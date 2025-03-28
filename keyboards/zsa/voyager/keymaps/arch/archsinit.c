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

    case M_JIGG:
      if (record->event.pressed) {
        static deferred_token token = INVALID_DEFERRED_TOKEN;
        static report_mouse_t report = {0};
        if (token) {
          // If jiggler is currently running, stop when any key is pressed.
          cancel_deferred_exec(token);
          token = INVALID_DEFERRED_TOKEN;
          report = (report_mouse_t){};  // Clear the mouse.
          host_mouse_send(&report);
        } else if (keycode == M_JIGG) {

          uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
            // Deltas to move in a circle of radius 20 pixels over 32 frames.
            static const int8_t deltas[32] = {
                0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
                0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
            static uint8_t phase = 0;
            // Get x delta from table and y delta by rotating a quarter cycle.
            report.x = deltas[phase];
            report.y = deltas[(phase + 8) & 31];
            phase = (phase + 1) & 31;
            host_mouse_send(&report);
            return 16;  // Call the callback every 16 ms.
          }

          token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback.
        }
      }

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