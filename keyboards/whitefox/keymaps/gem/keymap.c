/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"

#define ____ KC_TRNS
#define DEL_LN LSFT(KC_DEL)
#define W_FF LCTL(KC_RGHT)
#define W_BACK LCTL(KC_LEFT)
#define CAPS2 LT(2, KC_CAPS)
#define L_DFLT 0
#define L_GAME 1
#define L_NAVI 2
#define L_UTIL 3

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
     * |---------------------------------------------------------------|
     * |FN 0 |   A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Alt | Caps |     |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [L_DFLT] = LAYOUT( \
        KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_INS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL, \
        CAPS2,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KC_NUHS, KC_ENT,           KC_HOME,\
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,          KC_UP,   KC_END,\
        KC_LCTL, KC_LGUI, KC_LALT,         LT(L_NAVI, KC_SPACE),                                KC_RALT,  DF(L_GAME), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [L_NAVI] = LAYOUT( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  ____,    ____,    KC_PAUSE, \
        ____,    KC_F13,  W_FF,    KC_F14, KC_F15, KC_F16, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_PSCR,  ____,    ____,    ____,             ____, \
        ____,    ____,    KC_SLCK, DEL_LN, ____,   ____,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RIGHT, ____,    ____,    ____,             ____, \
        ____,    ____,    ____,    KC_DEL, ____,   ____,   W_BACK,  ____,    ____,    ____,     ____,     ____,    ____,             KC_PGUP, ____, \
        ____,    ____,    ____,            ____,                                                ____,     ____,    ____,    KC_HOME, KC_PGDN, KC_END \
    ),
    [L_UTIL] = LAYOUT( \
        ____,    ____,    ____,    ____,   ____,   ____,   ____,    KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS,  ____,    ____,    ____,    ____,    ____, \
        ____,    KC_2,    ____,    ____,   ____,   ____,   ____,    KC_P7,   KC_P8,   KC_P9,    KC_PPLS,  ____,    ____,    ____,             KC_MUTE, \
        ____,    ____,    ____,    ____,   ____,   ____,   ____,    KC_P4,   KC_P5,   KC_P6,    KC_PENT,  ____,    ____,    KC_MPLY,          ____, \
        ____,    ____,    ____,    ____,   ____,   ____,   ____,    KC_P0,   KC_P1,   KC_P2,    KC_P3,    ____,    ____,             KC_VOLU, ____, \
        ____,    ____,    ____,            ____,                                                ____,     ____,    ____,    ____,    KC_VOLD, ____ \
    ),
    [L_GAME] = LAYOUT( \
        KC_ESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_INS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL, \
        KC_CAPS,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KC_NUHS, KC_ENT,           KC_HOME,\
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,          KC_UP,   KC_END,\
        KC_LCTL, KC_LGUI, KC_LALT,         KC_SPACE ,                                      LT(L_NAVI, KC_RALT),  DF(L_DFLT), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT \
    ),
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
