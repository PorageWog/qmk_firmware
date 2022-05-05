#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCTION 3

#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_D MT(MOD_LSFT, KC_D)
#define HRM_F MT(MOD_LCTL, KC_F)
#define HRM_J MT(MOD_RCTL, KC_J)
#define HRM_K MT(MOD_RSFT, KC_K)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_SCL MT(MOD_LGUI, KC_SCLN)

#define TD_Q TD(TAPDANCE_Q_TAB)
#define TD_A TD(TAPDANCE_A_ESC)
#define TD_SCLN TD(TAPDANCE_SCLN_QUOT)
#define LOCK TD(TAPDANCE_LOCK)

#define COPY LCTL(KC_INS)
#define PASTE LSFT(KC_INS)

#define CONTEXT_ACTIONS LALT(KC_ENT)
#define CODE_COMPLETION LCTL(KC_SPC)

#define KC_QWRT TO(0)
#define KC_LWR MO(1)
#define KC_RSE MO(2)
#define KC_FUNC TO(3)
#define KC_F_OS MO(3)
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
  TAPDANCE_LOCK
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TAPDANCE_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
  [TAPDANCE_A_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
  [TAPDANCE_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TAPDANCE_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, LGUI(KC_L))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  TD_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  TD_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,                               KC_H,    HRM_J,   HRM_K,   HRM_L,   TD_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,           KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LWR,  W_RSE,   KC_ENT,                    KC_SPC,  KC_RSE,  KC_LWR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_LCBR, KC_LCBR,                            KC_RCBR, KC_RCBR, _______, _______, KC_PSCR, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LOCK,    LOCK,    _______, _______, KC_LBRC, KC_LBRC,                            KC_RBRC, KC_RBRC, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_CAPS, _______, _______, KC_LT,   KC_LT,   _______,          _______, KC_GT,   KC_GT,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_QWRT, KC_FUNC, KC_EQL,                    KC_MINS, KC_F_OS, KC_QWRT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LOCK,    LOCK,    _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_CAPS, _______, COPY,    PASTE,   _______, _______,          _______, _______, _______, _______, _______, KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_FUNC, KC_QWRT, CONTEXT_ACTIONS,   CODE_COMPLETION, KC_QWRT, KC_F_OS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNCTION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BRIU, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_QWRT, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_F11,                             KC_F12,  KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_MUTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BRID, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_VOLD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_QWRT, KC_QWRT, _______,                   _______, KC_QWRT, KC_QWRT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

/*
  [_] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
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
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
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
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_FUNCTION, layer_state_cmp(state, _FUNCTION));
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
            return 150;
        default:
            return 200;
    }
}
