# tree-sitter-lish

Two tree-sitter grammars for the [lish](https://github.com/mhogle25/lish-zig) language:

- **`lish`** — single top-level expression. Used for `.lish` files (configs, scripts, single-expression payloads).
- **`lishmacro`** — sequence of `|name params| body` macro definitions. Used for `.lishmacro` files.

The two grammars are deliberately decoupled. `lish` is the full expression grammar. `lishmacro` is a small wrapper grammar that recognizes only macro headers (`|name params|`), uses an **external scanner** to find the byte range of each macro's body, and relies on a **tree-sitter injection** to delegate body parsing to the `lish` grammar at the editor level.

That setup means improvements to lish — new operators, new syntax — automatically benefit lishmacro highlighting without any change to `tree-sitter-lishmacro`. It also mirrors how `tree-sitter-folio` is designed to embed lish inside `{...}` regions.

## Layout

```
tree-sitter-lish/
├── tree-sitter.json          # grammars array — declares both grammars
├── package.json              # npm scripts: generate, test
├── common/
│   ├── constants.js          # character constants mirrored from lish-zig/src/token.zig
│   ├── constants.h           # C mirror used by external scanners
│   └── define-grammar.js     # the lish expression grammar (used only by `lish/`)
├── lish/
│   ├── grammar.js            # 1-line shim → define-grammar()
│   ├── queries/highlights.scm
│   └── test/corpus/*.txt
├── lishmacro/
│   ├── grammar.js            # minimal wrapper: macro header + opaque body token
│   ├── src/scanner.c         # external scanner: finds body boundary, skips strings
│   ├── queries/
│   │   ├── highlights.scm    # highlights only the header shell
│   │   └── injections.scm    # delegates `macro_body` content to the `lish` grammar
│   └── test/corpus/*.txt
└── test/
    └── constants-sync.test.js  # enforces token.zig ↔ constants.js ↔ constants.h
```

## Build

```sh
pnpm install              # gets the tree-sitter CLI as a devDependency
pnpm generate             # produces lish/src/parser.c and lishmacro/src/parser.c
pnpm test                 # runs both grammars' corpus tests + the constants sync test
```

`npm` and `yarn` work equivalently; `pnpm` is what the repo was developed against.

## Relation to lish-lsp

[`lish-lsp`](https://github.com/mhogle25/lish-lsp) provides editor support for open files by speaking LSP and running the actual lish parser. It produces semantic tokens that drive syntax highlighting in LSP-aware editors.

`tree-sitter-lish` complements that for:

- **GitHub source code rendering** (linguist looks for `tree-sitter-LANG` grammars)
- **Editors that prefer tree-sitter over LSP** for highlighting (Helix, Zed, recent Neovim)
- **Closed / non-workspace files** that the LSP isn't managing
- **Initial paint before LSP attaches**

The two highlighters are kept aligned by sharing the lish-zig source-of-truth (see "Cross-language sync" below) and by using matching capture names — `tree-sitter-lish` emits the same tree-sitter standard captures (`@comment`, `@string`, `@number`, `@variable`, `@parameter`, `@operator`, `@function.call`, `@function.macro`) that map cleanly to the LSP token types lish-lsp produces.

## Cross-language sync

The character constants (`$`, `:`, `(`, `[`, `|`, `~`, ...) live in three files, one per consumer:

1. `lish-zig/src/token.zig` — Zig source of truth (used by the lish parser, lexer, highlighter, REPL).
2. `tree-sitter-lish/common/constants.js` — JS mirror (used by `define-grammar.js` and `lishmacro/grammar.js`).
3. `tree-sitter-lish/common/constants.h` — C mirror (used by `lishmacro/src/scanner.c` and any future external scanners).

`tree-sitter-lish/test/constants-sync.test.js` text-parses all three and asserts they agree. If you change one and forget the others, CI fails until they're aligned. Each file has a header comment naming the contract.

## Editor integration

### Neovim (via nvim-treesitter)

`tree-sitter-lish` ships two parsers from one repo. Register each with its `location` set to the appropriate subdirectory.

In `~/.config/nvim/init.lua` (or wherever you configure nvim-treesitter):

```lua
local parser_config = require('nvim-treesitter.parsers').get_parser_configs()

parser_config.lish = {
  install_info = {
    url = 'https://github.com/mhogle25/tree-sitter-lish',
    files = { 'src/parser.c' },
    location = 'lish',
    branch = 'main',
  },
  filetype = 'lish',
}

parser_config.lishmacro = {
  install_info = {
    url = 'https://github.com/mhogle25/tree-sitter-lish',
    files = { 'src/parser.c' },
    location = 'lishmacro',
    branch = 'main',
  },
  filetype = 'lishmacro',
}

vim.filetype.add({
  extension = {
    lish      = 'lish',
    lishmacro = 'lishmacro',
  },
})
```

Then `:TSInstall lish lishmacro`.

### Helix

In `~/.config/helix/languages.toml`:

```toml
[[language]]
name = "lish"
scope = "source.lish"
file-types = ["lish"]
roots = []
indent = { tab-width = 2, unit = "  " }
language-servers = ["lish-lsp"]

[[grammar]]
name = "lish"
source = { git = "https://github.com/mhogle25/tree-sitter-lish", rev = "main", subpath = "lish" }

[[language]]
name = "lishmacro"
scope = "source.lishmacro"
file-types = ["lishmacro"]
roots = []
indent = { tab-width = 2, unit = "  " }
language-servers = ["lish-lsp"]

[[grammar]]
name = "lishmacro"
source = { git = "https://github.com/mhogle25/tree-sitter-lish", rev = "main", subpath = "lishmacro" }

[language-server.lish-lsp]
command = "lish-lsp"
```

Then `hx --grammar fetch && hx --grammar build`.

### VS Code

VS Code's tree-sitter integration is provided by extensions, not the editor core. The [lish-lsp VS Code extension](https://github.com/mhogle25/lish-lsp/tree/main/editors/vscode) already provides semantic tokens via LSP — install that for highlighting. The tree-sitter grammars here are useful for GitHub rendering and other tree-sitter-native consumers, not for VS Code directly.

## Status

Early. The grammars handle every form in `lish-zig/src/stdlib.lishmacro` without errors and 23 corpus tests pass. As lish grows, this repo grows with it.
