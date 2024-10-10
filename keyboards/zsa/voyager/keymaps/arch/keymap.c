/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include QMK_KEYBOARD_H

#include "archsinit.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
        C_SWIN,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    CK_9,    CK_0,    KC_EQL,
        QK_GESC, KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                         KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    KC_SCLN,
        CK_BKS,  KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                         KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    KC_COMM,
        KC_TAB,  KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P,    KC_DOT,  KC_MINS, CK_SLS,  KC_ENT,
                                                     KC_SPC,  L_EXT,      QK_AREP, O_SFT
    ),

    [_QWERTY] = LAYOUT(
        C_SWIN,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    CK_9,    CK_0,    KC_EQL,
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        CK_BKS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  CK_SLS,  KC_ENT,
                                                     KC_SPC,  L_EXT,      QK_AREP, O_SFT
    ),

    [_EXTEND] = LAYOUT(
        C_STAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_PSCR, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, C_ZMI,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,
        XXXXXXX, O_SFT,   O_GUI,   O_ALT,   O_CTL,   C_ZMO,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_RALT,
        XXXXXXX, C_UND,   C_CUT,   C_CPY,   C_PST,   L_EX2,                        L_QWE,   O_CTL,   O_ALT,   O_GUI,   O_SFT,   C_LNG,
                                                     XXXXXXX, _______,    L_MAI,   XXXXXXX
    ),
    
    [_EXTEND2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_H,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),

};  