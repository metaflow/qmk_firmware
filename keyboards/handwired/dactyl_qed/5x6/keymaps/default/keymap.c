/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _GAMEPAD 1
#define _LEVEL1 2
#define _TOP 3
#define TOP  MO(_TOP)
#define LEVEL1  MO(_LEVEL1)
#define GAMEPAD TG(_GAMEPAD)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
    KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,/**/KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,/**/KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,/**/KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LBRC, KC_LPRN,         /**/         KC_RPRN, KC_RBRC, KC_MINS, KC_EQL , _______,
                                        _______, KC_DEL ,/**/KC_BSPC, KC_ENT,
                               KC_SPC , TOP    , LEVEL1 ,/**/_______, TOP    , KC_SPC
  ),
  [_GAMEPAD] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,/**/_______, _______, KC_UP,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______,/**/_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,/**/_______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         /**/         _______, _______, _______, _______, _______,
                                        _______, _______,/**/_______, _______,
                               _______, _______, _______,/**/_______, _______, _______
  ),
  [_LEVEL1] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,/**/_______, KC_PGUP, KC_UP,   KC_PGDN,  _______, _______,
    KC_CAPS, _______, _______, _______, _______, _______,/**/KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, _______,
    _______, _______, _______, _______, _______, _______,/**/_______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, GAMEPAD,         /**/         _______, _______, _______, _______, _______,
                                        _______, RESET  ,/**/_______, _______,
                               _______, _______, _______,/**/_______, _______, _______
  ),
  [_TOP] = LAYOUT_5x6(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,/**/KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,/**/KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    _______, _______, _______, _______, _______, _______,/**/_______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, GAMEPAD,         /**/         _______, _______, _______, _______, _______,
                                        _______, RESET  ,/**/_______, _______,
                               _______, _______, _______,/**/_______, _______, _______
  ),
};
