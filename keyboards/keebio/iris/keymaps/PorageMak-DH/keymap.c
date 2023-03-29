#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _QWERTY 1
#define _SYMBOL 2
#define _NUMBER 3

#define ALTENT MT(MOD_LALT, KC_ENT)
#define SHIFTandENTER S(KC_ENT)

#define LOCK TD(TAPDANCE_LOCK)
#define CAPS TD(TAPDANCE_CAPS)

#define CONTEXT_ACTIONS A(KC_ENT)
#define CODE_COMPLETION C(KC_SPC)
#define PRT_WIN A(KC_PSCR)
#define FIND RCS(KC_F)
#define TEST RCS(KC_T)
#define RENAME S(KC_F6)
#define USAGES A(KC_F7)
#define FORMAT LCA(KC_L)
#define HINT C(KC_P)
#define VSMENU RCS(KC_P)

#define KC_COLEMAK DF(_COLEMAK)
#define KC_MISC MO(_QWERTY)
#define KC_SYM MO(_SYMBOL)
#define KC_NUMS MO(_NUMBER)
#define KC_QWERT DF(_QWERTY)
#define KC_COLEM DF(_COLEMAK)

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
};

enum {
  TAPDANCE_LOCK,
  TAPDANCE_CAPS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TAPDANCE_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, G(KC_L)),
  [TAPDANCE_CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_QWERT,_______ ,_______ ,FIND    ,VSMENU  ,TEST                               ,RENAME  ,USAGES  ,_______ ,FORMAT  ,HINT    ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B                               ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G                               ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_LBRC ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_EQL           ,KC_MINS ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RBRC
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,KC_LCTL ,ALTENT  ,KC_LSFT                   ,KC_SPC  ,KC_NUMS ,KC_SYM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_COLEM,_______ ,_______ ,_______ ,FIND    ,TEST                               ,RENAME  ,USAGES  ,_______ ,FORMAT  ,HINT    ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T                               ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G                               ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_LBRC ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_EQL           ,KC_MINS ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RBRC
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,KC_LCTL ,ALTENT  ,KC_LSFT                   ,KC_SPC  ,KC_NUMS ,KC_SYM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_BRIU ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5                              ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_VOLU
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC                            ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_MUTE
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_BRID ,_______ ,_______ ,_______ ,_______ ,KC_F11  ,KC_PLUS          ,_______ ,KC_F12  ,_______ ,_______ ,_______ ,_______ ,KC_VOLD
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,KC_LGUI ,SHIFTandENTER             ,_______ ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                               ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,LOCK    ,_______ ,_______ ,_______ ,_______ ,_______                            ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_GRV  ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,CAPS    ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_PLUS          ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BSLS ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,_______ ,CONTEXT_ACTIONS   ,CODE_COMPLETION ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

/*
  [_] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,_______ ,_______                   ,_______ ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
 */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _QWERTY);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _QWERTY);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _QWERTY);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_OFF}
);

const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_BLUE},
    {6, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    colemak_layer,
    qwerty_layer,
    symbol_layer,
    number_layer,
    capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_COLEMAK, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_NUMBER, layer_state_cmp(state, _NUMBER));
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return 200;
    }
}
