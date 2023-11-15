#include QMK_KEYBOARD_H

#define _STAGING 0
#define _PROD 1

enum my_keycodes {
  PRIME_STAGING = SAFE_RANGE,
  DATA_STAGING,
  TOOLS_STAGING,
  PRIME_PROD,
  DATA_PROD,
  TOOLS_PROD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_STAGING] = LAYOUT(
    TO(1),  PRIME_STAGING,  DATA_STAGING, TOOLS_STAGING \
  ),
  [_PROD] = LAYOUT(
    TO(0),  PRIME_PROD,  DATA_PROD, TOOLS_PROD \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case PRIME_STAGING:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("kubectx prime-staging"SS_TAP(X_ENT));
        } else {
            // when keycode is released
        }
        break;

      case DATA_STAGING:
        if (record->event.pressed) {
            SEND_STRING("kubectx data-staging"SS_TAP(X_ENT));
        }
        break;

      case TOOLS_STAGING:
        if (record->event.pressed) {
            SEND_STRING("kubectx tools-staging"SS_TAP(X_ENT));
        }
        break;

      case PRIME_PROD:
        if (record->event.pressed) {
            SEND_STRING("kubectx prime-prod"SS_TAP(X_ENT));
        } else {
        }
        break;

      case DATA_PROD:
        if (record->event.pressed) {
            SEND_STRING("kubectx data-prod"SS_TAP(X_ENT));
        }
        break;

      case TOOLS_PROD:
        if (record->event.pressed) {
            SEND_STRING("kubectx tools-prod"SS_TAP(X_ENT));
        }
        break;
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("kubectx: "), false);

    switch (get_highest_layer(layer_state)) {
        case _STAGING:
            oled_write_ln_P(PSTR("STAGING\n"), false);
            oled_write_ln_P(PSTR("Prime   Data   Tools"), false);
            break;
        case _PROD:
            oled_write_ln_P(PSTR("PROD\n"), false);
            oled_write_ln_P(PSTR("Prime   Data   Tools"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

}
#endif
