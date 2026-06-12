; Injection queries for lishmacro.
;
; Tells the editor to re-parse `macro_body` regions with the `lish` grammar,
; so macro bodies get the same highlighting as standalone .lish files.

((macro_body) @injection.content
 (#set! injection.language "lish"))
