#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NAV,
  _FN,
  _MENU,
};

#define L_LWR MO(_LOWER)
#define L_RSE MO(_RAISE)
#define L_NAV MO(_NAV)
#define L_FN MO(_FN)
#define L_MNU MO(_MENU)

#define LNV(num) LALT(KC_##num)
#define RNV(num) LGUI(KC_##num)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
KC_ESC,  KC_HOME, KC_END,  KC_INS,  KC_PGDN, KC_PGUP,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RALT,
KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                           KC_LGUI, KC_LALT, L_LWR,   KC_SPC,  L_NAV,   L_RSE,   L_FN,    L_MNU
),

[_LOWER] = LAYOUT(
KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, KC_1,    KC_2,    KC_3,    KC_0,    _______,                   _______, _______, _______, _______, _______, _______,
_______, KC_4,    KC_5,    KC_6,    _______, _______,                   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
_______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
KC_TILD, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
_______, _______, _______, _______, _______, _______,                   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, LNV(1),  LNV(2),  LNV(3),  _______, _______,                   _______, _______, RNV(1),  RNV(2),  RNV(3),  _______,
_______, LNV(4),  LNV(5),  LNV(6),  _______, _______,                   _______, _______, RNV(4),  RNV(5),  RNV(6),  _______,
_______, LNV(7),  LNV(8),  LNV(9),  _______, _______, _______, _______, _______, _______, RNV(7),  RNV(8),  RNV(9),  _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
),

[_FN] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, KC_F1,   KC_F2,   KC_F3,   _______, _______,                   _______, _______, KC_F7,   KC_F8,   KC_F9,   _______,
_______, KC_F4,   KC_F5,   KC_F6,   _______, _______,                   _______, _______, KC_F10,  KC_F11,  KC_F12,  _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
),

[_MENU] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, QK_RBT,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
                           _______, _______, _______, _______, _______, _______, _______, _______
)
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
