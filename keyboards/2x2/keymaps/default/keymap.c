#include QMK_KEYBOARD_H
//#include "quantum.h"

#define KC_TS LCA(KC_L)
#define KC_DIC LCA(KC_K)

enum layer_names {
  _MAIN,
  _FN1,
  _FN2,
  _FN3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
    LT(_FN1, KC_1),  KC_2, 
    KC_3,     KC_4
  ),

  [_FN1] = LAYOUT(
    KC_TRNS,        KC_6,
    KC_7,      RESET 
  ),
  [_FN2] = LAYOUT(
    KC_NO,        KC_NO,
    KC_NO,      KC_NO 
  ),
  [_FN3] = LAYOUT(
    KC_NO,        KC_NO,
    KC_NO,      KC_NO
  ),

};







