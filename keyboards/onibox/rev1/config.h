/*
Copyright 2019 Rodrigo Feijao <hello@rodrigofeijao.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3042 // 0niBox
#define PRODUCT_ID      0x5231 // R1
#define DEVICE_VER      0x0001
#define MANUFACTURER    ONIBOX
#define PRODUCT         REV1

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { D0, D1, D4, D7, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7 }
#define UNUSED_PINS { D3, D2, E6, B4, B5, B0, B7, D5, C7, F1, F0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 2

/* RGB Underglow */
#define RGB_DI_PIN B6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

/* Joystick config */
#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXES_COUNT 2
