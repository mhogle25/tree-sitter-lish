/**
 * Shared grammar definition for the `lish` expression language.
 *
 * The `lishmacro` dialect intentionally does NOT extend this — it's a separate,
 * minimal grammar that uses an external scanner to find macro bodies and a
 * tree-sitter injection to delegate body parsing to the `lish` grammar at the
 * editor level. See lishmacro/grammar.js + lishmacro/src/scanner.c.
 *
 * Character literals come from `common/constants.js`, which is generated from
 * lish's `token.zig` (via `tools/gen.zig`) and vendored in by `scripts/sync.js`.
 * Run `pnpm sync` to refresh it; do not edit it by hand.
 *
 * ---
 * Cross-language sync — token-level regexes.
 *
 * The `number`, `identifier`, and `comment` regexes duplicate the lexical rules
 * of lish's `src/lexer.zig`. They are NOT generated; if you change them here
 * you must also change the Zig lexer (or vice versa), and your CI will need to
 * catch the divergence.
 *
 * `escape_sequence`'s single-char class is the exception: it is built from
 * `common/escapes.js`, generated from `token.zig`'s `escSymToChar` and vendored
 * by `scripts/sync.js`, so it cannot drift. The `\xAB` / `\u{...}` forms are
 * tree-sitter-side extensions and stay hand-written here.
 *
 * The contracts holding the remaining hand-mirrored regexes in sync are:
 *
 *   - `lish/src/scanner_corpus/` — boundary-finding cases run by every
 *     embedder. Catches drift in string + comment + escape handling.
 *   - `tree-sitter-lish/test/scanner-corpus.test.js` — runs the corpus
 *     against this grammar's external scanner.
 *
 * NOTE: lish has a shared boundary finder (`boundary.zig`), but this
 * grammar's external scanner can't call it (streaming, ships as C/WASM, can't
 * link Zig). So `comment` and the `number` / `identifier` regexes stay
 * hand-mirrored, with the corpus catching string/comment/escape drift. This is
 * by design; see lish roadmap, "Lish embedders".
 */

const C = require('./constants');
const E = require('./escapes');

// Regex character-class body from raw chars, escaping the few that are special
// inside a `[...]` class.
function charClass(chars) {
    const body = chars.map(c => /[\\\]^-]/.test(c) ? '\\' + c : c).join('');
    return '[' + body + ']';
}

module.exports = function defineLishGrammar() {
    return grammar({
        name: 'lish',

        extras: $ => [
            /\s+/,
            $.comment,
        ],

        word: $ => $.identifier,

        rules: {
            source_file: $ => optional(choice($.expression, $.sub_expression)),

            // op arg arg arg ...   — the unparenthesized form. Used at top
            // level and as the contents of a sub_expression.
            expression: $ => prec.right(seq(
                field('operation', $.identifier),
                repeat(field('argument', $._term)),
            )),

            // A "term" is anything that can appear in an argument slot.
            _term: $ => choice(
                $.sub_expression,
                $.list,
                $.block,
                $.single_term_call,
                $.scope_ref,
                $.number,
                $.string,
                $.identifier,
            ),

            sub_expression: $ => seq(C.EXPRESSION_OPEN, $.expression, C.EXPRESSION_CLOSE),

            list: $ => seq(C.LIST_OPEN, repeat($._term), C.LIST_CLOSE),

            block: $ => seq(C.BLOCK_OPEN, repeat($._term), C.BLOCK_CLOSE),

            // $name — single-term expression (zero-argument call on `name`).
            single_term_call: $ => seq(C.EXPRESSION_SINGLE, $.identifier),

            // :name — scope thunk; looks `name` up in the current scope.
            scope_ref: $ => seq(C.SCOPE_THUNK, $.identifier),

            // Numbers: integer or float, with optional leading minus glued to
            // the digits. `- 1` is two tokens (op then number); `-1` is one
            // number.
            number: $ => token(prec(2, /-?\d+(\.\d+)?/)),

            // String literals come in two flavours: double-quoted and
            // single-quoted. Escape sequences are split out so highlight
            // queries can color them.
            string: $ => choice(
                seq(
                    C.QUOTE_DOUBLE,
                    repeat(choice(
                        alias($._string_content_double, $.string_content),
                        $.escape_sequence,
                    )),
                    C.QUOTE_DOUBLE,
                ),
                seq(
                    C.QUOTE_SINGLE,
                    repeat(choice(
                        alias($._string_content_single, $.string_content),
                        $.escape_sequence,
                    )),
                    C.QUOTE_SINGLE,
                ),
            ),

            _string_content_double: $ => token.immediate(prec(1, /[^"\\]+/)),
            _string_content_single: $ => token.immediate(prec(1, /[^'\\]+/)),

            // Single-char class comes from the generated escapes.js (mirrors
            // token.zig's escSymToChar). The hex / Unicode forms are
            // tree-sitter-side extensions and stay hand-written.
            escape_sequence: $ => token.immediate(
                new RegExp('\\\\(?:' + charClass(E.SINGLE_CHAR_ESCAPES) + '|x[0-9a-fA-F]{2}|u\\{[0-9a-fA-F]+\\})'),
            ),

            // Identifier: any run of non-structural characters. Lish ops like
            // `+`, `<=`, `??`, `is`, and the bitwise `|`/`~`/`&`/`<<` etc. all
            // qualify. In expression position `|` and `~` are ordinary operator
            // chars (they are macro-header-only structure; see the lishmacro
            // grammar). The base walls excluded here mirror token.zig's
            // `isReservedChar`: `( ) [ ] { } : $ " ' ;`. `#` is excluded so `##`
            // can only start a comment, never an identifier.
            identifier: $ => token(prec(1, /[^\s()\[\]{}"':$;#]+/)),

            // Comment forms. Two shapes in lish:
            //   inline: `## stuff ##`  ends at the next `##` on the line
            //   to-EOL: `## stuff`     ends at newline / EOF
            // One regex handles both: body chars are non-newline AND not part
            // of `##` (encoded as "non-#-non-newline" or "# followed by non-#-
            // non-newline"), so the body naturally stops at any `##`. A trailing
            // `##` is optionally consumed. Since tree-sitter takes longest
            // match, the inline form wins whenever a closing `##` exists.
            comment: $ => token(/##([^\n#]|#[^\n#])*(##)?/),
        },
    });
};
