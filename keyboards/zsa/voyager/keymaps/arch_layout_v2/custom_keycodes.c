/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

// Here are my keycode definitions and custom keycodes. 

// Normal Mode Keycodes
#define C_EXT LALT(KC_F4)               // Alt-F4 : Exit Application
#define C_CLS LCTL(KC_W)                // Ctrl-w : Close Window/Tab
#define C_BCK LALT(KC_LEFT)             // Alt-Left : Go Back
#define C_FWD LALT(KC_RIGHT)            // Alt-Right : Go Forward
#define C_UND LCTL(KC_Z)                // Ctrl-z : Undo
#define C_CUT LCTL(KC_X)                // Ctrl-x : Cut
#define C_CPY LCTL(KC_C)                // Ctrl-z : Copy
#define C_PST LCTL(KC_V)                // Ctrl-z : Paste
#define C_LNG LGUI(KC_SPC)              // GUI-Space : Switch Input Language
#define C_WPR LCTL(KC_LEFT)             // Ctrl-Left : Move Back One Word
#define C_WNX LCTL(KC_RIGHT)            // Ctrl-Right : Move Forward One Word
#define C_EOP LCTL(KC_END)              // Ctrl-End : Move End of Page
#define C_BOP LCTL(KC_HOME)             // Ctrl-Home : Move Beginning of Page
#define C_SLB LSFT(KC_HOME)             // Shift-Home : Select to Beginning of Line
#define C_SLE LSFT(KC_END)              // Shift-End : Select to End of Page
#define C_SLP LSFT(LCTL(KC_LEFT))       // Shift-Ctrl-Left : Select Prior Word
#define C_SLN LSFT(LCTL(KC_RIGHT))      // Shift-Ctrl-Right : Select Next Word

// Shift Normal Mode
#define C_ZMI LCTL(KC_MS_WH_UP)         // Ctrl-Wheel Up : Zoom In
#define C_ZMO LCTL(KC_MS_WH_DOWN)       // Ctrl-Wheel Down : Zoom Out

// Layer Changes
#define L_NOR TO(_NORMAL)               // Change Layer to _NORMAL
#define L_STY TO(_STURDY)               // Change Layer to _STURDY
#define L_INS TO(_INSERT)               // Change Layer to _INSERT
#define L_SFT MO(_SHIFT)                // Change Layer to _SHIFT
#define L_CAL MO(_CALLUM)              // Change Layer to _CALLUM

// One Shot Modifiers
#define O_SFT OSM(MOD_LSFT)             
#define O_CTL OSM(MOD_LCTL)
#define O_ALT OSM(MOD_LALT)
#define O_GUI OSM(MOD_LGUI)
#define O_MEH OSM(MOD_MEH)
#define O_HYP OSM(MOD_HYPR)

enum custom_keycodes {
  C_STAB = SAFE_RANGE,                  // Ctrl-Tab : Switch Tab And Hold Ctrl 
  C_SWIN,                               // Alt-Tab : Switch Windows And Hold Alt
  C_ADDL,                               // Adds a new line below cursor
                                        //     and places cursor on new line
  C_ADLA,                               // Add a new line above (same as above)
  C_SCTL,                               // Select current line and hold shift
  C_SCTW,                               // Select current word and hold shift
  C_WPRI,                               // Move cursor to start of prior word
  C_WNXT,                               // Move cursor to start of next word
  C_DELL,                               // Delete current line
  C_DELW,                               // Delete current word
  C_CLRM,                               // Clear all mods and switch to normal
}; 