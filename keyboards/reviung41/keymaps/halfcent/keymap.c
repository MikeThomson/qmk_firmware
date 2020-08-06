/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "halfcent.h"

enum layer_names {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _SPACE = 3,
    _ADJUST = 4
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define HC_SPCFNSPC LT(_SPACE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    HC_TABCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                            KC_LALT,   LOWER,    HC_SPCFNSPC,   RAISE,    KC_RGUI
  ),
  
  [_SPACE] = LAYOUT_reviung41(
    _______,  _______,  KC_UP,    _______,  _______,    _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,   _______,            _______,  _______,  _______,    _______,  _______,   _______,
    _______,  _______,   _______,  _______,  _______,   _______,            _______,  _______,   _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
     KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            _______,    _______,    _______,    _______,    _______,    _______,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            _______,    _______,    _______,    _______,   _______,   _______,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,               KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            _______,    _______,    _______,    _______,    _______,    _______,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  _______,   KC_QUOT,            _______,    _______,    _______,    _______,   _______,   _______,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RESET,     XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

