/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUOT , KC_UNDS}, // Shift ' is _
  {KC_MINS, KC_DQT}, // Shift - is "
  {KC_SLSH, KC_LABK}, // Shift / is <
  {KC_COMM, KC_QUES}, // Shift , is ? 
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);