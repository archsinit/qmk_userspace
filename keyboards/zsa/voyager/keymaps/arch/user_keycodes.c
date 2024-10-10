/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

// Layers
enum layers {
    _MAIN = 0,
    _QWERTY,
    _EXTEND,
    _EXTEND2,
};

// Custom Keycodes
enum custom_keycodes {
  C_STAB = SAFE_RANGE,
  C_SWIN,

  SMTD_KEYCODES_BEGIN, /*======================================*/
  CK_9,
  CK_0,
  CK_SLS,
  CK_BKS,
  SMTD_KEYCODES_END, /*========================================*/

  /* Macro for Alternate Repeat Key ===========================*/
  M_SPC,
  /*===========================================================*/
}; 

// One Shot Modifiers
#define O_SFT OSM(MOD_LSFT)             
#define O_CTL OSM(MOD_LCTL)
#define O_ALT OSM(MOD_LALT)
#define O_GUI OSM(MOD_LGUI)
#define O_MEH OSM(MOD_MEH)
#define O_HYP OSM(MOD_HYPR)

// Layer Change
#define L_MAI TO(_MAIN)
#define L_QWE TO(_QWERTY)
#define L_EXT MO(_EXTEND)
#define L_EX2 OSL(_EXTEND2)

// Miscellaneous
#define C_ZMI LCTL(KC_MS_WH_UP) 
#define C_ZMO LCTL(KC_MS_WH_DOWN) 
#define C_UND LCTL(KC_Z) 
#define C_CUT LCTL(KC_X)
#define C_CPY LCTL(KC_C)
#define C_PST LCTL(KC_V)
#define C_LNG LGUI(KC_SPC)