// Copyright 2021-22 Will McGLoughlin (wymcg)
// SPDX-License-Identifier: GPL-2.0-or-later
// Customized Pluto12 macropad layout.

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO,      KC_MPLY,     KC_MNXT,     KC_MUTE,
        KC_F13,     C(KC_ENT),   A(KC_TAB),  KC_F14,
        C(KC_C),    C(KC_V),     C(KC_A),    KC_F15
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
    return false;
}
