/* Copyright 2018 Holten Campbell
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

#define TABCTL MT(MOD_LCTL,KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
		KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,             KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    KC_HOME, KC_END,
         TABCTL, KC_A,     KC_S,     KC_D,   KC_F,    KC_G,                      KC_H, KC_J,     KC_K, KC_L,    KC_QUOT, KC_ENT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    MO(4),            KC_B,  KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
		KC_LCTL,  KC_RGUI,                    KC_RALT, HC_BSPCFN1,     HC_SPCFN2,   KC_RALT,                          KC_RGUI, KC_RCTL
    ),

    LAYOUT(
		KC_GRV,    _______,   KC_UP,   _______,   _______,    _______,          _______,   _______,    _______,     _______,   _______ ,   _______,   KC_DEL,
        _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   _______,    _______,          _______,   _______,    _______,   _______,  KC_SCLN,   KC_BSLS,
		_______,   _______,   _______,   _______,   _______,    _______,          _______,   _______,    _______,   _______,   _______,   _______,   _______,
        _______,   _______,                         _______,    _______,        _______,   _______,                                     _______,   _______
    ),

    LAYOUT(
		_______,  KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,     KC_8,    KC_9,    KC_0,      KC_MINS,  KC_EQL,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   KC_P4,    KC_P5,   KC_P6,   KC_LBRC,   KC_RBRC,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   KC_P1,    KC_P2,   KC_P3,   _______,   _______,  _______,
		_______,  _______,                         _______,    _______,	         _______,   KC_PDOT,                               _______,  _______
    ),

    LAYOUT(
        _______,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_F10,    KC_F11,   KC_F12,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,  _______,
		_______,  _______,                         _______,    _______,	         _______,   _______,                               _______,  RESET
    ),

    LAYOUT(
        _______,  _______,   _______,   _______,   _______,    _______,          _______,     _______,    _______,   _______,   _______,    HC_DSKL,   HC_DSKR,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,  _______,
		_______,  _______,                         _______,    _______,	         _______,   _______,                               _______,  _______
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}



void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

//function for layer indicator LED
layer_state_t layer_state_set_keymap(layer_state_t state)
{
    if (get_highest_layer(state) == 1) {
        writePinHigh(B3);
	} else {
		writePinLow(B3);
    }
    return state;
}
