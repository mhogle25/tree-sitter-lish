/**
 * tree-sitter grammar for `.lishmacro` files.
 *
 * Intentionally small: a `.lishmacro` file is a sequence of `|name params| body`
 * declarations. The body is a lish expression — and rather than re-stating the
 * entire lish grammar here, we treat the body as an opaque `macro_body` token
 * recognized by the external scanner in `src/scanner.c`. A `queries/injections.scm`
 * tells the editor to re-parse `macro_body` content with the `lish` grammar.
 *
 * The scanner's job: starting after the closing `|` of a macro header, scan
 * forward until the next `|` at the top level (i.e. not inside a string).
 * This mirrors the boundary logic in `lish-zig/src/macro_parser.zig`.
 */

const C = require('../common/constants');

module.exports = grammar({
    name: 'lishmacro',

    extras: $ => [
        /\s+/,
        $.comment,
    ],

    word: $ => $.identifier,

    externals: $ => [
        $.macro_body,
    ],

    rules: {
        source_file: $ => repeat1($.macro_definition),

        macro_definition: $ => seq(
            C.MACRO_BRACKET,
            field('name', $.identifier),
            repeat(field('param', $._macro_param)),
            C.MACRO_BRACKET,
            field('body', $.macro_body),
        ),

        _macro_param: $ => choice(
            $.deferred_param,
            $.identifier,
        ),

        // ~name — deferred parameter marker.
        deferred_param: $ => seq(C.DEFERRED, $.identifier),

        // Identifier: any run of non-structural characters, excluding `#`
        // (reserved for comment opener).
        identifier: $ => token(prec(1, /[^\s()\[\]{}|"':$~#]+/)),

        // Same comment rule as lish — see the explanation in common/define-grammar.js.
        comment: $ => token(/##([^\n#]|#[^\n#])*(##)?/),
    },
});
