void leader_start_user(void) {
    // TODO: Add a LED indicator (blinking) when leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_Z, KC_Z)) {
        // Leader, z, z => Ctrl+s
        SEND_STRING("Testing Successful!");

    // Obsidian Shortcuts ====================================================
    } else if (leader_sequence_three_keys(KC_O, KC_O, KC_S)) {
        // Leader, o, o, s => MEH+s
        tap_code16(MEH(KC_S));
    } else if (leader_sequence_three_keys(KC_O, KC_O, KC_O)) {
        // Leader, o, o, o => MEH+o
        tap_code16(MEH(KC_O)); 
    } else if (leader_sequence_three_keys(KC_O, KC_O, KC_P)) {
        // Leader, o, o, p => MEH+p
        tap_code16(MEH(KC_P));

    } else if (leader_sequence_three_keys(KC_O, KC_H, KC_H)) {
        // Leader, o, h, h => MEH+h
        tap_code16(MEH(KC_H));
    
    } else if (leader_sequence_three_keys(KC_O, KC_T, KC_E)) {
        // Leader, o, t, e => MEH+e
        tap_code16(MEH(KC_E));
    } else if (leader_sequence_three_keys(KC_O, KC_T, KC_T)) {
        // Leader, o, t, t => MEH+t
        tap_code16(MEH(KC_T));
    }

}