/* Copyright 2020 imchipwood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _BASE 0
#define _SUB  1

enum custom_keycodes {
    RUBYPRY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER
    /-----------------------------------------------------`
    |             |    7    |    8    |    9    |  Bkspc  |
    |             |---------|---------|---------|---------|
    |             |    4    |    5    |    6    |   Esc   |
    |             |---------|---------|---------|---------|
    |             |    1    |    2    |    3    |   Tab   |
    |-------------|---------|---------|---------|---------|
    | Left mouse  | TT(SUB) |    0    |    .    |  Enter  |
    \-----------------------------------------------------'
    */
    [_BASE] = LAYOUT(
                    KC_0,          KC_0,           KC_0,            RUBYPRY,
                    LCTL(KC_P7),   LCTL(KC_P8),    LCTL(KC_P9),     KC_BSPC,
                    LCTL(KC_P4),   LCTL(KC_P5),    LCTL(KC_P6),     KC_ESC,
        KC_BTN1,    LCTL(KC_P1),   LCTL(KC_P2),    LCTL(KC_P3),     TT(_SUB)    
    ),
    /*
            SUB LAYER
    /-----------------------------------------------------`
    |             |         |         |         |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    +    |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    -    |
    |-------------|---------|---------|---------|---------|
    |    LOCK     |         |         |         |    =    |
    \-----------------------------------------------------'
    */
    [_SUB] = LAYOUT(
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        KC_LOCK,    _______,     _______,     _______,      _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
/*
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
*/
    switch (keycode) {
    case RUBYPRY:
        if (record->event.pressed) {
            // when keycode RUBYPRY is pressed
            SEND_STRING("require 'pry'; binding.pry");
        } else {
            // when keycode RUBYPRY is released
        }
        break;
    }

    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    //debug_enable = true;
    //debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
    /*  Custom encoder control - handles CW/CCW turning of encoder
     *  Default behavior:
     *    main layer:
     *       CW: move mouse right
     *      CCW: move mouse left
     *    other layers:
     *       CW: = (equals/plus - increase slider in Adobe products)
     *      CCW: - (minus/underscore - decrease slider in adobe products)
     */
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _BASE:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

            default:
                // other layers - =/+ (quals/plus) (CW) and -/_ (minus/underscore) (CCW)
                if (clockwise) {
                    tap_code16(SGUI(KC_Z));
                } else {
                    tap_code16(LGUI(KC_Z));
                }
                break;
        }
    }
}
