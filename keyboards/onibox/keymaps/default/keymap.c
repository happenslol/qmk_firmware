#include QMK_KEYBOARD_H

#define OB_UP    KC_W
#define OB_DOWN  KC_S
#define OB_LEFT  KC_A
#define OB_RIGHT KC_D

#define OB_PUNCH KC_J
#define OB_KICK  KC_U
#define OB_SLASH KC_I
#define OB_HEAVY KC_K
#define OB_DUST  KC_O
#define OB_DASH  KC_Q
#define OB_RC    KC_M
#define OB_TAUNT KC_N
#define OB_RESET KC_SPACE
#define OB_PAUSE KC_ENTER
#define OB_PLAY  KC_COMMA
#define OB_REC   KC_DOT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
    KC_NO, OB_REC, OB_PLAY, OB_PAUSE, KC_NO, \
    KC_NO, OB_TAUNT, OB_RESET, OB_LEFT, OB_DOWN, \
    OB_RIGHT, OB_UP, OB_KICK, OB_DUST, OB_RC, \
    KC_NO, OB_PUNCH, OB_SLASH, OB_HEAVY, OB_DASH \
  )
};
