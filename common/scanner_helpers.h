// ---------------------------------------------------------------------------
// Shared scanner primitives for tree-sitter grammars that wrap lish syntax.
//
// Mirrors the boundary-skipping behavior of lish-zig's lexer so that
// wrapper-grammar scanners (lishmacro, future folio) find the same byte
// boundaries the lish parser would.
//
// Any function in this header that mirrors lish lexer logic is part of the
// boundary-finding contract documented at:
//
//   lish-zig/src/scanner_corpus/
//
// If lish gains a new lexical form, the corpus grows, every embedder's CI
// fails until they learn the new form.
//
// NOTE: lish-zig has a shared boundary finder (`boundary.zig`), and Zig
// embedders call it directly. A tree-sitter scanner cannot: it reads input one
// codepoint at a time (no buffer to pass) and ships as portable C/WASM (can't
// link Zig). So these streaming helpers stay, held to the same corpus. This is
// by design, not a gap to close. See lish-zig roadmap, "lish embedders".
// ---------------------------------------------------------------------------

#ifndef LISH_TREE_SITTER_SCANNER_HELPERS_H
#define LISH_TREE_SITTER_SCANNER_HELPERS_H

#include "tree_sitter/parser.h"
#include "constants.h"

static inline bool lish_is_horizontal_space(int32_t c) {
    return c == ' ' || c == '\t';
}

static inline bool lish_is_newline(int32_t c) {
    return c == '\n' || c == '\r';
}

static inline bool lish_is_inline_space(int32_t c) {
    return lish_is_horizontal_space(c) || lish_is_newline(c);
}

// Skip the contents of a string literal whose opening quote has just been
// consumed. Handles backslash escapes the same way lish's lexer does — `\X`
// for any single char X is two bytes (we don't care about the escape table
// itself, only the byte-count semantics for boundary finding).
//
// Returns when the matching close quote is consumed, or when EOF is reached
// (unterminated string).
static inline void lish_skip_string(TSLexer *lexer, int32_t quote) {
    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;
        if (c == LISH_BACKSLASH) {
            lexer->advance(lexer, false);
            if (lexer->eof(lexer)) return;
            lexer->advance(lexer, false);
            continue;
        }
        if (c == quote) {
            lexer->advance(lexer, false);
            return;
        }
        lexer->advance(lexer, false);
    }
}

// Skip a comment whose opening `##` has just been consumed. Comments end at:
//   - a matching `##`  (inline form)
//   - a newline        (to-EOL form)
//   - EOF
// Mirrors lish-zig/src/lexer.zig's comment handling.
static inline void lish_skip_comment(TSLexer *lexer) {
    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;
        if (lish_is_newline(c)) return;
        if (c == LISH_COMMENT) {
            lexer->advance(lexer, false);
            if (lexer->eof(lexer)) return;
            if (lexer->lookahead == LISH_COMMENT) {
                lexer->advance(lexer, false);
                return;
            }
            continue;
        }
        lexer->advance(lexer, false);
    }
}

#endif
