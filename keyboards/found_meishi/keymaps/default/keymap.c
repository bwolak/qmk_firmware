#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _NUM 1


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    TO(1),  KC_A,  KC_B, KC_C \
  ),
  [_NUM] = LAYOUT(
    TO(0),  KC_1,  KC_2, KC_3 \
  )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default\n"), false);
            oled_write_ln_P(PSTR("A    B    C"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("FN\n"), false);
            oled_write_ln_P(PSTR("1    2    3"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

}
#endif
