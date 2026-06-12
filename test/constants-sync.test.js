// ---------------------------------------------------------------------------
// Enforces the cross-language sync contract between:
//
//   ../lish-zig/src/token.zig     (Zig source of truth)
//   ../common/constants.js         (JS mirror used by the grammar)
//   ../common/constants.h          (C mirror used by external scanners)
//
// On failure, align all three files and re-run. Do not "fix" by editing only
// one side — the divergence is the bug.
// ---------------------------------------------------------------------------

const fs = require('fs');
const path = require('path');

const TOKEN_ZIG    = path.join(__dirname, '..', '..', 'lish-zig', 'src', 'token.zig');
const CONSTANTS_JS = path.join(__dirname, '..', 'common', 'constants.js');
const CONSTANTS_H  = path.join(__dirname, '..', 'common', 'constants.h');

// The subset of token.zig constants we mirror on the JS side. Adding a new
// entry here without also mirroring it in constants.js (or vice versa) is a
// sync error.
const TRACKED_NAMES = [
    'EXPRESSION_SINGLE',
    'SCOPE_THUNK',
    'EXPRESSION_OPEN',
    'EXPRESSION_CLOSE',
    'LIST_OPEN',
    'LIST_CLOSE',
    'BLOCK_OPEN',
    'BLOCK_CLOSE',
    'QUOTE_DOUBLE',
    'QUOTE_SINGLE',
    'MACRO_BRACKET',
    'DEFERRED',
    'DECIMAL_POINT',
    'NEGATIVE_SIGN',
    'COMMENT',
    'BACKSLASH',
];

function parseZigConstants(source) {
    const out = {};
    // `pub const NAME = 'X';` — `X` may be a single char or an escape like `\\` or `\n`.
    const pattern = /^pub const ([A-Z_]+)\s*=\s*'(\\.|[^'])'\s*;/gm;
    for (const [, name, raw] of source.matchAll(pattern)) {
        out[name] = decodeCChar(raw);
    }
    return out;
}

function parseCConstants(source) {
    const out = {};
    // `#define LISH_NAME 'X'` — `X` may be a single char or an escape.
    // Strip the LISH_ prefix on the way out so names match the Zig / JS keys.
    const pattern = /^#define\s+LISH_([A-Z_]+)\s+'(\\.|[^'])'/gm;
    for (const [, name, raw] of source.matchAll(pattern)) {
        out[name] = decodeCChar(raw);
    }
    return out;
}

// Zig and C use the same character-literal escape conventions for the few
// escapes we hit, so one decoder serves both.
function decodeCChar(raw) {
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
            throw new Error(`unhandled char escape: ${raw}`);
    }
}

function fail(message) {
    console.error('constants-sync FAILED: ' + message);
    process.exit(1);
}

const zigConstants = parseZigConstants(fs.readFileSync(TOKEN_ZIG, 'utf8'));
const cConstants   = parseCConstants(fs.readFileSync(CONSTANTS_H, 'utf8'));
const jsConstants  = require(CONSTANTS_JS);

const sources = {
    zig: zigConstants,
    js:  jsConstants,
    c:   cConstants,
};

const errors = [];
for (const name of TRACKED_NAMES) {
    for (const [label, map] of Object.entries(sources)) {
        if (!(name in map)) {
            errors.push(`missing in ${label}: ${name}`);
        }
    }
    if (errors.length) continue;
    const values = Object.fromEntries(
        Object.entries(sources).map(([label, map]) => [label, map[name]]),
    );
    const unique = new Set(Object.values(values));
    if (unique.size > 1) {
        errors.push(`${name}: ${JSON.stringify(values)}`);
    }
}

// Catch extra entries on either mirror that aren't tracked — likely means
// someone added a constant without registering it.
for (const [label, map] of Object.entries(sources)) {
    if (label === 'zig') continue; // token.zig has many constants we don't mirror
    for (const name of Object.keys(map)) {
        if (!TRACKED_NAMES.includes(name)) {
            errors.push(`untracked constant in ${label}: ${name} — add it to TRACKED_NAMES`);
        }
    }
}

if (errors.length > 0) {
    fail('\n  ' + errors.join('\n  '));
}

console.log(`constants-sync OK (${TRACKED_NAMES.length} constants verified across 3 files)`);
