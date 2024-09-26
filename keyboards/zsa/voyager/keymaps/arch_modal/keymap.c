/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

/* 
 * An attempt on designing a modal keyboard, similar to vim in concept. 
 * Only two modes exists: normal and insert. 
 * Normal mode is used for navigation, selection, and editing. 
 * Insert mode is used for entering. 
 * A callum layer with modifiers and a numpad is available in both modes.
 * Both layers have a shift mode. 
 */

#include QMK_KEYBOARD_H
#include "features/custom_keycodes.c"

enum layers {
    _NORMAL = 0,
    _INSERT,
    _SHIFT,
    _CALLUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NORMAL] = LAYOUT(
        C_EXT,   C_CLS,   C_STAB,  C_SWIN,  KC_N,    KC_Y,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
        KC_BSPC, KC_ENT,  C_BCK,   KC_UP,   C_FWD,   C_ADDL,                       KC_HOME, C_WPRI,  C_WNXT,  KC_END,  KC_INS,  XXXXXXX,
        C_CLRM,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, C_SCTL,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
        KC_TAB,  C_UND,   C_CUT,   C_CPY,   C_PST,   C_SCTW,                       XXXXXXX, XXXXXXX, XXXXXXX, C_LNG,   KC_RALT, KC_ENT,
                                                     L_SFT,   L_CAL,      L_INS,   KC_SPC
    ),
    [_INSERT] = LAYOUT(
        KC_QUOT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
        C_CLRM,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                                     O_SFT,   L_CAL,      QK_LEAD, KC_SPC
    ),
    [_SHIFT] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, C_ZMI,   KC_PGUP, C_ZMO,   C_ADLA,                       C_SLB,   C_SLP,   C_SLN,   C_SLE,    _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END,  C_DELL,                       C_EOP,   KC_PGDN, KC_PGUP, C_BOP,    _______, _______,
        _______, _______, _______, _______, _______, C_DELW,                       _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    [_CALLUM] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
        _______, _______, KC_BSLS, KC_LBRC, KC_RBRC, O_HYP,                        KC_COLN, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, 
        _______, O_SFT,   O_GUI,   O_ALT,   O_CTL,   O_MEH,                        KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_DOT,  KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
                                                     _______, _______,    KC_0,    _______
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

    case C_ADDL: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
      }
      break;

    case C_ADLA: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_ENTER) SS_TAP(X_UP));
      }
      break;

    case C_SCTL: 

    case C_SCTW: 
  
    case C_WPRI: 

    case C_WNXT: 

    case C_DELL: 

    case C_DELW: 

    case C_CLRM:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        layer_move(_NORMAL);
        tap_code16(KC_ESC);
      }
      return false;

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
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            default:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
        }
    }
    return false;
}

