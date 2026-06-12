// ---------------------------------------------------------------------------
// Cross-language sync contract.
//
// This file mirrors character constants from the upstream lish source:
//
//   lish-zig/src/token.zig                 (Zig source of truth)
//   tree-sitter-lish/common/constants.h    (C mirror used by external scanners)
//
// If you change a value here, also update the Zig source and the C header. The
// sync is enforced by test/constants-sync.test.js, which text-parses all three
// files and compares.
// ---------------------------------------------------------------------------

module.exports = {
    EXPRESSION_SINGLE: '$',
    SCOPE_THUNK:       ':',
    EXPRESSION_OPEN:   '(',
    EXPRESSION_CLOSE:  ')',
    LIST_OPEN:         '[',
    LIST_CLOSE:        ']',
    BLOCK_OPEN:        '{',
    BLOCK_CLOSE:       '}',
    QUOTE_DOUBLE:      '"',
    QUOTE_SINGLE:      "'",
    MACRO_BRACKET:     '|',
    DEFERRED:          '~',
    DECIMAL_POINT:     '.',
    NEGATIVE_SIGN:     '-',
    COMMENT:           '#',
    BACKSLASH:         '\\',
};
