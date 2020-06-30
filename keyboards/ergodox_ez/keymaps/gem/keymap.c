#include QMK_KEYBOARD_H
#include "version.h"
#include "action_layer.h"

enum layers {
    BASE, // default layer
    GAME,  // media keys
    SYMB, // symbols
    MISC,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

#define _____ KC_TRNS
#define XXXX KC_TRNS

enum {
    TD_ESC_1,
};


qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// TODO: RBRC and RPRN doesn't seem to be very useful to be put on a separate but needed for other. Maybe put on symb?
// TODO: add logger app for keyboard to record all events and analyse usage (should be possible to enable / disable to type passwords).
// TODO: replace caps ctrl with something more useful.
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_MINS,               KC_EQL,      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_MINS,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_LBRC,               KC_RBRC,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_LPRN,               KC_RPRN,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  KC_GRV,          KC_LGUI,     KC_LALT,       KC_BSPC, KC_DEL,                                                        KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,  KC_RALT,
                                                                 KC_HOME, KC_LGUI,               TT(MISC),     KC_END,
                                                                           KC_ENT,              KC_PGUP,
                                              LT(SYMB, KC_SPACE), KC_LCTL, KC_INS,              KC_PGDN,    KC_LCTL, LT(SYMB, KC_ENT)
),
[GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_6,                  KC_PAUS,     KC_6,    KC_U,    KC_8,    KC_9,     KC_0,      KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,                  KC_VOLU,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_N,                  KC_VOLD,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  KC_LALT,         KC_H,        KC_J,          KC_K,    KC_SPC,                                                        KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,  KC_LWIN,
                                                                 KC_7,    KC_8,                  MO(MISC),     KC_DEL,
                                                                          KC_9,                  KC_PGUP,
                                                        KC_SPC,  KC_U,    KC_0,                  KC_PGDN,    MO(SYMB), KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   =  |      |           |      |   Up |   7  |   UP  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   -  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `-------------------- 
 * 
 *  KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _____,     _____, KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,
  _____, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_EQL, _____,     _____, KC_UP,   KC_HOME,  KC_UP,   KC_END,     KC_ASTR, KC_F12,
  _____, KC_HASH, KC_DLR,   KC_LPRN, KC_RPRN,  KC_MINS,                  LCTL(KC_LEFT), KC_LEFT,  KC_DOWN,        KC_RIGHT, LCTL(KC_RIGHT), _____,
  _____, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV , _____,          _____, KC_AMPR,      KC_BSPC,  LSFT(KC_DEL),  KC_DEL, _____, _____,
  RESET,   _____, _____, _____, KC_LBRC,                                         KC_0,     KC_DOT,   _____,  KC_EQL,  _____,
                                               RGB_MOD, DF(BASE),     RGB_TOG, RGB_SLD,
                                                        DF(GAME),     _____,
                                      RGB_VAD, XXXX, _____,           _____, XXXX, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MISC] = LAYOUT_ergodox_pretty(
  // left hand
  _____, _____, _____, _____, _____, _____, _____,        _____,   _____, _____, _____, _____, _____, _____,
  _____, _____, _____, KC_MS_U, _____, _____, _____,      KC_VOLU, _____, KC_7, KC_8, KC_9, _____, _____,
  KC_CAPS, _____, KC_MS_L, KC_MS_D, KC_MS_R, _____,                       KC_4, KC_5, KC_6, _____, _____, KC_MPLY,
  _____, _____, _____, _____, _____, _____, _____,        KC_VOLD, _____, KC_1, KC_2, KC_3, _____, _____,
  RESET, _____, _____, KC_BTN1, KC_BTN2,                                         KC_0, _____, _____, _____, _____,

                                               _____, _____,     XXXX, _____,
                                                        _____,     KC_VOLU,
                                      _____, _____, _____,     KC_VOLD, _____, _____
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
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

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  ergodox_right_led_1_off();
    if(layer_state_cmp(default_layer_state, GAME)) {
      ergodox_right_led_1_on();
  }
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
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
