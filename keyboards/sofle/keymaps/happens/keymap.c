#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
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
//                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
// ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_ESC,   KC_HOME, KC_END,  KC_INS,  KC_PGDN, KC_PGUP,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LALT,
  KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PSCR,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                     KC_LGUI, KC_LGUI, KC_LALT, L_LWR,   KC_ENT,    L_NAV,   L_RSE,   L_FN,    L_MENU,  KC_RCTL
),

[_LOWER] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_1,    KC_2,    KC_3,    KC_0,    _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_4,    KC_5,    KC_6,    _______, _______,                     _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______,  KC_7,    KC_8,    KC_9,    _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_DEL,
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______,  _______, _______, _______, _______, _______,                     _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

[_FN] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_F1,   KC_F2,   KC_F3,   _______, _______,                     _______, _______, KC_F4,   KC_F5,   KC_F6,   _______,
  _______,  KC_F7,   KC_F8,   KC_F9,   _______, _______,                     _______, _______, KC_F10,  KC_F11,  KC_F12,  _______,
  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

[_MENU] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  QK_BOOT,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,  A(KC_1), A(KC_2), A(KC_3), _______, _______,                     _______, _______, G(KC_1), G(KC_2), G(KC_3), _______,
  _______,  A(KC_4), A(KC_5), A(KC_6), _______, _______,                     _______, _______, G(KC_4), G(KC_5), G(KC_6), _______,
  _______,  A(KC_7), A(KC_8), A(KC_9), _______, _______, _______,   _______, _______, _______, G(KC_7), G(KC_8), G(KC_9), _______,
                     _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
)

};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Turn LED off
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    } else if (index == 1) {
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif
