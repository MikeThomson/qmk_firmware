/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

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

#include QMK_KEYBOARD_H
#include "halfcent.h"

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define Z_SHIFT MT(MOD_LSFT, KC_Z)
#define SL_SHIFT MT(MOD_LSFT, KC_SLSH)
#define A_CTRL MT(MOD_LCTL, KC_A)
#define LOWER_ENT LT(_LOWER, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  A_CTRL,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  Z_SHIFT,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  SL_SHIFT,
                    KC_LGUI, LOWER, KC_BSPC,         HC_SPCFN1, LOWER_ENT,  KC_RALT
),

[_RAISE] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_GRV, XXXXXXX,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  KC_QUOT,
                    XXXXXXX, XXXXXXX, KC_DEL,      XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,  KC_DQT,
                    XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,  XXXXXXX, KC_DEL
)
};
