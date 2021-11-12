// qmk compile -kb keebio/iris/rev5 -km DeanMurray77
// File location: /Users/deanmurray/qmk_firmware/keebio_iris_rev5_DeanMurray77.hex

#include QMK_KEYBOARD_H

#define _ALPHA 0
#define _PROGRAMMING 1
#define _NUMBERS 2
#define _MEDIA 3
#define _GAMING 4

enum custom_keycodes {
  ALPHA = SAFE_RANGE,
  PROGRAMMING,
  NUMBERS,
  MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA] = LAYOUT(
  //┌─────────────┬────────┬─────────────┬─────────────┬─────────────┬────────┐                       ┌────────┬─────────────┬─────────────┬─────────────┬────────┬─────────────┐
     KC_NO,        KC_1,    KC_2,         KC_3,         KC_4,         KC_5,                            KC_6,    KC_7,         KC_8,         KC_9,         KC_0,    KC_NO,
  //├─────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                       ├────────┼─────────────┼─────────────┼─────────────┼────────┼─────────────┤
     KC_TAB,       KC_QUOT, KC_COMM,      KC_DOT,       KC_P,         KC_Y,                            KC_F,    KC_G,         KC_C,         KC_R,         KC_L,    KC_BSPC,
  //├─────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                       ├────────┼─────────────┼─────────────┼─────────────┼────────┼─────────────┤
     KC_EQL,       KC_A,    LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I,                            KC_D,    LGUI_T(KC_H), LALT_T(KC_T), LCTL_T(KC_N), KC_S,    KC_MINS,
  //├─────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼────────┐     ┌────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼─────────────┤
     OSM(MOD_LSFT), KC_SCLN, KC_Q,         KC_J,         KC_K,         KC_X,    KC_VOLD,      KC_VOLU, KC_B,    KC_M,         KC_W,         KC_V,         KC_Z,    OSM(MOD_LSFT),
  //└─────────────┴────────┴─────────────┴─────────────┼────────┬────┴───┬────┴───┬────┘     └───┬────┴───┬────┴───┬────────┬┴─────────────┴─────────────┴────────┴─────────────┘                               
                                                         KC_ESC, KC_ENT,   KC_MPLY,               TO(1),   KC_SPC,   KC_DEL
                                                    // └────────┴────────┴────────┘              └────────┴────────┴────────┘
  ),

  [_PROGRAMMING] = LAYOUT(
  //┌──────────────┬────────┬────────┬─────────────┬─────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬───────────────┐
     KC_NO,         KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼───────────────┤
     KC_TAB,        KC_HOME, KC_PGDN, KC_UP,        KC_PGUP,  KC_END,                         KC_DLR,  KC_MINS, KC_RSFT, KC_PLUS, KC_SLSH, KC_BSPC,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼───────────────┤
     KC_EQL,        KC_GRV,  KC_LEFT, KC_DOWN,      KC_RIGHT, KC_RBRC,                        KC_EXLM, KC_LGUI, KC_RALT, KC_RCTL, KC_BSLS, KC_X,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼───────────────┤
     OSM(MOD_LSFT), KC_LPRN, KC_RPRN, LGUI_T(KC_C), KC_LBRC,  KC_V,    RGB_VAD,      RGB_VAI, KC_PERC, KC_RSFT, KC_AMPR, KC_ASTR, TO(0),   OSM(MOD_LSFT),
  //└──────────────┴────────┴────────┴───┬────────┬┴────────┬┴───────┬┴────────┘    └────────┼────────┼────────┼────────┴────────┴────────┴───────────────┘
                                          KC_ESC,  KC_ENT,   TO(0),                      TO(2),   KC_SPC,  KC_DEL
                                      // └────────┴─────────┴────────┘                  └────────┴────────┴────────┘
  ),

  [_NUMBERS] = LAYOUT(
  //┌──────────────┬────────┬─────────────┬─────────────┬─────────────┬────────┐                      ┌────────┬─────────────┬─────────────┬─────────────┬────────┬──────────────┐
     KC_NO,         KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,                          KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     KC_TAB,        KC_HOME, KC_PGDN,      KC_F2,        KC_PGUP,      KC_END,                         KC_DLR,  KC_MINS,      KC_RSFT,      KC_PLUS,      KC_INS,  KC_BSPC,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     KC_EQL,        KC_6,    LCTL_T(KC_3), LALT_T(KC_1), LGUI_T(KC_2), KC_7,                           KC_9,    LGUI_T(KC_4), LALT_T(KC_0), LCTL_T(KC_5), KC_8,    KC_X,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼────────┐    ┌────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     OSM(MOD_LSFT), KC_NO,   KC_NO,        KC_C,         KC_NO,        KC_V,    KC_NO,        KC_NO,   KC_PERC, KC_RSFT,      KC_NO,        KC_NO,        TO(0),   OSM(MOD_LSFT),
  //└──────────────┴────────┴─────────────┴────────┬────┴───┬────────┬┴────────┴───┬────┘    └───┬────┴───┬────┴───┬────────┬┴─────────────┴─────────────┴────────┴──────────────┘
                                                    KC_ESC,  KC_ENT,  TO(1),                      TO(3),   KC_SPC,  KC_DEL
                                                // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
  ),

  [_MEDIA] = LAYOUT(
  //┌──────┬────────┬──────────────┬──────────────┬───────────────┬────────┐                      ┌────────┬───────────────┬──────────────┬───────────────┬────────┬────────┐
     KC_NO, KC_NO,   KC_NO,         KC_NO,         KC_NO,          KC_NO,                          KC_NO,   KC_NO,          KC_NO,         KC_NO,          KC_NO,   KC_NO,
  //├──────┼────────┼──────────────┼──────────────┼───────────────┼────────┤                      ├────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_NO, KC_WSCH, KC_WBAK,       KC_WFWD,       KC_WREF,        KC_STOP,                        RGB_TOG, RGB_MOD,        RGB_HUI,       RGB_SAI,        RGB_M_P, RGB_M_G,
  //├──────┼────────┼──────────────┼──────────────┼───────────────┼────────┤                      ├────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_F1, KC_F2,   LCTL_T(KC_F3), LALT_T(KC_F4), LGUI_T(KC_F5),  KC_F6,                          KC_F7,   LGUI_T(KC_F8),  LALT_T(KC_F9), LCTL_T(KC_F10), KC_F11,  KC_F12,
  //├──────┼────────┼──────────────┼──────────────┼───────────────┼────────┼────────┐    ┌────────┼────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_NO, KC_NO,   KC_NO,         KC_NO,         KC_NO,          KC_NO,   RGB_VAD,      RGB_VAI, KC_NO,   KC_NO,          KC_NO,         KC_NO,          TO(0),   KC_NO,
  //└──────┴────────┴──────────────┴───┬────────┬─┴──────┬────────┼────────┴───┬────┘    └───┬────┴───┬────┴───┬────────┬──┴──────────────┴───────────────┴────────┴────────┘
                                        KC_ESC,  KC_ENT,  TO(2),                              TO(4),   KC_SPC,  KC_DEL
                                    // └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌──────┬────────┬──────┬──────┬──────┬────────┐                      ┌─────┬─────┬────────┬────────┬────────┬────────┐
     KC_ESC, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,                           KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├──────┼────────┼──────┼──────┼──────┼────────┤                      ├─────┼─────┼────────┼────────┼────────┼────────┤
     KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,                           KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├──────┼────────┼──────┼──────┼──────┼────────┤                      ├─────┼─────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                           KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├──────┼────────┼──────┼──────┼──────┼────────┼────────┐    ┌────────┼─────┼─────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_NO,        KC_NO,   KC_N, KC_M, KC_COMM, KC_DOT,  TO(0),   KC_SLSH,
  //└──────┴────────┴──────┴───┬──┴────┬─┴──────┬─┴───┬────┘    └───┬────┴───┬─┴─────┼────────┼────────┴────────┴────────┘
                                KC_ESC, KC_SPC,  TO(3),                KC_NO, KC_SPC,  KC_DEL
                            // └───────┴────────┴─────┘             └────────┴───────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALPHA:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ALPHA);
      }
      return false;
      break;
    case PROGRAMMING:
      if (record->event.pressed) {
        layer_on(_PROGRAMMING);
        update_tri_layer(_PROGRAMMING, _NUMBERS, _MEDIA);
      } else {
        layer_off(_PROGRAMMING);
        update_tri_layer(_PROGRAMMING, _NUMBERS, _MEDIA);
      }
      return false;
      break;
    case NUMBERS:
      if (record->event.pressed) {
        layer_on(_NUMBERS);
        update_tri_layer(_PROGRAMMING, _NUMBERS, _MEDIA);
      } else {
        layer_off(_NUMBERS);
        update_tri_layer(_PROGRAMMING, _NUMBERS, _MEDIA);
      }
      return false;
      break;
    case MEDIA:
      if (record->event.pressed) {
        layer_on(_MEDIA);
      } else {
        layer_off(_MEDIA);
      }
      return false;
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
