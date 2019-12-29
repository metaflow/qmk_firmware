/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

#define _QWERTY 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_7  , KC_8  , KC_3  , KC_4  , KC_5  ,KC_6,                         KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,KC_6,
     KC_A  , KC_B  , KC_C  , KC_D  , KC_E  ,KC_F,                         KC_A  , KC_B  , KC_C  , KC_D  , KC_E  ,KC_F,
     KC_G  , KC_H  , KC_I  , KC_J  , KC_K  ,KC_L,                         KC_G  , KC_H  , KC_I  , KC_J  , KC_K  ,KC_L,
     KC_M  , KC_N  , KC_O  , KC_P , KC_Q,                                         KC_M  , KC_N  , KC_O  , KC_P , KC_Q,
                                     KC_R, KC_S,                          KC_R, KC_S,
                               KC_T, KC_U, KC_V,                          KC_T, KC_U, KC_V
  ),
};
