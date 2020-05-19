#pragma once

#include "quantum.h"

enum keycodes {
    HC_DESK1,
    HC_DESK2,
    HC_DESK3,
    HC_DESK4,

    HC_MORSE,

};

#define HC_SPCFN1 LT(1, KC_SPC)
#define HC_SPCFN2 LT(2, KC_SPC)
#define HC_BSPCFN1 LT(1, KC_BSPC)
#define HC_BSPCFN2 LT(2, KC_BSPC)

#define HC_DSKL LCTL(LGUI(KC_LEFT))
#define HC_DSKR LCTL(LGUI(KC_RIGHT))