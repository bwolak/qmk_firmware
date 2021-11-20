#include QMK_KEYBOARD_H

#define _DIVVY 0
#define _NADA 1

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

// Tap Dance declarations
enum {
    TD_LEFT,
    TD_MIDDLE,
    TD_RIGHT,
};

// Tap Dance actions
void left_key(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LCTL(KC_P1));
    } else if (state->count == 2) {
        tap_code16(LCTL(KC_P4));
    } else if (state->count == 3) {
        tap_code16(LCTL(KC_P7));
    }
}

void middle_key(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LCTL(KC_P2));
    } else if (state->count == 2) {
        tap_code16(LCTL(KC_P5));
    } else if (state->count == 3) {
        tap_code16(LCTL(KC_P8));
    }
}

void right_key(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LCTL(KC_P3));
    } else if (state->count == 2) {
        tap_code16(LCTL(KC_P6));
    } else if (state->count == 3) {
        tap_code16(LCTL(KC_P9));
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LEFT] = ACTION_TAP_DANCE_FN(left_key),
    [TD_MIDDLE] = ACTION_TAP_DANCE_FN(middle_key),
    [TD_RIGHT] = ACTION_TAP_DANCE_FN(right_key),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DIVVY] = LAYOUT(
    TO(_NADA), TD(TD_LEFT), TD(TD_MIDDLE), TD(TD_RIGHT)
  ),
  [_NADA] = LAYOUT( 
    TO(_DIVVY), KC_N,  KC_I, KC_L
  )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _DIVVY:
            oled_write_ln_P(PSTR("Divvy\n"), false);
            oled_write_ln_P(PSTR("Left   Middle   Right"), false);
            break;
        case _NADA:
          oled_write_ln_P(PSTR("That key doesn't"), false);
          oled_write_ln_P(PSTR("do anything  :(\n\n"), false);
          break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined\n\n\n\n\n"), false);
    }

}
#endif
