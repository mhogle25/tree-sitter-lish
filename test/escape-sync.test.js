// ---------------------------------------------------------------------------
// Enforces sync between:
//
//   ../lish-zig/src/token.zig          (`escSymToChar` switch)
//   ../common/define-grammar.js         (`escape_sequence` regex char class)
//
// Both define WHICH single-character escape sequences are recognized inside
// lish string literals. They live in different languages and could silently
// drift. This test text-parses both forms, builds the set of characters that
// each accepts as a `\X` escape, and asserts the sets are equal.
//
// Hex (`\xAB`) and Unicode (`\u{...}`) escapes are tree-sitter-side extensions
// — lish-zig's lexer treats them as `\X` (2-byte escape, second char ignored).
// Both still consume 2 bytes so boundary detection agrees; only the highlighter
// would tag them differently. We deliberately do NOT include them in the sync.
// ---------------------------------------------------------------------------

const fs = require('fs');
const path = require('path');

const TOKEN_ZIG = path.join(__dirname, '..', '..', 'lish-zig', 'src', 'token.zig');
const GRAMMAR_JS = path.join(__dirname, '..', 'common', 'define-grammar.js');
const CONSTANTS_JS = path.join(__dirname, '..', 'common', 'constants.js');

// Named character constants used as keys in the Zig switch (e.g. `BACKSLASH`).
// They resolve via the JS constants mirror (already verified by constants-sync).
const constants = require(CONSTANTS_JS);

function parseZigEscapes(source) {
    // Walk `escSymToChar` switch arms. Each arm matches:
    //   'X' => ...,                  (literal char)
    //   NAMED_CONST => ...,          (resolves via constants.js)
    const fnStart = source.indexOf('pub fn escSymToChar');
    if (fnStart < 0) throw new Error('escSymToChar not found in token.zig');
    const fnEnd = source.indexOf('\n}', fnStart);
    const body = source.slice(fnStart, fnEnd);

    const out = new Set();
    const charPattern = /^\s*'(\\.|[^'])'\s*=>/gm;
    const namedPattern = /^\s*([A-Z_]+)\s*=>/gm;

    for (const [, key] of body.matchAll(charPattern)) {
        out.add(decodeCharLiteral(key));
    }
    for (const [, name] of body.matchAll(namedPattern)) {
        if (!(name in constants)) continue; // skip helpers / non-mirrored names
        out.add(constants[name]);
    }
    return out;
}

function decodeCharLiteral(raw) {
    if (raw.length === 1) return raw;
    switch (raw) {
        case "\\'":  return "'";
        case '\\"':  return '"';
        case '\\\\': return '\\';
        case '\\n':  return '\n';
        case '\\r':  return '\r';
        case '\\t':  return '\t';
        case '\\0':  return '\0';
        default:
            throw new Error(`unhandled Zig char literal escape: ${raw}`);
    }
}

function parseJsEscapeRegex(source) {
    // Locate the escape_sequence rule and extract its first character class.
    // Format: escape_sequence: $ => token.immediate(/\\(["'\\nrtab0aefv]|x...|u...|/)
    const ruleStart = source.indexOf('escape_sequence:');
    if (ruleStart < 0) throw new Error('escape_sequence rule not found in define-grammar.js');
    const slice = source.slice(ruleStart, ruleStart + 400);
    // The regex starts with /\\\\\( and the first [ ... ] is the single-char class.
    const m = slice.match(/\/\\\\\(\[([^\]]+)\]/);
    if (!m) throw new Error('could not extract char class from escape_sequence regex');

    const out = new Set();
    let i = 0;
    const cls = m[1];
    while (i < cls.length) {
        const c = cls[i];
        if (c === '\\' && i + 1 < cls.length) {
            // `\\` in the regex source is a literal backslash.
            out.add('\\');
            i += 2;
            continue;
        }
        out.add(c);
        i += 1;
    }
    return out;
}

const zigSource = fs.readFileSync(TOKEN_ZIG, 'utf8');
const jsSource = fs.readFileSync(GRAMMAR_JS, 'utf8');

const zigEscapes = parseZigEscapes(zigSource);
const jsEscapes = parseJsEscapeRegex(jsSource);

const onlyInZig = [...zigEscapes].filter(c => !jsEscapes.has(c));
const onlyInJs = [...jsEscapes].filter(c => !zigEscapes.has(c));

if (onlyInZig.length > 0 || onlyInJs.length > 0) {
    console.error('escape-sync FAILED:');
    if (onlyInZig.length > 0) {
        console.error('  in token.zig but not in escape_sequence regex:');
        for (const c of onlyInZig) console.error(`    ${JSON.stringify(c)}`);
    }
    if (onlyInJs.length > 0) {
        console.error('  in escape_sequence regex but not in token.zig:');
        for (const c of onlyInJs) console.error(`    ${JSON.stringify(c)}`);
    }
    process.exit(1);
}

console.log(`escape-sync OK (${zigEscapes.size} escape characters verified)`);
