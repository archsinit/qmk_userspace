/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include QMK_KEYBOARD_H

#include "custom_keycodes.c"
#include "leader.c"

enum layers {
    _QWERTY = 0,
    _CALLUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        C_SWIN,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_QUOT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
        QK_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                                     O_SFT,   L_CAL,      QK_LEAD, KC_SPC
    ),
    [_CALLUM] = LAYOUT(
        C_STAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_BSPC, KC_ENT,  KC_BSLS, KC_LBRC, KC_RBRC, C_ZMI,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,
        QK_GESC, O_SFT,   O_GUI,   O_ALT,   O_CTL,   C_ZMO,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
        KC_TAB,  C_UND,   C_CUT,   C_CPY,   C_PST,   QK_LLCK,                      _______, _______, KC_PSCR, C_LNG,   KC_RALT, KC_ENT,
                                                     KC_SPC,  _______,    _______, _______
    ),
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_ctrl_tab_active = false; 
uint16_t ctrl_tab_timer = 0; 

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

  switch (keycode) {
    case C_STAB:
      if (record->event.pressed) {
        if (!is_ctrl_tab_active) {
          is_ctrl_tab_active = true;
          register_code(KC_LCTL);
        }
        ctrl_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case C_SWIN:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

  }
  
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 400) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_ctrl_tab_active) {
    if (timer_elapsed(ctrl_tab_timer) > 400) {
      unregister_code(KC_LCTL);
      is_ctrl_tab_active = false;
    }
  }
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
        break;
    case _CALLUM:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
        break;
    }
  return state;
}