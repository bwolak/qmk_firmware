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
#include "v1x_right.h"

void keyboard_pre_init_kb(void) {
    // Set LED IO as outputs
    setPinOutput(LED_00);
    setPinOutput(LED_01);
    setPinOutput(LED_02);
    keyboard_pre_init_user();
}

void shutdown_user() {
    // Shutdown LEDs
    writePinLow(LED_00);
    writePinLow(LED_01);
    writePinLow(LED_02);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    // Layer LEDs act as binary indication of current layer
    uint8_t layer = biton32(state);
    writePin(LED_00, layer & 0b1);
    writePin(LED_01, (layer >> 1) & 0b1);
    return layer_state_set_user(state);
}

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    uint8_t led_delay_ms = 80;
    for (int i = 0; i < 2; i++) {
        writePinHigh(LED_00);
        writePinHigh(LED_01);
        writePinHigh(LED_02);
        wait_ms(led_delay_ms);
        writePinLow(LED_00);
        writePinLow(LED_01);
        writePinLow(LED_02);
        if (i < 1) {
            wait_ms(led_delay_ms);
        }
    }

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)
    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware
    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    writePin(LED_02, !IS_LED_ON(usb_led, USB_LED_NUM_LOCK));
    led_set_user(usb_led);
}
