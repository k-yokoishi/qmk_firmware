#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Ecs  |   1  |   2  |   3  |   4  |   5  |  `   |                    |   =  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | NONE |                    |   B  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Space|||||||| Alt  |      |   N  |   M  |   ,  |   .  |   /  | Up   |
   * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
   * | Cmd  |  Alt |  Alt | Cmd  ||||||||LW/EIS|      |  Del |||||||| Bspc |      |RS/KAN|||||||| Cmd  | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT_4key_2u_inner( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,                         KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                        KC_B,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                         KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP, \
    KC_ESC,  KC_LALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,                        KC_BSPC, KC_ENT,  RAISE,   KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  `   |                    |   =  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |                    |   ]  |   ~  |   `  |   [  |   ]  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | NONE |                    |   /  |   +  |   =  |   {  |   }  |   :  |  '   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Space|||||||| Alt  |      |   |  |   -  |   <  |   >  |  Up  | Shift|
   * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
   * | Cmd  |  Alt |  Alt | Cmd  ||||||||LW/EIS|      |  Del |||||||| Bspc |      |RS/KAN|||||||| Cmd  | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT_4key_2u_inner(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_GRV,                         KC_EQL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_TILD, KC_GRV,  KC_LBRC, KC_RBRC, KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                        KC_SLSH, KC_PPLS, KC_EQL,  KC_LCBR, KC_RCBR, KC_COLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                         KC_LALT, KC_UNDS, KC_MINS, KC_LABK, KC_RABK, KC_UP,   KC_RSFT, \
    KC_ESC,  KC_LALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,                        KC_BSPC, KC_ENT,  RAISE,   KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |  `   |                    |   =  |   6  |   7  |   8  | Mute | Vol- | Vol+ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  [   |                    |   ]  |   6  |   7  |   8  |   9  |   0  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | NONE |                    |   B  | Left | Down |  Up  | Right|   ;  |  '   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Space|||||||| Alt  |      |   N  |   M  |   ,  |   .  |   /  | Up   |
   * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
   * | Cmd  |  Alt |  Alt | Cmd  ||||||||LW/EIS|      |  Del |||||||| Bspc |      |RS/KAN|||||||| Cmd  | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT_4key_2u_inner(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,                         KC_EQL,  KC_6,    KC_7,    KC_8,    KC__MUTE, KC__VOLDOWN, KC__VOLUP, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                        KC_B,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                         KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP, \
    KC_ESC,  KC_LALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,                        KC_BSPC, KC_ENT,  RAISE,   KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|WhlDwn|WhlUp |      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|RClick|LClick|      |                    |      |Msleft|MsDown| MsUp |MsRght|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT_4key_2u_inner(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, KC_WH_D, KC_WH_U, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, KC_BTN2, KC_BTN1, BL_DEC ,_______,                       _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool lower_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed){
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed){
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed){
        lower_pressed = false;
      }
      break;
  }
  return true;
}
