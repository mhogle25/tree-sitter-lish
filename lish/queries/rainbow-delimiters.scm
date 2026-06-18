; Rainbow-delimiters query for the `lish` grammar: color matched brackets by
; nesting depth. `.lishmacro` bodies reuse this via the lish injection.

(sub_expression
  "(" @delimiter
  ")" @delimiter) @container

(list
  "[" @delimiter
  "]" @delimiter) @container

(block
  "{" @delimiter
  "}" @delimiter) @container
