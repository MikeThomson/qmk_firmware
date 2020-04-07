#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    HC_MORSE = SAFE_RANGE,
};

/* Standard arrangement / LAYOUT
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │
 * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬┴───┤
 * │40  │41  │43  │44      │46  │48        │4a  │4b  │4d  │4e  │
 * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┴────┘
*/
#define LAYOUT_halfcent(\
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
    k10, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
    k20, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3e, \
    k40, k41, k43, k44, k46, k48, k4a, k4b, k4d, k4e  \
) { \
    { k00,  k01,   k02,   k03,  k04,  k05,   k06,  k07,   k08,  k09,   k0a,  k0b,  k0c,   k0d,  k0e   }, \
    { k10,  KC_NO, k12,   k13,  k14,  k15,   k16,  k17,   k18,  k19,   k1a,  k1b,  k1c,   k1d,  k1e   }, \
    { k20,  KC_NO, k22,   k23,  k24,  k25,   k26,  k27,   k28,  k29,   k2a,  k2b,  k2c,   k2d,  KC_NO }, \
    { k30,  k31,   k32,   k33,  k34,  k35,   k36,  k37,   k38,  k39,   k3a,  k3b,  KC_NO, k3d,  k3e   }, \
    { k40,  k41,   KC_NO, k43,  k44,  KC_NO, k46,  KC_NO, k48,  KC_NO, k4a,  k4b,  KC_NO,   k4d,  k4e   }  \
}

#define HC_DSK_LEFT LCTL(LGUI(KC_LEFT))
#define HC_DSK_RIGHT LCTL(LGUI(KC_RIGHT))

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

LAYOUT_halfcent(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_HOME, KC_END,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(2),
        KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, MO(1), KC_SPC, KC_RALT, MO(1), KC_APP, KC_RCTL),

LAYOUT_halfcent(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
        _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______,HC_DSK_LEFT, HC_DSK_RIGHT, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______,KC_PGUP, KC_INS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_DEL, _______, _______, _______, _______, MO(3), _______),

LAYOUT_halfcent(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK, KC_PAUS, KC_PSCR,
        _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, HC_MORSE, KC_BTN2, _______, _______, _______, _______),

LAYOUT_halfcent(
        RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

//    LAYOUT_halfcent(
//		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
//		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//
//    LAYOUT_halfcent(
//		KC_TRNS, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//

};

typedef struct MorseDefinition {
    char const taps[8];
    char const letter[2];
} MorseDefinition;

#define HC_MORSE_MAP_LENGTH 43

const MorseDefinition hc_morseMap[HC_MORSE_MAP_LENGTH] = {
    {".-", "A"},
    {"-...", "B"},
    {"-.-.", "C"},
    {"-..", "D"},
    {".", "E"},
    {"..-.", "F"},
    {"--.", "G"},
    {"....", "H"},
    {"..", "I"},
    {".---", "J"},
    {"-.-", "K"},
    {".-..", "L"},
    {"--", "M"},
    {"-.", "N"},
    {"---", "O"},
    {".--.", "P"},
    {"--.-", "Q"},
    {".-.", "R"},
    {"...", "S"},
    {"-", "T"},
    {"..-", "U"},
    {"...-", "V"},
    {".--", "W"},
    {"-..-", "X"},
    {"-.--", "Y"},
    {"--..", "Z"},
    {".----", "1"},
    {"..---", "2"},
    {"...--", "3"},
    {"....-", "4"},
    {".....", "5"},
    {"-....", "6"},
    {"--...", "7"},
    {"---..", "8"},
    {"----.", "9"},
    {"-----", "0"},
    {"--..--", ","},
    {".-.-.-", "."},
    {"..--..", "?"},
    {"-..-.", "/"},
    {"-....-", "-"},
    {"-.--.", "("},
    {"-.--.-", ")"}
};


uint32_t hc_key_timer;
static char hc_taps[8] = {0};
static int hc_tapIndex = 0;

#define HC_MORSE_DOT_LENGTH 100

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HC_MORSE:
            if (record->event.pressed) {
                hc_key_timer = timer_read32();
            } else {
                if (timer_elapsed32(hc_key_timer) >= 3 * HC_MORSE_DOT_LENGTH) {
                    hc_taps[hc_tapIndex] = '-';
                } else {
                    hc_taps[hc_tapIndex] = '.';
                }
                hc_tapIndex++;
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void matrix_scan_user(void) {
    if (
            hc_tapIndex == 8
            || (hc_tapIndex > 0 && timer_elapsed32(hc_key_timer) >= 3 * HC_MORSE_DOT_LENGTH)
    ) {
        for (int i = 0; i < HC_MORSE_MAP_LENGTH; i++) {
            if (strcmp(hc_taps, hc_morseMap[i].taps) == 0) {
                send_string(hc_morseMap[i].letter);
            }
        }

        hc_tapIndex = 0;
        for (int i = 0; i < 8; i++) hc_taps[i] = '\0';
    }
}


// @TODO basic layout