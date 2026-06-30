; Highlight queries for the `lishmacro` grammar.
;
; The grammar is intentionally minimal — it only highlights the macro header
; shell (`name params | ... ;`): the `|` header/body separator and the `;`
; terminator. Body content is handled by the lish injection (see
; queries/injections.scm), so highlighting inside macro bodies comes from the
; lish grammar's own highlights.scm and matches everywhere lish appears
; (standalone files + embedded macro bodies).

; Comments
(comment) @comment

; Macro delimiters: the `|` header/body separator and the `;` body terminator.
(macro_definition "|" @keyword.function)
(macro_definition ";" @keyword.function)
(macro_definition name:  (identifier) @function.macro)
(macro_definition param: (identifier) @parameter)

; Deferred macro parameters (~name)
(deferred_param (identifier) @parameter)
"~" @operator
