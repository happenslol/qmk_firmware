#include QMK_KEYBOARD_H
#include "joystick.h"

enum axis_keycodes {
    JS_UP = SAFE_RANGE,
    JS_DWN,
    JS_LFT,
    JS_RGT
};

#define JS_0 JS_BUTTON7
#define JS_1 JS_BUTTON0
#define JS_2 JS_BUTTON1
#define JS_3 JS_BUTTON2
#define JS_4 JS_BUTTON3
#define JS_5 JS_BUTTON4
#define JS_6 JS_BUTTON5
#define JS_7 JS_BUTTON6
#define JS_8 JS_BUTTON15
#define JS_9 JS_BUTTON8
#define JS_A JS_BUTTON9
#define JS_B JS_BUTTON10
#define JS_C JS_BUTTON11
#define JS_D JS_BUTTON12
#define JS_E JS_BUTTON13
#define JS_F JS_BUTTON14

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_all(
      JS_8, JS_9, JS_A, JS_B,          JS_2,       \
      JS_C,                        JS_1,    JS_3,  \
      JS_D,  JS_LFT, JS_DWN,  JS_0,    JS_6,       \
      JS_E,             JS_RGT,    JS_5,    JS_7,  \
      JS_F,                   JS_4,                \
                            JS_UP)
};

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

static uint8_t direction_state = 0;

enum direction {
    Up = 1,
    Left = 2,
    Down = 4,
    Right = 8
};

static inline void update_direction_state(uint8_t dir, bool state) {
    if (state) direction_state |= dir;
    else direction_state &= ~dir;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case JS_UP:
            update_direction_state(Up, record->event.pressed);
            joystick_status.status |= JS_UPDATED;
            break;
        case JS_DWN:
            update_direction_state(Down, record->event.pressed);
            joystick_status.status |= JS_UPDATED;
            break;
        case JS_LFT:
            update_direction_state(Left, record->event.pressed);
            joystick_status.status |= JS_UPDATED;
            break;
        case JS_RGT:
            update_direction_state(Right, record->event.pressed);
            joystick_status.status |= JS_UPDATED;
            break;
    }

    joystick_status.axes[0] =
        (direction_state >> 1 & 1) * 127 + // Left
        (direction_state >> 3 & 1) * -127; // Right

    joystick_status.axes[1] =
        (direction_state >> 0 & 1) * 127 + // Up
        (direction_state >> 2 & 1) * -127; // Down

    return true;
}
