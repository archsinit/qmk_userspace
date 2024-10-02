/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#define SMTD_TAPHOLD(macro_key, key, hold_key)          \
    case macro_key: {                                   \
        switch (action) {                               \
            case SMTD_ACTION_TOUCH:                     \
                break;                                  \
            case SMTD_ACTION_TAP:                       \
                tap_code16(key);                        \
                break;                                  \
            case SMTD_ACTION_HOLD:                      \
                tap_code16(hold_key);                   \
                break;                                  \
            case SMTD_ACTION_RELEASE:                   \
                break;                                  \
        }                                               \
        break;                                          \
    }

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_TAPHOLD(CK_9, KC_9, KC_LBRC)
        SMTD_TAPHOLD(CK_0, KC_0, KC_RBRC)
        SMTD_TAPHOLD(CK_SLS, KC_SLSH, KC_BSLS)
        SMTD_TAPHOLD(CK_BKS, KC_BSPC, C(KC_BSPC))
    }
}