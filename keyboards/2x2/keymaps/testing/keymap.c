#include QMK_KEYBOARD_H

enum layer_names {
  _MAIN,
  _FN1,
  
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

};



#define KC_TS LCA(KC_L)
#define KC_DIC LCA(KC_K)

typedef struct{
  bool is_press_action;
  uint8_t state;
} tap;

enum{
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP
};


enum custom_keycodes {
  UNEQL = SAFE_RANGE,
};

enum {
  TD_M5,
  TD_M3,
  TD_M4,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case UNEQL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LSFT("1")SS_LSFT("0"));
            
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

void td_equal(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count==1){
    SEND_STRING(SS_LSFT("0"));
    reset_tap_dance(state);
  }
  else{
    SEND_STRING(SS_LSFT("1")SS_LSFT("0"));
    reset_tap_dance(state);
  }
}

void td_great_less(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count==1){
    SEND_STRING(SS_LSFT(","));
    reset_tap_dance(state);
  }
  else{
    SEND_STRING(SS_LSFT("."));
    reset_tap_dance(state);
  }
}

uint8_t cur_dance(qk_tap_dance_state_t *state){
  if (state->count==1){
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }else if (state->count==2){
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if(state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  } else return 8;
}

static tap xtap_state={
  .is_press_action =true,
  .state=0
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state=cur_dance(state);
  switch(xtap_state.state){
    case SINGLE_TAP: SEND_STRING(SS_LSFT("0")); break;
    case SINGLE_HOLD: layer_off(_MAIN); layer_on(_FN1);break;
    case DOUBLE_TAP: SEND_STRING(SS_LSFT("1")SS_LSFT("0")); break;
    case DOUBLE_HOLD: break;
  }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state){
    case SINGLE_TAP: break;
    case SINGLE_HOLD: layer_off(_FN1); layer_on(_MAIN); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: break;
  }
  xtap_state.state=0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_M5]=ACTION_TAP_DANCE_FN(td_equal),
  [TD_M4]=ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished,x_reset),
  [TD_M3]=ACTION_TAP_DANCE_DOUBLE(KC_1,KC_2),
};





