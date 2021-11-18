// qmk compile -kb keebio/iris/rev5 -km DeanMurray77
// File location: /Users/deanmurray/qmk_firmware/keebio_iris_rev5_DeanMurray77.hex

#include QMK_KEYBOARD_H

#define _ALPHA 0
#define _NAV 1
#define _NUMBERS 2
#define _SUPER_NAV 3
#define _PER_NAV 4
#define _SPREADSHEET 5
#define _GAMING 6
#define _MISC 7

// 4 per_nav, 5 = spreadsheet, 6 = gaming, 7 = MISC

enum custom_keycodes {
  ALPHA = SAFE_RANGE,
  NAV,
  NUMBERS,
  SUPER_NAV,
  OSM_LSFT = OSM(MOD_LSFT),
};

// I've considered leaving c,x,v with hold triggering the command plus each of those keys on the nav layer. I'm taking them off for now because I think it will lead to too much cording
// I can put it back on if that ends up making sense

// Tap Dance declarations
enum {
  TD_COMMA_QUEST,
  TD_1_F1,
  TD_2_F2,
  TD_3_F3,
  TD_4_F4,
  TD_5_F5,
  TD_6_F6,
  TD_7_F7,
  TD_8_F8,
  TD_9_F9,
  TD_0_F10,
  TD_F11_F12,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for comma/<, twice for a question mark
  [TD_COMMA_QUEST] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_QUES),
  [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [TD_F11_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA] = LAYOUT( // 0
  //┌─────────┬────────┬───────────────────┬─────────────┬─────────────┬─────────────┐                       ┌─────┬─────────────┬─────────────┬─────────────┬──────┬──────────┐
     KC_NO,    KC_1,    KC_2,               KC_3,         KC_4,         KC_5,                                 KC_6, KC_7,         KC_8,         KC_9,         KC_0,  KC_NO,
  //├─────────┼────────┼───────────────────┼─────────────┼─────────────┼─────────────┤                       ├─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     KC_TAB,   KC_QUOT, TD(TD_COMMA_QUEST), KC_DOT,       KC_P,         KC_Y,                                 KC_F, KC_G,         KC_C,         KC_R,         KC_L,  KC_BSPC,
  //├─────────┼────────┼───────────────────┼─────────────┼─────────────┼─────────────┤                       ├─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     KC_EQL,   KC_A,    LCTL_T(KC_O),       LALT_T(KC_E), LGUI_T(KC_U), KC_I,                                 KC_D, LGUI_T(KC_H), LALT_T(KC_T), LCTL_T(KC_N), KC_S,  KC_MINS,
  //├─────────┼────────┼───────────────────┼─────────────┼─────────────┼─────────────┼────────┐     ┌────────┼─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     OSM_LSFT, KC_SCLN, KC_Q,               KC_J,         KC_K,         KC_X,         KC_VOLD,       KC_VOLU, KC_B, KC_M,         KC_W,         KC_V,         KC_Z,  OSM_LSFT,
  //└─────────┴────────┴───────────────────┴─────────────┼────────┬────┴───┬────────┬┴────────┘     └───┬────┴───┬─┴──────┬──────┴─┬───────────┴─────────────┴──────┴──────────┘                               
                                                          KC_ESC,  KC_ENT,  OSL(2),               MO(1),   KC_SPC,   KC_DEL
                                                      // └────────┴────────┴────────┘            └────────┴────────┴────────┘
  ), // I still want to get cxv to work such that I can tap for the key and hold for the command plus key version

  [_NAV] = LAYOUT( // 1
  //┌─────────┬────────┬────────┬─────────────┬─────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬──────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_NO,   KC_PGDN, KC_UP,        KC_PGUP,  KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_DEL,  KC_LEFT, KC_DOWN,      KC_RIGHT, KC_NO,                          KC_NO,   KC_LGUI, KC_LSFT, KC_NO,   KC_LCTL, KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_NO,   KC_HOME, KC_NO,        KC_END,    KC_NO,  RGB_VAD,      RGB_VAI, KC_NO,   KC_LALT, KC_LSFT, KC_NO,   KC_NO,   KC_NO,
  //└─────────┴────────┴────────┴───┬────────┬┴────────┬┴───────┬┴────────┘    └────────┼────────┼────────┼────────┴────────┴────────┴──────────┘
                                     KC_NO,   KC_ENT,    KC_DEL,                          KC_NO,   KC_NO,  KC_NO
                                 // └────────┴─────────┴────────┘                       └────────┴────────┴────────┘ // I may end up wanting delete added back in, but on the left hand...
  ),

  [_NUMBERS] = LAYOUT( // 2
  //┌─────────┬────────┬─────────────┬─────────────┬─────────────┬────────┐                      ┌────────┬─────────────┬─────────────┬─────────────┬────────┬──────────┐
     KC_NO,    KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,                          KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────┤
     KC_NO,    KC_HASH, KC_DLR,       KC_LPRN,      KC_RPRN,      KC_PERC,                        KC_CIRC, KC_LCBR,      KC_RCBR,      KC_TILD,      KC_INS,  KC_NO,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────┤
     KC_NO,    KC_6,    KC_3,         KC_1,         KC_2,         KC_7,                           KC_9,    KC_4,         KC_0,         KC_5,         KC_8,    KC_NO,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼────────┐    ┌────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼──────────┤
     KC_NO,    KC_AT,   KC_AMPR,      KC_LBRC,      KC_RBRC,      KC_EXLM, KC_MPLY,      KC_NO,   KC_GRV,  KC_PERC,      KC_ASTR,      KC_PIPE,      KC_NO,   KC_NO,
  //└─────────┴────────┴─────────────┴────────┬────┴───┬────────┬┴───────┬┴────────┘    └───┬────┴───┬────┴───┬────────┬┴─────────────┴─────────────┴────────┴──────────┘
                                               KC_NO,   KC_NO,   TO(3),                     KC_NO,   KC_SLASH, KC_BSLASH
                                           // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
  ),

  [_SUPER_NAV] = LAYOUT( // 3
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                     ┌────────┬────────┬────────┬───────┬────────┬────────┐
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                        TO(0),  TO(0),  TO(0),  TO(0), TO(0),  TO(0),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼───────┼────────┼────────┤
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                        RGB_TOG, RGB_MOD,        RGB_HUI,       RGB_SAI,        RGB_M_P, RGB_M_G,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼───────┼────────┼────────┤
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                        TO(0),  TO(4),  TO(5),  TO(6), TO(7),  TO(0),
  //├────────┼────────┼────────┼────────┼────────┼────────┼───────┐    ┌────────┼────────┼────────┼────────┼───────┼────────┼────────┤
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),      TO(0),  TO(0),  TO(0),  TO(0),  TO(0), TO(0), TO(0),
  //└────────┴────────┴────────┴───┬────┴──┬─────┴──┬─────┴──┬┴───┘    └───┬────┴───┬────┴──┬─────┴─┬──────┴───────┴────────┴────────┘
                                    TO(0), TO(0),  TO(0),                TO(0),   TO(0), TO(0)
                                // └───────┴────────┴────────┘             └────────┴───────┴───────┘
  ),

  [_PER_NAV] = LAYOUT( // 4
  //┌──────────────┬────────┬────────┬─────────────┬─────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬───────────────┐
     KC_NO,         KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼───────────────┤
     KC_TAB,        KC_HOME, KC_PGDN, KC_UP,        KC_PGUP,  KC_END,                         KC_DLR,  KC_MINS, KC_AMPR, KC_PLUS, KC_SLSH, KC_BSPC,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼───────────────┤
     KC_EQL,        KC_GRV,  KC_LEFT, KC_DOWN,      KC_RIGHT, KC_RBRC,                        KC_EXLM, KC_LGUI, KC_LSFT, KC_BSLS, KC_LCTL, KC_X,
  //├──────────────┼────────┼────────┼─────────────┼─────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼───────────────┤
     OSM(MOD_LSFT), KC_LPRN, KC_RPRN, LGUI_T(KC_C), KC_LBRC,  KC_V,    RGB_VAD,      RGB_VAI, KC_PERC, KC_LALT, KC_LSFT, KC_ASTR, TO(0),   OSM(MOD_LSFT),
  //└──────────────┴────────┴────────┴───┬────────┬┴────────┬┴───────┬┴────────┘    └────────┼────────┼────────┼────────┴────────┴────────┴───────────────┘
                                          KC_ESC,  KC_ENT,   KC_MPLY,                         KC_NO,   KC_SPC,  KC_DEL
                                      // └────────┴─────────┴────────┘                       └────────┴────────┴────────┘
  ),

  [_SPREADSHEET] = LAYOUT( // 5
  //┌──────────────┬────────┬─────────────┬─────────────┬─────────────┬────────┐                      ┌────────┬─────────────┬─────────────┬─────────────┬────────┬──────────────┐
     KC_NO,         KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,                          KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     KC_TAB,        KC_HOME, KC_PGDN,      KC_F2,        KC_PGUP,      KC_END,                         KC_DLR,  KC_MINS,      KC_RSFT,      KC_PLUS,      KC_INS,  KC_BSPC,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     KC_EQL,        KC_6,    LCTL_T(KC_3), LALT_T(KC_1), LGUI_T(KC_2), KC_7,                           KC_9,    LGUI_T(KC_4), LALT_T(KC_0), LCTL_T(KC_5), KC_8,    KC_X,
  //├──────────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼────────┐    ┌────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼──────────────┤
     OSM(MOD_LSFT), KC_NO,   KC_NO,        KC_C,         KC_NO,        KC_V,    KC_NO,        KC_NO,   KC_PERC, KC_LSFT,      KC_NO,        KC_NO,        TO(0),   OSM(MOD_LSFT),
  //└──────────────┴────────┴─────────────┴────────┬────┴───┬────────┬┴────────┴───┬────┘    └───┬────┴───┬────┴───┬────────┬┴─────────────┴─────────────┴────────┴──────────────┘
                                                    KC_ESC,  KC_ENT,  KC_MPLY,                      KC_NO,   KC_SPC,  KC_DEL
                                                // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT( // 6
  //┌──────┬────────┬──────┬──────┬──────┬────────┐                      ┌─────┬─────┬────────┬────────┬────────┬────────┐
     KC_ESC, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,                           KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├──────┼────────┼──────┼──────┼──────┼────────┤                      ├─────┼─────┼────────┼────────┼────────┼────────┤
     KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,                           KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├──────┼────────┼──────┼──────┼──────┼────────┤                      ├─────┼─────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                           KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├──────┼────────┼──────┼──────┼──────┼────────┼────────┐    ┌────────┼─────┼─────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_NO,        KC_NO,   KC_N, KC_M, KC_COMM, KC_DOT,  TO(0),   KC_SLSH,
  //└──────┴────────┴──────┴───┬──┴────┬─┴──────┬─┴───┬────┘    └───┬────┴───┬─┴─────┼────────┼────────┴────────┴────────┘
                                KC_ESC, KC_SPC,  KC_MPLY,                KC_NO, KC_SPC,  KC_DEL
                            // └───────┴────────┴─────┘             └────────┴───────┴────────┘
  ),

    [_MISC] = LAYOUT( // 7
  //┌────────┬────────┬──────────────┬──────────────┬───────────────┬────────┐                      ┌────────┬───────────────┬──────────────┬───────────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_NO,          KC_NO,                          KC_NO,   KC_NO,          KC_NO,         KC_NO,          KC_NO,   KC_NO,
  //├────────┼────────┼──────────────┼──────────────┼───────────────┼────────┤                      ├────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_NO,          KC_NO,                          KC_NO,   KC_NO,          KC_NO,         KC_NO,          KC_NO,   KC_NO,
  //├────────┼────────┼──────────────┼──────────────┼───────────────┼────────┤                      ├────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_F11,  KC_F6,   KC_F3,         KC_F1,         KC_F2,          KC_F7,                          KC_F9,   KC_F4,          KC_F10,         KC_F5,          KC_F8,   KC_F12,
  //├────────┼────────┼──────────────┼──────────────┼───────────────┼────────┼────────┐    ┌────────┼────────┼───────────────┼──────────────┼───────────────┼────────┼────────┤
     KC_LSFT, KC_NO,   KC_NO,         KC_NO,         KC_NO,          KC_NO,   RGB_VAD,      RGB_VAI, KC_NO,   KC_NO,          KC_NO,         KC_NO,          TO(0),   KC_LSFT,
  //└────────┴────────┴──────────────┴───┬────────┬─┴──────┬────────┼────────┴───┬────┘    └───┬────┴───┬────┴───┬────────┬──┴──────────────┴───────────────┴────────┴────────┘
                                          KC_ESC,  KC_ENT,  KC_MPLY,                              KC_NO,   KC_SPC,  KC_DEL
                                      // └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case ALPHA:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_ALPHA);
//       }
//       return false;
//       break;
//     case NAV:
//       if (record->event.pressed) {
//         layer_on(_NAV);
//         update_tri_layer(_NAV, _NUMBERS, _SUPER_NAV);
//       } else {
//         layer_off(_NAV);
//         update_tri_layer(_NAV, _NUMBERS, _SUPER_NAV);
//       }
//       return false;
//       break;
//     case NUMBERS:
//       if (record->event.pressed) {
//         layer_on(_NUMBERS);
//         update_tri_layer(_NAV, _NUMBERS, _SUPER_NAV);
//       } else {
//         layer_off(_NUMBERS);
//         update_tri_layer(_NAV, _NUMBERS, _SUPER_NAV);
//       }
//       return false;
//       break;
//     case SUPER_NAV:
//       if (record->event.pressed) {
//         layer_on(_SUPER_NAV);
//       } else {
//         layer_off(_SUPER_NAV);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
//     }
//     else if (index == 1) {
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     }
//     return true;
// }
