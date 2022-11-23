#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYMBOL 1
#define _NUMBER 2
#define _MISC 3

#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_D MT(MOD_LSFT, KC_D)
#define HRM_F MT(MOD_LCTL, KC_F)
#define HRM_J MT(MOD_RCTL, KC_J)
#define HRM_K MT(MOD_RSFT, KC_K)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_SCL MT(MOD_LGUI, KC_SCLN)

#define ALTWIN MT(MOD_LALT, KC_LGUI)
#define ALTENT MT(MOD_LALT, KC_ENT)
#define SHIFTorENTER MT(MOD_LSFT, KC_ENT)
#define SHIFTandENTER LSFT(KC_ENT)

#define TD_Q TD(TAPDANCE_Q_TAB)
#define TD_A TD(TAPDANCE_A_ESC)
#define TD_SCLN TD(TAPDANCE_SCLN_QUOT)
#define LOCK TD(TAPDANCE_LOCK)
#define CAPS TD(TAPDANCE_CAPS)
#define RSESPC TD(TAPDANCE_RSESPC)

#define COPY LCTL(KC_INS)
#define PASTE LSFT(KC_INS)

#define CONTEXT_ACTIONS LALT(KC_ENT)
#define CODE_COMPLETION LCTL(KC_SPC)

#define KC_SYM MO(1)
#define KC_NUMS MO(2)
#define KC_MISC MO(3)
#define W_RSE LT(2, KC_LGUI)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
};

enum {
  TAPDANCE_Q_TAB,
  TAPDANCE_A_ESC,
  TAPDANCE_SCLN_QUOT,
  TAPDANCE_LOCK,
  TAPDANCE_CAPS,
  TAPDANCE_RSESPC
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TAPDANCE_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
  [TAPDANCE_A_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
  [TAPDANCE_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TAPDANCE_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, LGUI(KC_L)),
  [TAPDANCE_CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS),
  [TAPDANCE_RSESPC] = ACTION_TAP_DANCE_DOUBLE(KC_NUMS, KC_RSFT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                               ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC
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
                                   ,_______ ,KC_LGUI ,SHIFTandENTER             ,_______ ,KC_MISC ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,KC_P1   ,KC_P2   ,KC_P3   ,KC_P4   ,KC_P5                              ,KC_P6   ,KC_P7   ,KC_P8   ,KC_P9   ,KC_P0   ,KC_DEL
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,LOCK    ,_______ ,_______ ,_______ ,_______ ,_______                            ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_GRV  ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,CAPS    ,_______ ,_______ ,COPY    ,PASTE   ,_______ ,KC_PLUS          ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BSLS ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,KC_MISC ,CONTEXT_ACTIONS   ,CODE_COMPLETION ,_______ ,KC_MISC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MISC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,KC_PSCR ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,_______ ,_______                   ,_______ ,_______ ,_______
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
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _MISC);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _MISC);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _MISC);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _MISC);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_MISC);
      } else {
        layer_off(_MISC);
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

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_OFF}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_BLUE},
    {6, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    lower_layer,
    raise_layer,
    function_layer,
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
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_NUMBER, layer_state_cmp(state, _NUMBER));
    rgblight_set_layer_state(_MISC, layer_state_cmp(state, _MISC));
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_SCL:
            return 350;
        case HRM_S:
        case HRM_L:
            return 250;
        case HRM_D:
        case HRM_K:
	case SHIFTorENTER:
            return 150;
        default:
            return 200;
    }
}
