// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "encoder.h"

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _FN,
    _MENU,
    _NAV,
};

#define L_LWR MO(_LOWER)
#define L_RSE MO(_RAISE)
#define L_FN MO(_FN)
#define L_MENU MO(_MENU)
#define L_NAV MO(_NAV)

// template
// [_LAYER] = LAYOUT(
//   _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
//                               _______, _______, _______, _______,   _______, _______, _______, _______
// ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_ESC,   KC_HOME, KC_END,  KC_INS,  KC_PGDN, KC_PGUP,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RALT,
  KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,    KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                              KC_LGUI, KC_LALT, L_LWR,   KC_SPC,    L_NAV,   L_RSE,   L_FN,    L_MENU
),

[_LOWER] = LAYOUT(
  KC_GRV,   _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_1,    KC_2,    KC_3,    KC_0,    _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_4,    KC_5,    KC_6,    _______, _______,                     _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______,  KC_7,    KC_8,    KC_9,    _______, _______, KC_MUTE,   _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,   _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  KC_TILD,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_DEL,
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______,  _______, _______, _______, _______, _______,                     _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,   _______, _______, _______, _______
),

[_FN] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_F1,   KC_F2,   KC_F3,   _______, _______,                     _______, _______, KC_F4,   KC_F5,   KC_F6,   _______,
  _______,  KC_F7,   KC_F8,   KC_F9,   _______, _______,                     _______, _______, KC_F10,  KC_F11,  KC_F12,  _______,
  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,   _______, _______, _______, _______
),

[_MENU] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     RGB_VAD, RGB_VAI, _______, _______, _______, _______,
  _______,  RGB_M_P, RGB_M_B, RGB_M_SW,_______, _______,                     RGB_HUD, RGB_HUI, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______,                     RGB_SAD, RGB_SAI, _______, _______, _______, _______,
  QK_BOOT,  _______, _______, _______, _______, _______, RGB_TOG,   _______, RGB_RMOD,RGB_MOD, _______, _______, _______, _______,
                              _______, _______, _______, _______,   _______, _______, _______, _______
),

[_NAV] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  A(KC_1), A(KC_2), A(KC_3), _______, _______,                     _______, _______, G(KC_1), G(KC_2), G(KC_3), _______,
  _______,  A(KC_4), A(KC_5), A(KC_6), _______, _______,                     _______, _______, G(KC_4), G(KC_5), G(KC_6), _______,
  _______,  A(KC_7), A(KC_8), A(KC_9), _______, _______, _______,   _______, _______, _______, G(KC_7), G(KC_8), G(KC_9), _______,
                              _______, _______, _______, _______,   _______, _______, _______, _______
)
};

#ifdef ENCODER_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_LOWER] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_FN] =     { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_MENU] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_NAV] =    { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};

#endif

#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_270;
}

void render_logo(void) {
    static const char PROGMEM logo[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x60,
      0x60, 0x60, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
      0x00, 0xe0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x1e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x80, 0xc0,
      0x80, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
      0xe0, 0xc0, 0x80, 0x80, 0xc0, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
      0x00, 0x1f, 0xff, 0xff, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x78, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x01,
      0x01, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0x78, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
      0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _MENU:
            oled_write_P(PSTR("Menu"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Fn"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
