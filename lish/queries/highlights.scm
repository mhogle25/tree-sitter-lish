; Highlight queries for the `lish` grammar.
;
; Capture names follow tree-sitter's standard taxonomy so editors can theme
; them without language-specific mapping. They match the LSP's semantic-token
; output (see lish-lsp/src/semantic_tokens.zig) so the two highlighters agree
; on the same source.
;
; Queries are deliberately non-overlapping — every identifier is captured by
; exactly one pattern based on its syntactic role. This makes the highlight
; behavior identical across editors regardless of how each one resolves
; multi-capture conflicts.

; Literals
(comment)         @comment
(string)          @string
(escape_sequence) @string.escape
(number)          @number

; Identifier in an expression's operation slot — the head of `op arg arg`.
(expression operation: (identifier) @function.call)

; Identifier in an expression's argument slot — covers top-level and
; sub-expression args.
(expression argument: (identifier) @variable)

; Identifier as a direct child of list / block sugar — those don't use
; field labels, just positional children.
(list  (identifier) @variable)
(block (identifier) @variable)

; Identifier inside a sigil-prefixed form. The sigil character itself reads
; as an operator; the identifier takes the role-specific capture.
(scope_ref        (identifier) @parameter)
(single_term_call (identifier) @function)
(deferred_param   (identifier) @parameter)

; Sigil characters.
":" @operator
"$" @operator
"~" @operator

; Bracket punctuation.
"(" @punctuation.bracket
")" @punctuation.bracket
"[" @punctuation.bracket
"]" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket
