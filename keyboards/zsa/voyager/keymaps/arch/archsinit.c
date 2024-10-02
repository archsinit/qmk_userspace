/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "user_keycodes.c"
#include "rgb_matrix.c"
#include "features/sm_td.h"
#include "features/sm_td_user.c"
#include "features/custom_shift_keys.h"
#include "features/custom_shift_keys_user.c"
#include "features/alternate_repeat.c"

//TODO: alt repeat key

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_ctrl_tab_active = false; 
uint16_t ctrl_tab_timer = 0; 

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  if (!process_smtd(keycode, record)) { return false; }

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

    /* Macro for Alternate Repeat Key ===========================*/
    case M_SPC: SEND_STRING(/* */"the"); break;
    /*===========================================================*/
  }

  return true;

}

void matrix_scan_user(void) { 
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