#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_all(
    RGB_HUD, RGB_HUI, RGB_MOD, RGB_TOG,   KC_O,       \
    RGB_SAI,                          KC_I,   KC_P,   \
    RGB_SAD,      KC_A, KC_S,     KC_U,    KC_L,      \
    RGB_VAI,                KC_D,     KC_K,   KC_SCLN,\
    RGB_VAD,                      KC_J,               \
                               KC_W)
};
