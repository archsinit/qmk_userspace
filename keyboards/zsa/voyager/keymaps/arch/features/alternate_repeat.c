/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_SPC: SEND_STRING(/* */"the "); return KC_TRNS;  // " the"
        case KC_E: return KC_D;  // For "ED" bigram.
        case KC_D: return KC_E;  // For "DE" bigram.
        case KC_C: return KC_E;  // For "CE" bigram.
        case KC_L: return KC_O;  // For "LO" bigram.
        case KC_U: return KC_N;  // For "UN" bigram.
    }

    return KC_TRNS;
}