// ---------------------------------------------------------------------------
// Cross-language sync contract.
//
// This header mirrors character constants from the upstream lish source:
//
//   lish-zig/src/token.zig
//
// Used by tree-sitter external scanners (e.g. tree-sitter-lishmacro/src/scanner.c)
// to find boundaries in source while skipping over string content. If you change
// a value here, also update the Zig source and constants.js. The sync is enforced
// by test/constants-sync.test.js, which text-parses all three files and compares.
// ---------------------------------------------------------------------------

#ifndef LISH_TREE_SITTER_CONSTANTS_H
#define LISH_TREE_SITTER_CONSTANTS_H

#define LISH_EXPRESSION_SINGLE '$'
#define LISH_SCOPE_THUNK       ':'
#define LISH_EXPRESSION_OPEN   '('
#define LISH_EXPRESSION_CLOSE  ')'
#define LISH_LIST_OPEN         '['
#define LISH_LIST_CLOSE        ']'
#define LISH_BLOCK_OPEN        '{'
#define LISH_BLOCK_CLOSE       '}'
#define LISH_QUOTE_DOUBLE      '"'
#define LISH_QUOTE_SINGLE      '\''
#define LISH_MACRO_BRACKET     '|'
#define LISH_DEFERRED          '~'
#define LISH_DECIMAL_POINT     '.'
#define LISH_NEGATIVE_SIGN     '-'
#define LISH_COMMENT           '#'
#define LISH_BACKSLASH         '\\'

#endif
