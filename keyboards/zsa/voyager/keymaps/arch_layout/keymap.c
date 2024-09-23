/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include QMK_KEYBOARD_H
#include "features/select_word.h"

enum layers {
    _ALPHA = 0,
    _ALT = 1,
    _CALLUM = 2,
    _NUMPAD = 3,
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  ADDLINE,
};

#define O_SHIFT OSM(MOD_LSFT)
#define O_GUI OSM(MOD_LGUI)
#define O_ALT OSM(MOD_LALT)
#define O_CTRL OSM(MOD_LCTL)

#define MO_CALL MO(_CALLUM)
#define TO_ALPH TO(_ALPHA)
#define TO_ALT TO(_ALT)
#define TO_NUM TO(_NUMPAD)

#define ALT_F4 LALT(KC_F4)
#define GUI_SPC LGUI(KC_SPC)
#define ZM_IN LCTL(KC_MS_WH_UP)
#define ZM_OUT LCTL(KC_MS_WH_DOWN)

#define CU_COPY LCTL(KC_C)
#define CU_PSTE LCTL(KC_V)
#define CU_UNDO LCTL(KC_Z)
#define CU_CUT LCTL(KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALT] = LAYOUT(
        KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_QUOT, KC_V,    KC_M,    KC_L,    KC_C,    KC_P,                         KC_B,    QK_AREP, KC_U,    KC_O,    KC_Q,    KC_SCLN,
        QK_GESC, KC_S,    KC_T,    KC_R,    KC_D,    KC_Y,                         KC_F,    KC_N,    KC_E,    KC_A,    KC_I,    KC_BSPC,
        KC_TAB,  KC_X,    KC_K,    KC_J,    KC_G,    KC_W,                         KC_Z,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                                     O_SHIFT, MO_CALL,    QK_REP,  KC_SPC
    ),
    [_ALPHA] = LAYOUT(
        KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_QUOT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN,
        QK_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    QK_AREP, KC_BSPC,
        KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                                     O_SHIFT, MO_CALL,    QK_REP,  KC_SPC
    ),
    [_CALLUM] = LAYOUT(
        ALT_F4,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_BSPC, KC_ENT,  KC_BSLS, KC_LBRC, KC_RBRC, ZM_IN,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,
        QK_GESC, O_SHIFT, O_GUI,   O_ALT,   O_CTRL,  ZM_OUT,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
        KC_TAB,  CU_UNDO, CU_CUT,  CU_COPY, CU_PSTE, KC_SPC,                       ADDLINE, SELWORD, KC_PSCR, GUI_SPC, KC_RALT, KC_ENT,
                                                     TO_ALPH, _______,    TO_NUM,  QK_LLCK
    ),
    [_NUMPAD] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO_ALT,                       KC_LABK, KC_LPRN, KC_RPRN, KC_RABK, KC_NUM,  KC_EQL,
        KC_BSPC, KC_ENT,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                      KC_COLN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, 
        QK_GESC, O_CTRL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSPC,
        KC_TAB,  CU_UNDO, XXXXXXX, ADDLINE, SELWORD, KC_SPC,                       KC_DOT,  KC_1,    KC_2,    KC_3,    KC_PLUS, KC_ENT,
                                                     O_SHIFT, TO_ALPH,    KC_0,    KC_SPC
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }

  switch (keycode) {
    case ADDLINE:  
      if (record->event.pressed) {
        const uint8_t mods = get_mods();
        const uint8_t oneshot_mods = get_oneshot_mods();

        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) { 
          del_oneshot_mods(MOD_MASK_SHIFT);
          unregister_mods(MOD_MASK_SHIFT);  
          SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_ENTER));
          register_mods(mods);
        } else {
          SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
        }
      }
      return false;
    }

  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}