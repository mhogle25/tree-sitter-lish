#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 32
#define LARGE_STATE_COUNT 10
#define SYMBOL_COUNT 30
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_LBRACK = 4,
  anon_sym_RBRACK = 5,
  anon_sym_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_DOLLAR = 8,
  anon_sym_COLON = 9,
  sym_number = 10,
  anon_sym_DQUOTE = 11,
  anon_sym_SQUOTE = 12,
  sym__string_content_double = 13,
  sym__string_content_single = 14,
  sym_escape_sequence = 15,
  sym_comment = 16,
  sym_source_file = 17,
  sym_expression = 18,
  sym__term = 19,
  sym_sub_expression = 20,
  sym_list = 21,
  sym_block = 22,
  sym_single_term_call = 23,
  sym_scope_ref = 24,
  sym_string = 25,
  aux_sym_expression_repeat1 = 26,
  aux_sym_list_repeat1 = 27,
  aux_sym_string_repeat1 = 28,
  aux_sym_string_repeat2 = 29,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_COLON] = ":",
  [sym_number] = "number",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym__string_content_double] = "string_content",
  [sym__string_content_single] = "string_content",
  [sym_escape_sequence] = "escape_sequence",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym_expression] = "expression",
  [sym__term] = "_term",
  [sym_sub_expression] = "sub_expression",
  [sym_list] = "list",
  [sym_block] = "block",
  [sym_single_term_call] = "single_term_call",
  [sym_scope_ref] = "scope_ref",
  [sym_string] = "string",
  [aux_sym_expression_repeat1] = "expression_repeat1",
  [aux_sym_list_repeat1] = "list_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_number] = sym_number,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym__string_content_double] = sym__string_content_double,
  [sym__string_content_single] = sym__string_content_double,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym_expression] = sym_expression,
  [sym__term] = sym__term,
  [sym_sub_expression] = sym_sub_expression,
  [sym_list] = sym_list,
  [sym_block] = sym_block,
  [sym_single_term_call] = sym_single_term_call,
  [sym_scope_ref] = sym_scope_ref,
  [sym_string] = sym_string,
  [aux_sym_expression_repeat1] = aux_sym_expression_repeat1,
  [aux_sym_list_repeat1] = aux_sym_list_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__string_content_double] = {
    .visible = true,
    .named = true,
  },
  [sym__string_content_single] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__term] = {
    .visible = false,
    .named = true,
  },
  [sym_sub_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_single_term_call] = {
    .visible = true,
    .named = true,
  },
  [sym_scope_ref] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_argument = 1,
  field_operation = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_operation] = "operation",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_operation, 0},
  [1] =
    {field_argument, 0},
  [2] =
    {field_argument, 1, .inherited = true},
    {field_operation, 0},
  [4] =
    {field_argument, 0, .inherited = true},
    {field_argument, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
};

static TSCharacterRange sym_identifier_character_set_1[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'!', '!'}, {'%', '&'}, {'*', '9'}, {'<', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 24,
        '#', 2,
        '$', 20,
        '\'', 25,
        '(', 14,
        ')', 15,
        '-', 38,
        ':', 21,
        '[', 16,
        '\\', 37,
        ']', 17,
        '{', 18,
        '}', 19,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (lookahead != 0 &&
          (lookahead < '0' || ';' < lookahead)) ADVANCE(42);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(24);
      if (lookahead == '#') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(44);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(44);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == '\'') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0) ADVANCE(35);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        'u', 6,
        'x', 10,
        '"', 36,
        '\'', 36,
        '0', 36,
        '\\', 36,
        'a', 36,
        'b', 36,
        'e', 36,
        'f', 36,
        'n', 36,
        'r', 36,
        't', 36,
        'v', 36,
      );
      END_STATE();
    case 6:
      if (lookahead == '{') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == '}') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(8);
      END_STATE();
    case 11:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 24,
        '#', 2,
        '$', 20,
        '\'', 25,
        '(', 14,
        ')', 15,
        '-', 38,
        ':', 21,
        '[', 16,
        ']', 17,
        '{', 18,
        '}', 19,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if (lookahead != 0 &&
          (lookahead < '0' || ';' < lookahead)) ADVANCE(42);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      if (lookahead == '#') ADVANCE(2);
      if (lookahead == '(') ADVANCE(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__string_content_double);
      if (lookahead == '\n') ADVANCE(30);
      if (lookahead == '#') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__string_content_double);
      if (lookahead == '\n') ADVANCE(30);
      if (lookahead == '#') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__string_content_double);
      if (lookahead == '#') ADVANCE(29);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(30);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__string_content_double);
      if (lookahead == '#') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__string_content_double);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__string_content_single);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(32);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__string_content_single);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__string_content_single);
      if (lookahead == '#') ADVANCE(34);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(35);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__string_content_single);
      if (lookahead == '#') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__string_content_single);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_identifier);
      ADVANCE_MAP(
        'u', 42,
        'x', 41,
        '0', 42,
        '\\', 42,
        'a', 42,
        'b', 42,
        'e', 42,
        'f', 42,
        'n', 42,
        'r', 42,
        't', 42,
        'v', 42,
      );
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if ((!eof && set_contains(sym_identifier_character_set_1, 10, lookahead))) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '#') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(44);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 12},
  [2] = {.lex_state = 11},
  [3] = {.lex_state = 11},
  [4] = {.lex_state = 11},
  [5] = {.lex_state = 11},
  [6] = {.lex_state = 11},
  [7] = {.lex_state = 11},
  [8] = {.lex_state = 11},
  [9] = {.lex_state = 11},
  [10] = {.lex_state = 11},
  [11] = {.lex_state = 11},
  [12] = {.lex_state = 11},
  [13] = {.lex_state = 11},
  [14] = {.lex_state = 11},
  [15] = {.lex_state = 11},
  [16] = {.lex_state = 11},
  [17] = {.lex_state = 11},
  [18] = {.lex_state = 11},
  [19] = {.lex_state = 11},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 12},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 12},
  [29] = {.lex_state = 12},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym_expression] = STATE(31),
    [sym_sub_expression] = STATE(31),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__term] = STATE(19),
    [sym_sub_expression] = STATE(19),
    [sym_list] = STATE(19),
    [sym_block] = STATE(19),
    [sym_single_term_call] = STATE(19),
    [sym_scope_ref] = STATE(19),
    [sym_string] = STATE(19),
    [aux_sym_expression_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_RPAREN] = ACTIONS(11),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(23),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__term] = STATE(19),
    [sym_sub_expression] = STATE(19),
    [sym_list] = STATE(19),
    [sym_block] = STATE(19),
    [sym_single_term_call] = STATE(19),
    [sym_scope_ref] = STATE(19),
    [sym_string] = STATE(19),
    [aux_sym_expression_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(29),
    [sym_identifier] = ACTIONS(13),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_RPAREN] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(23),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
  [4] = {
    [sym__term] = STATE(4),
    [sym_sub_expression] = STATE(4),
    [sym_list] = STATE(4),
    [sym_block] = STATE(4),
    [sym_single_term_call] = STATE(4),
    [sym_scope_ref] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym_list_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(34),
    [anon_sym_LBRACK] = ACTIONS(37),
    [anon_sym_RBRACK] = ACTIONS(40),
    [anon_sym_LBRACE] = ACTIONS(42),
    [anon_sym_RBRACE] = ACTIONS(40),
    [anon_sym_DOLLAR] = ACTIONS(45),
    [anon_sym_COLON] = ACTIONS(48),
    [sym_number] = ACTIONS(51),
    [anon_sym_DQUOTE] = ACTIONS(54),
    [anon_sym_SQUOTE] = ACTIONS(57),
    [sym_comment] = ACTIONS(3),
  },
  [5] = {
    [sym__term] = STATE(19),
    [sym_sub_expression] = STATE(19),
    [sym_list] = STATE(19),
    [sym_block] = STATE(19),
    [sym_single_term_call] = STATE(19),
    [sym_scope_ref] = STATE(19),
    [sym_string] = STATE(19),
    [aux_sym_expression_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(60),
    [sym_identifier] = ACTIONS(62),
    [anon_sym_LPAREN] = ACTIONS(65),
    [anon_sym_RPAREN] = ACTIONS(60),
    [anon_sym_LBRACK] = ACTIONS(68),
    [anon_sym_LBRACE] = ACTIONS(71),
    [anon_sym_DOLLAR] = ACTIONS(74),
    [anon_sym_COLON] = ACTIONS(77),
    [sym_number] = ACTIONS(80),
    [anon_sym_DQUOTE] = ACTIONS(83),
    [anon_sym_SQUOTE] = ACTIONS(86),
    [sym_comment] = ACTIONS(3),
  },
  [6] = {
    [sym__term] = STATE(9),
    [sym_sub_expression] = STATE(9),
    [sym_list] = STATE(9),
    [sym_block] = STATE(9),
    [sym_single_term_call] = STATE(9),
    [sym_scope_ref] = STATE(9),
    [sym_string] = STATE(9),
    [aux_sym_list_repeat1] = STATE(9),
    [sym_identifier] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_RBRACE] = ACTIONS(91),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(93),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
  [7] = {
    [sym__term] = STATE(8),
    [sym_sub_expression] = STATE(8),
    [sym_list] = STATE(8),
    [sym_block] = STATE(8),
    [sym_single_term_call] = STATE(8),
    [sym_scope_ref] = STATE(8),
    [sym_string] = STATE(8),
    [aux_sym_list_repeat1] = STATE(8),
    [sym_identifier] = ACTIONS(95),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_RBRACK] = ACTIONS(97),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(99),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
  [8] = {
    [sym__term] = STATE(4),
    [sym_sub_expression] = STATE(4),
    [sym_list] = STATE(4),
    [sym_block] = STATE(4),
    [sym_single_term_call] = STATE(4),
    [sym_scope_ref] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym_list_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(101),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_RBRACK] = ACTIONS(103),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(105),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
  [9] = {
    [sym__term] = STATE(4),
    [sym_sub_expression] = STATE(4),
    [sym_list] = STATE(4),
    [sym_block] = STATE(4),
    [sym_single_term_call] = STATE(4),
    [sym_scope_ref] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym_list_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(101),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_RBRACE] = ACTIONS(107),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(21),
    [sym_number] = ACTIONS(105),
    [anon_sym_DQUOTE] = ACTIONS(25),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 1,
      sym_identifier,
    ACTIONS(109), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [21] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(113), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [42] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      sym_identifier,
    ACTIONS(117), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [63] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      sym_identifier,
    ACTIONS(121), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [84] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(125), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [105] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(129), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [126] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      sym_identifier,
    ACTIONS(133), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [147] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      sym_identifier,
    ACTIONS(137), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [168] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(141), 12,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [189] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(145), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      anon_sym_DOLLAR,
      anon_sym_COLON,
      sym_number,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [208] = 4,
    ACTIONS(149), 1,
      anon_sym_DQUOTE,
    ACTIONS(153), 1,
      sym_comment,
    STATE(22), 1,
      aux_sym_string_repeat1,
    ACTIONS(151), 2,
      sym__string_content_double,
      sym_escape_sequence,
  [222] = 4,
    ACTIONS(149), 1,
      anon_sym_SQUOTE,
    ACTIONS(153), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_string_repeat2,
    ACTIONS(155), 2,
      sym__string_content_single,
      sym_escape_sequence,
  [236] = 4,
    ACTIONS(153), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_DQUOTE,
    STATE(24), 1,
      aux_sym_string_repeat1,
    ACTIONS(159), 2,
      sym__string_content_double,
      sym_escape_sequence,
  [250] = 4,
    ACTIONS(153), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_SQUOTE,
    STATE(25), 1,
      aux_sym_string_repeat2,
    ACTIONS(161), 2,
      sym__string_content_single,
      sym_escape_sequence,
  [264] = 4,
    ACTIONS(153), 1,
      sym_comment,
    ACTIONS(163), 1,
      anon_sym_DQUOTE,
    STATE(24), 1,
      aux_sym_string_repeat1,
    ACTIONS(165), 2,
      sym__string_content_double,
      sym_escape_sequence,
  [278] = 4,
    ACTIONS(153), 1,
      sym_comment,
    ACTIONS(168), 1,
      anon_sym_SQUOTE,
    STATE(25), 1,
      aux_sym_string_repeat2,
    ACTIONS(170), 2,
      sym__string_content_single,
      sym_escape_sequence,
  [292] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_identifier,
    STATE(30), 1,
      sym_expression,
  [302] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
  [309] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(175), 1,
      sym_identifier,
  [316] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(177), 1,
      sym_identifier,
  [323] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
  [330] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(181), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(10)] = 0,
  [SMALL_STATE(11)] = 21,
  [SMALL_STATE(12)] = 42,
  [SMALL_STATE(13)] = 63,
  [SMALL_STATE(14)] = 84,
  [SMALL_STATE(15)] = 105,
  [SMALL_STATE(16)] = 126,
  [SMALL_STATE(17)] = 147,
  [SMALL_STATE(18)] = 168,
  [SMALL_STATE(19)] = 189,
  [SMALL_STATE(20)] = 208,
  [SMALL_STATE(21)] = 222,
  [SMALL_STATE(22)] = 236,
  [SMALL_STATE(23)] = 250,
  [SMALL_STATE(24)] = 264,
  [SMALL_STATE(25)] = 278,
  [SMALL_STATE(26)] = 292,
  [SMALL_STATE(27)] = 302,
  [SMALL_STATE(28)] = 309,
  [SMALL_STATE(29)] = 316,
  [SMALL_STATE(30)] = 323,
  [SMALL_STATE(31)] = 330,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 2, 0, 3),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(19),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(26),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(7),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(6),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(28),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(29),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(19),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(20),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2, 0, 4), SHIFT_REPEAT(21),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sub_expression, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sub_expression, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_term_call, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_term_call, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scope_ref, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scope_ref, 2, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 1, 0, 2),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_expression_repeat1, 1, 0, 2),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(25),
  [173] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_lish(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
