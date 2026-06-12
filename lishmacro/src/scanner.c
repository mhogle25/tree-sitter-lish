// External scanner for the lishmacro grammar.
//
// Recognizes one external token: `macro_body`. Starting after the closing `|`
// of a macro header, advances through arbitrary content until the next
// top-level `|` (i.e. not inside a string or comment) or EOF.
//
// Mirrors the boundary logic in lish-zig/src/macro_parser.zig's
// `parseFromLexer(..., stop_at: &.{.macro_bracket})` and the comment/string
// handling in lish-zig/src/lexer.zig. All the lish-specific lexical knowledge
// (what's a string, what's a comment, where escape sequences are) lives in
// common/scanner_helpers.h — this file just composes those primitives with
// the lishmacro-specific terminator logic.
//
// TODO: when we add a shared `lish_find_expression_boundary` C ABI to lish-zig
// (see roadmap "lish embedders" section), this scanner shrinks to one call.

#include "tree_sitter/parser.h"
#include "../../common/constants.h"
#include "../../common/scanner_helpers.h"

enum TokenType {
    MACRO_BODY,
};

void *tree_sitter_lishmacro_external_scanner_create(void) {
    return NULL;
}

void tree_sitter_lishmacro_external_scanner_destroy(void *payload) {
    (void)payload;
}

unsigned tree_sitter_lishmacro_external_scanner_serialize(void *payload, char *buffer) {
    (void)payload;
    (void)buffer;
    return 0;
}

void tree_sitter_lishmacro_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    (void)payload;
    (void)buffer;
    (void)length;
}

bool tree_sitter_lishmacro_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    (void)payload;
    if (!valid_symbols[MACRO_BODY]) return false;

    // Skip leading whitespace — the body's actual content starts at the first
    // non-whitespace char after the header's closing `|`.
    while (!lexer->eof(lexer) && lish_is_inline_space(lexer->lookahead)) {
        lexer->advance(lexer, true);
    }

    if (lexer->eof(lexer) || lexer->lookahead == LISH_MACRO_BRACKET) {
        return false;
    }

    bool consumed_any = false;
    while (!lexer->eof(lexer) && lexer->lookahead != LISH_MACRO_BRACKET) {
        int32_t c = lexer->lookahead;

        if (c == LISH_QUOTE_DOUBLE || c == LISH_QUOTE_SINGLE) {
            lexer->advance(lexer, false);
            lish_skip_string(lexer, c);
            lexer->mark_end(lexer);
            consumed_any = true;
            continue;
        }

        // Lish comments are `##` openers. If we see `#` not followed by `#`,
        // it's a stray char — treat as content. (Lish itself rejects `#` alone
        // at the lexer level, but the boundary-finder doesn't care.)
        if (c == LISH_COMMENT) {
            lexer->advance(lexer, false);
            if (!lexer->eof(lexer) && lexer->lookahead == LISH_COMMENT) {
                lexer->advance(lexer, false);
                lish_skip_comment(lexer);
                // Don't mark_end inside a comment — the comment isn't body content.
                consumed_any = true;
                continue;
            }
            lexer->mark_end(lexer);
            consumed_any = true;
            continue;
        }

        lexer->advance(lexer, false);
        // Snapshot the token's end only at non-whitespace positions so trailing
        // whitespace before the next `|` (or EOF) doesn't get included.
        if (!lish_is_inline_space(c)) {
            lexer->mark_end(lexer);
        }
        consumed_any = true;
    }

    if (!consumed_any) return false;
    lexer->result_symbol = MACRO_BODY;
    return true;
}
