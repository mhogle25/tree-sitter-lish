// ---------------------------------------------------------------------------
// Runs the shared scanner-boundary corpus against the tree-sitter lishmacro
// external scanner.
//
// The corpus lives in ../lish-zig/src/scanner_corpus/ — same one consumed by
// lish-zig's lexer test and folio's scanBraceContent test. See its README for
// the file format and the contract every embedder is held to.
//
// For each `|` case, we shell out to `tree-sitter parse` against the lishmacro
// grammar, extract the macro_body node's end position from the S-expression
// output, convert that line/col to a byte offset, and assert it equals the
// declared boundary. The `}` cases are not exercised here — they belong to
// the future tree-sitter-folio scanner.
// ---------------------------------------------------------------------------

const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const CORPUS_DIR = path.join(__dirname, '..', '..', 'lish-zig', 'src', 'scanner_corpus');
const TREE_SITTER = path.join(__dirname, '..', 'node_modules', '.bin', 'tree-sitter');
const LISHMACRO_DIR = path.join(__dirname, '..', 'lishmacro');

function parseCase(text) {
    const sepIdx = text.indexOf('---\n');
    if (sepIdx < 0) throw new Error('case missing --- separator');
    const header = text.slice(0, sepIdx);
    let source = text.slice(sepIdx + 4);
    if (source.endsWith('\n')) source = source.slice(0, -1);

    const meta = {};
    for (const line of header.split('\n')) {
        const m = line.match(/^([a-z_]+):\s*(.+)$/);
        if (m) meta[m[1]] = m[2];
    }
    return {
        terminator: meta.terminator,
        boundary: parseInt(meta.boundary, 10),
        source,
    };
}

// Convert a [line, column] position (0-indexed, tree-sitter style) into a byte
// offset within `source`. For ASCII sources this is a straight count.
function lineColToByte(source, line, col) {
    if (line === 0) return col;
    let pos = 0;
    for (let i = 0; i < line; i++) {
        pos = source.indexOf('\n', pos);
        if (pos < 0) throw new Error(`source has only ${i + 1} lines, asked for line ${line}`);
        pos += 1;
    }
    return pos + col;
}

// Parse the case source with tree-sitter-lishmacro by shelling out. We write
// to a temp file rather than passing on stdin because `tree-sitter parse
// /dev/stdin` reads inconsistently from Node's `spawnSync` input pipe.
function parseWithLishmacro(source) {
    const tmp = path.join('/tmp', `tree-sitter-lish-${process.pid}-${Date.now()}.lishmacro`);
    fs.writeFileSync(tmp, source);
    try {
        const result = spawnSync(TREE_SITTER, ['parse', tmp], {
            cwd: LISHMACRO_DIR,
            encoding: 'utf8',
        });
        if (result.status !== 0 && result.status !== 1) {
            // status 0 = clean parse, status 1 = parse with errors (still produces a tree).
            throw new Error(`tree-sitter parse exited ${result.status}: ${result.stderr}`);
        }
        return result.stdout;
    } finally {
        fs.unlinkSync(tmp);
    }
}

// Find the FIRST macro_body node's end [line, col] in tree-sitter's
// S-expression output. Lines look like:
//   body: (macro_body [0, 6] - [0, 41])
function findMacroBodyEnd(parseOutput) {
    const m = parseOutput.match(/macro_body\s*\[\d+,\s*\d+\]\s*-\s*\[(\d+),\s*(\d+)\]/);
    if (!m) return null;
    return [parseInt(m[1], 10), parseInt(m[2], 10)];
}

function fail(message) {
    console.error('scanner-corpus FAILED:\n  ' + message);
    process.exit(1);
}

const files = fs.readdirSync(CORPUS_DIR).filter(f => f.endsWith('.case')).sort();
const errors = [];
let pipeCount = 0;

// Each case's source is RAW body content (no surrounding `|name|` header). To
// run it through tree-sitter-lishmacro we synthesize a wrapper:
//
//     |x|<source>|body
//
// The leading `|x|` makes the case's content the body of a first macro. The
// trailing `|body` completes a second macro definition using whatever follows
// the boundary `|` in the corpus source as its name; this keeps tree-sitter
// from producing a top-level ERROR node that swallows the partial tree.
//
// The first macro_body's end position in the synthesized parse, minus the
// prefix length, gives us the boundary within the original source.
const WRAPPER_PREFIX = '|x|';
const WRAPPER_SUFFIX = '|body';

for (const filename of files) {
    const text = fs.readFileSync(path.join(CORPUS_DIR, filename), 'utf8');
    const c = parseCase(text);
    if (c.terminator !== '|') continue;
    pipeCount += 1;

    const synth = WRAPPER_PREFIX + c.source + WRAPPER_SUFFIX;
    const output = parseWithLishmacro(synth);
    const end = findMacroBodyEnd(output);
    if (!end) {
        errors.push(
            `${filename}: no macro_body node in parse output\n    synth: ${JSON.stringify(synth)}`,
        );
        continue;
    }

    const synthOffset = lineColToByte(synth, end[0], end[1]);
    const actual = synthOffset - WRAPPER_PREFIX.length;
    if (actual !== c.boundary) {
        errors.push(
            `${filename}: expected boundary ${c.boundary}, scanner reports ${actual}\n` +
            `    source: ${JSON.stringify(c.source)}\n` +
            `    macro_body end position: [${end[0]}, ${end[1]}] (offset ${synthOffset} in synth)`,
        );
    }
}

if (errors.length > 0) fail('\n  ' + errors.join('\n  '));
if (pipeCount === 0) fail('no `|` cases found in corpus — did the path move?');

console.log(`scanner-corpus OK (${pipeCount} cases verified)`);
