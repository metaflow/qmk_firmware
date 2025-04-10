#include QMK_KEYBOARD_H
#include "version.h"
#include "action_layer.h"

enum layers {
    BASE, // default layer
    GAME,
    SC2,
    WORMS,
    SYMB, // symbols
    MISC,  // media keys
};

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
  MK_40,
  MK_39,
  MK_28,
};

#define _____ KC_TRNS
#define XXXX KC_TRNS

enum {
    TD_SCLN_Q,
    TD_L_M, 
};

struct multistate {
  uint16_t trigger;
  uint16_t codes[3];
  uint8_t codes_length;
  uint16_t last_time;
  uint8_t pos;
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_Q] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [TD_L_M] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_M),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_MINS,               KC_F11,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_EQL,                KC_PGUP,  KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_MINS,               KC_PGDN,  KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  KC_GRV,          KC_LGUI,     KC_DEL,        KC_LALT, KC_SPACE,                                          KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,  KC_RALT,
                                                                 KC_HOME, LT(MISC, KC_BSPC),              DF(GAME),  KC_CAPS,
                                                                           KC_INS,               KC_PSCR,
                                              LT(SYMB, KC_SPACE), KC_LCTL, KC_LSFT,              KC_RSFT,    KC_RCTL, LT(SYMB, KC_ENT)
),
[GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_6,                  KC_PAUSE,     KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_EQL,                KC_VOLU,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_MINS,               KC_VOLD,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  KC_F10,         KC_H,        KC_ENT,       KC_LALT,    KC_SPC,                                                        KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,  KC_LWIN,
                                                          KC_7, LT(MISC, KC_BSPC),                 DF(BASE),     KC_MS_BTN2,
                                                                          KC_INS,                  KC_PSCR,
                                                           KC_SPC,  KC_J, KC_L,                  KC_MS_BTN1,  MO(SYMB), KC_ENT
),
[SC2] = LAYOUT_ergodox_pretty(
  KC_ESC,          KC_1,        MK_28,         MK_39,   MK_40,    KC_5,    KC_6,                  KC_PAUS,     KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,                  KC_VOLU,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_SCLN,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_N,                  KC_VOLD,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  KC_F10,         KC_H,        KC_J,          KC_LALT,    KC_L,                                                    KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,  KC_LWIN,
                                                                  KC_F1,  KC_F2,                  DF(BASE),     KC_END,
                                                                     S(A(KC_5)),                  KC_PSCR,
                                                      KC_SPC,  KC_LCTL, KC_LSFT,                 TT(MISC),    MO(SYMB), KC_ENT
),
[SYMB] = LAYOUT_ergodox_pretty(
  EMAIL,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _____,     _____, KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,
  _____, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_EQL, _____,        KC_PGUP, KC_HOME, LCTL(KC_LEFT), LCTL(KC_RIGHT),   KC_END,     _____, KC_F12,
  _____, KC_HASH, KC_DLR,   KC_LPRN, KC_RPRN,  KC_MINS,                     KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, _____, _____,
  _____, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV , _____,        KC_PGDN, KC_AMPR, KC_BSPC,  LSFT(KC_DEL),  KC_DEL, _____, _____,
  _____,   _____, _____, _____, _____,                                         _____,     _____,   _____,  _____,  _____,
                                          _____, DF(BASE),     _____, _____,
                                                 DF(GAME),      _____,
                                      _____, _____, _____,        _____, _____, _____
),
[MISC] = LAYOUT_ergodox_pretty(
  // left hand/*  */
  _____, _____, _____, S(A(KC_3)), S(A(KC_4)), S(A(KC_5)), _____,          _____,   _____, _____, _____, _____, _____, KC_BSPC,
  _____, _____,   _____,   KC_MS_U, _____,   _____, KC_VOLU,      KC_VOLU, _____, KC_7, KC_8,   KC_9,  _____, _____,
  KC_CAPS, _____, KC_MS_L, KC_MS_D, KC_MS_R, _____,               _____, KC_4, KC_5,   KC_6,  KC_MPLY, _____,
  _____, _____, _____, _____, _____, _____, KC_VOLD,              KC_VOLD, _____, KC_1, KC_2,   KC_3, _____, _____,
  RESET, _____, _____, KC_BTN1, KC_BTN2,                                  KC_0, KC_DOT, _____, _____, _____,

                                               _____, _____,     DF(BASE), DF(WORMS),
                                                    _____,     DF(GAME),
                                      _____, _____, _____,     DF(SC2), _____, _____
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;
  static struct multistate taps[] = {
    { MK_40, {KC_4, KC_0, KC_Q}, 3},
    { MK_39, {KC_3, KC_9, KC_Q}, 3},
    { MK_28, {KC_2, KC_8, KC_Q}, 3}
  };
  for (int i = 0; i < sizeof(taps) / sizeof(taps[0]); i++) {
    if (keycode != taps[i].trigger) continue;
    if (TIMER_DIFF_16(record->event.time, taps[i].last_time) < 500) {
      taps[i].pos = (taps[i].pos + 1) % taps[i].codes_length;
    } else {
      taps[i].pos = 0;
    }
    taps[i].last_time = record->event.time;
    tap_code(taps[i].codes[taps[i].pos]);
    return true;
  }
  switch (keycode) {
    case EMAIL:
      if (!record->event.pressed) return true;
      // SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      SEND_STRING ("goncharov.mikhail@gmail.com");
      return false;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  ergodox_led_all_set(1);
};

// Runs constantly in the background, in a loop. For base layers.
void matrix_scan_user(void) {
  ergodox_right_led_1_off();
  if(layer_state_cmp(default_layer_state, GAME)) {
      ergodox_right_led_1_on();
      ergodox_right_led_set(1, 1);
  }
  if(layer_state_cmp(default_layer_state, SC2)) {
      ergodox_right_led_1_on();
      ergodox_right_led_set(1, 10);
  }
  if(layer_state_cmp(default_layer_state, WORMS)) {
      ergodox_right_led_1_on();
      ergodox_right_led_set(1, 10);
  }
};

// Runs whenever there is a layer state change. For momentary layers.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_led_all_set(1);
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case SYMB:
        ergodox_right_led_2_on();
        break;
      case MISC:
        ergodox_right_led_3_on();
        break;
    }
  return state;
};