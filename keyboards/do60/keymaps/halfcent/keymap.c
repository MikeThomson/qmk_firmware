#include QMK_KEYBOARD_H


#define HC_DSK_LEFT LCTL(LGUI(KC_LEFT))
#define HC_DSK_RIGHT LCTL(LGUI(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [0] = LAYOUT_60_ansi_split_bs_rshift(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS,   KC_DEL,   \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSPC,   \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,    \
      KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,     MO(1),    \
      KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                           KC_RGUI, MO(1),    KC_RGUI, KC_RCTL),
  // 0: Base Layer
  [1] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,  _______,   \
     _______, _______,   KC_UP,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,   HC_DSK_LEFT, HC_DSK_RIGHT,    _______,   \
     _______,KC_LEFT, KC_DOWN, KC_RIGHT,   _______,  _______,  _______,  _______,  _______,  KC_PGUP, KC_INS,_______, _______,    \
     _______,_______,   _______,   _______,  _______,  _______,  _______,  _______,  KC_PGDN,_______, _______,_______,     MO(1),    \
     _______,_______,_______,                 _______,                          _______, MO(1),   MO(2), _______),
  [2] = LAYOUT_60_ansi_split_bs_rshift(
      RESET, _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______, _______, _______,  _______,   \
     _______, _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______, _______,    _______,   \
     _______,_______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,_______, _______,    \
     _______,_______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,_______, _______,_______,     _______,    \
     _______,_______,_______,                 _______,                          _______, _______,   _______, _______),

  // 1: Function Layer
  /*
  [1] = LAYOUT_60_ansi_split_bs_rshift(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_NO,    KC_NO,     \
      KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  BL_TOGG,BL_ON,  BL_INC, KC_INS, KC_NO,   KC_PSCR, KC_SLCK,  KC_PAUS,          KC_DEL,    \
      KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, BL_STEP,BL_OFF, BL_DEC, KC_NO,  KC_NO,   KC_HOME, KC_PGUP,  KC_NO,            KC_ENT,    \
      KC_LSFT, KC_NO,   KC_NO,   KC_APP,  BL_STEP,  KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_MUTE, KC_END,  KC_RSFT,  KC_NO  , KC_PGUP,  KC_INS,    \
      KC_LCTL, KC_LGUI, KC_LALT,                    KC_BSPC,KC_SPC, KC_DEL,                  KC_RGUI, MO(1),    KC_HOME, KC_PGDOWN,KC_END),
*/
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
