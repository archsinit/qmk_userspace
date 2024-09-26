/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

// Here are my leader shortcuts. 

void leader_start_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_Z, KC_Z)) {
        // leader z z => Reset leader state

    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        
    }
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
}