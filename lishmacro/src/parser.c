#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 12
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_PIPE = 2,
  anon_sym_TILDE = 3,
  sym_comment = 4,
  sym_macro_body = 5,
  sym_source_file = 6,
  sym_macro_definition = 7,
  sym__macro_param = 8,
  sym_deferred_param = 9,
  aux_sym_source_file_repeat1 = 10,
  aux_sym_macro_definition_repeat1 = 11,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_PIPE] = "|",
  [anon_sym_TILDE] = "~",
  [sym_comment] = "comment",
  [sym_macro_body] = "macro_body",
  [sym_source_file] = "source_file",
  [sym_macro_definition] = "macro_definition",
  [sym__macro_param] = "_macro_param",
  [sym_deferred_param] = "deferred_param",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_macro_definition_repeat1] = "macro_definition_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [sym_comment] = sym_comment,
  [sym_macro_body] = sym_macro_body,
  [sym_source_file] = sym_source_file,
  [sym_macro_definition] = sym_macro_definition,
  [sym__macro_param] = sym__macro_param,
  [sym_deferred_param] = sym_deferred_param,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_macro_definition_repeat1] = aux_sym_macro_definition_repeat1,
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_macro_body] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_macro_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__macro_param] = {
    .visible = false,
    .named = true,
  },
  [sym_deferred_param] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_macro_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_body = 1,
  field_name = 2,
  field_param = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_param] = "param",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_param, 0},
  [1] =
    {field_body, 3},
    {field_name, 1},
  [3] =
    {field_param, 0, .inherited = true},
    {field_param, 1, .inherited = true},
  [5] =
    {field_body, 4},
    {field_name, 1},
    {field_param, 2, .inherited = true},
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
};

static TSCharacterRange sym_identifier_character_set_1[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'!', '!'}, {'%', '&'}, {'*', '9'}, {';', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {0x7f, 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '#') ADVANCE(1);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead == '~') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (lookahead != 0 &&
          (lookahead < '"' || '$' < lookahead) &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ':' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(6);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(8);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_identifier);
      if ((!eof && set_contains(sym_identifier_character_set_1, 9, lookahead))) ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '#') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
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
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0, .external_lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0, .external_lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_macro_body] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(12),
    [sym_macro_definition] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(5),
    [anon_sym_PIPE] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__macro_param] = STATE(7),
    [sym_deferred_param] = STATE(7),
    [aux_sym_macro_definition_repeat1] = STATE(3),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_PIPE] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(11),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__macro_param] = STATE(7),
    [sym_deferred_param] = STATE(7),
    [aux_sym_macro_definition_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_PIPE] = ACTIONS(13),
    [anon_sym_TILDE] = ACTIONS(11),
    [sym_comment] = ACTIONS(3),
  },
  [4] = {
    [sym__macro_param] = STATE(7),
    [sym_deferred_param] = STATE(7),
    [aux_sym_macro_definition_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(15),
    [anon_sym_PIPE] = ACTIONS(18),
    [anon_sym_TILDE] = ACTIONS(20),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_PIPE,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_macro_definition,
      aux_sym_source_file_repeat1,
  [14] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      anon_sym_PIPE,
    STATE(6), 2,
      sym_macro_definition,
      aux_sym_source_file_repeat1,
  [28] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(30), 3,
      anon_sym_PIPE,
      anon_sym_TILDE,
      sym_identifier,
  [37] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(32), 3,
      anon_sym_PIPE,
      anon_sym_TILDE,
      sym_identifier,
  [46] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(34), 2,
      ts_builtin_sym_end,
      anon_sym_PIPE,
  [54] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(36), 2,
      ts_builtin_sym_end,
      anon_sym_PIPE,
  [62] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(38), 1,
      sym_identifier,
  [69] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
  [76] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym_macro_body,
  [83] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(44), 1,
      sym_identifier,
  [90] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(46), 1,
      sym_macro_body,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 14,
  [SMALL_STATE(7)] = 28,
  [SMALL_STATE(8)] = 37,
  [SMALL_STATE(9)] = 46,
  [SMALL_STATE(10)] = 54,
  [SMALL_STATE(11)] = 62,
  [SMALL_STATE(12)] = 69,
  [SMALL_STATE(13)] = 76,
  [SMALL_STATE(14)] = 83,
  [SMALL_STATE(15)] = 90,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macro_definition_repeat1, 2, 0, 3), SHIFT_REPEAT(7),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macro_definition_repeat1, 2, 0, 3),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macro_definition_repeat1, 2, 0, 3), SHIFT_REPEAT(14),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macro_definition_repeat1, 1, 0, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_deferred_param, 2, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro_definition, 4, 0, 2),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro_definition, 5, 0, 4),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [40] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_macro_body = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_macro_body] = sym_macro_body,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_macro_body] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_lishmacro_external_scanner_create(void);
void tree_sitter_lishmacro_external_scanner_destroy(void *);
bool tree_sitter_lishmacro_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_lishmacro_external_scanner_serialize(void *, char *);
void tree_sitter_lishmacro_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_lishmacro(void) {
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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_lishmacro_external_scanner_create,
      tree_sitter_lishmacro_external_scanner_destroy,
      tree_sitter_lishmacro_external_scanner_scan,
      tree_sitter_lishmacro_external_scanner_serialize,
      tree_sitter_lishmacro_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
