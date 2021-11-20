#include QMK_KEYBOARD_H

#define _VIM 0

enum my_keycodes {
  SAVE_QUIT_VIM = SAFE_RANGE,
  QUIT_VIM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SAVE_QUIT_VIM:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_TAP(X_ESC)":wq"SS_TAP(X_ENT));
        } else {
            // when keycode is released
        }
        break;
    case QUIT_VIM:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC)":q!"SS_TAP(X_ENT));
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_VIM] = LAYOUT( 
    KC_ESC, KC_I, QUIT_VIM, SAVE_QUIT_VIM
  )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  oled_write_P(PSTR("VIM\n\n"), false);
  oled_write_P(PSTR("esc  ins  quit  save+                quit\n"), false);
}
#endif