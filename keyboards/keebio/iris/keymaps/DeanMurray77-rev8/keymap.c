// /Users/deanmurray/Services/qmk_firmware/keyboards/keebio/iris/keymaps/DeanMurray77/keymap.c
// qmk compile -kb keebio/iris/rev5 -km DeanMurray77
// File location: /Users/deanmurray/qmk_firmware/keebio_iris_rev5_DeanMurray77.hex

// hold duration for the home row mods:
// quantum/action_tapping.h under TAPPING_TERM

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

// Is there an option to re-map the keys on my laptop? It won't be a perfect match to my split keyboard, but might make it a little easier to use my laptop when I don't have my custom keyboard with me.
// Is there a way to consolidate my cmd-c/cmd-x/cmd-v functions into one so that I take up less space? I was told to look into a 'custom dance type'

// Tap Dance declarations
enum {
  TD_COMMA_QUEST, // Tap once for comma/<, twice for a question mark
  TD_SLASH_CMD, // Does a colon/semi-colon on tap. Cmd slash on hold
  TD_C_CMD, // Does C on tap, cmd-c on hold
  TD_V_CMD, // Does V on tap, cmd-V on hold
  TD_X_CMD, // Does X on tap, cmd-X on hold
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void slashCmd_finished(tap_dance_state_t *state, void *user_data);
void slashCmd_reset(tap_dance_state_t *state, void *user_data);
void cCmd_finished(tap_dance_state_t *state, void *user_data);
void cCmd_reset(tap_dance_state_t *state, void *user_data);
void xCmd_finished(tap_dance_state_t *state, void *user_data);
void xCmd_reset(tap_dance_state_t *state, void *user_data);
void vlashCmd_finished(tap_dance_state_t *state, void *user_data);
void vlashCmd_reset(tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT( // 0
  //┌─────────┬─────────────────┬───────────────────┬─────────────┬─────────────┬─────────────┐                       ┌─────┬─────────────┬─────────────┬─────────────┬──────┬──────────┐
     KC_NO,    KC_1,             KC_2,               KC_3,         KC_4,         KC_5,                                 KC_6, KC_7,         KC_8,         KC_9,         KC_0,  KC_NO,
  //├─────────┼─────────────────┼───────────────────┼─────────────┼─────────────┼─────────────┤                       ├─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     KC_TAB,   KC_QUOT,          TD(TD_COMMA_QUEST), KC_DOT,       KC_P,         KC_Y,                                 KC_F, KC_G,         TD(TD_C_CMD), KC_R,         KC_L,  KC_BSPC,
  //├─────────┼─────────────────┼───────────────────┼─────────────┼─────────────┼─────────────┤                       ├─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     KC_EQL,   KC_A,             LCTL_T(KC_O),       LALT_T(KC_E), LGUI_T(KC_U), KC_I,                                 KC_D, LGUI_T(KC_H), LALT_T(KC_T), LCTL_T(KC_N), KC_S,  KC_MINS,
  //├─────────┼─────────────────┼───────────────────┼─────────────┼─────────────┼─────────────┼────────┐     ┌────────┼─────┼─────────────┼─────────────┼─────────────┼──────┼──────────┤
     KC_LSFT, TD(TD_SLASH_CMD), KC_Q,               KC_J,         KC_K,         TD(TD_X_CMD), KC_VOLD,       KC_VOLU, KC_B, KC_M,         KC_W,         TD(TD_V_CMD), KC_Z,  KC_RSFT,
  //└─────────┴─────────────────┴───────────────────┴─────────────┼────────┬────┴───┬────────┬┴────────┘     └───┬────┴───┬─┴──────┬──────┴─┬───────────┴─────────────┴──────┴──────────┘                               
                                                                   KC_ESC,  KC_ENT,  OSL(2),                      MO(1),   KC_SPC,   KC_DEL
                                                               // └────────┴────────┴────────┘                   └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT( // 1
  //┌─────────┬────────┬────────┬─────────────┬─────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬──────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_NO,   KC_PGDN, KC_UP,        KC_PGUP,  KC_NO,                          KC_NO,   KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_DEL,  KC_LEFT, KC_DOWN,      KC_RIGHT, KC_NO,                          KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_NO,   KC_NO,
  //├─────────┼────────┼────────┼─────────────┼─────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
     KC_NO,    KC_NO,   KC_HOME, KC_NO,        KC_END,    KC_NO,  RGB_VAD,      RGB_VAI, KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└─────────┴────────┴────────┴───┬────────┬┴────────┬┴───────┬┴────────┘    └────────┼────────┼────────┼────────┴────────┴────────┴──────────┘
                                     KC_NO,   KC_ENT,    KC_DEL,                          KC_NO,   KC_NO,  KC_NO
                                 // └────────┴─────────┴────────┘                       └────────┴────────┴────────┘ // I may end up wanting delete added back in, but on the left hand...
  ),

  [_NUMBERS] = LAYOUT( // 2
  //┌─────────┬────────┬─────────────┬─────────────┬─────────────┬────────┐                      ┌────────┬─────────────┬─────────────┬───────────┬────────┬──────────┐
     KC_NO,    KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,                          KC_NO,   KC_NO,        KC_NO,        KC_NO,      KC_NO,   KC_NO,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼───────────┼────────┼──────────┤
     KC_NO,    KC_NO,   KC_LPRN,      KC_DOT,       KC_RPRN,      KC_NO,                          KC_CIRC, KC_LCBR,      KC_RCBR,      KC_TILD,    KC_HASH,  KC_BSPC,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┤                      ├────────┼─────────────┼─────────────┼───────────┼────────┼──────────┤
     KC_NO,    KC_6,    KC_3,         KC_1,         KC_2,         KC_7,                           KC_9,    KC_4,         KC_0,         KC_5,       KC_8,    KC_EXLM,
  //├─────────┼────────┼─────────────┼─────────────┼─────────────┼────────┼────────┐    ┌────────┼────────┼─────────────┼─────────────┼───────────┼────────┼──────────┤
     KC_INS,    KC_AT,  KC_LBRC,      KC_AMPR,      KC_RBRC,      KC_NO,   KC_MPLY,      KC_NO,   KC_GRV,  KC_PERC,      KC_ASTR,      KC_PIPE,    KC_DLR,   KC_NO,
  //└─────────┴────────┴─────────────┴────────┬────┴───┬────────┬┴───────┬┴────────┘    └───┬────┴───┬────┴───┬────────┬┴─────────────┴───────────┴────────┴──────────┘
                                               KC_NO,   KC_NO,   TO(3),                      OSL(7),  KC_SLASH, KC_BSLS
                                           // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
  ),

  // [_SUPER_NAV] = LAYOUT( // 3 (OLD)
  // //┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌────────┬────────┬────────┬───────┬─────────┬────────┐
  //    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      RGB_VAI,  TO(0),   TO(0),   TO(0),  TO(0),    TO(0),
  // //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├────────┼────────┼────────┼───────┼─────────┼────────┤
  //    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_M_P, RGB_M_G,
  // //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├────────┼────────┼────────┼───────┼─────────┼────────┤
  //    TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      TO(0),   TO(4),   TO(5),   TO(6),  TO(7),    TO(0),
  // //├───────┼───────┼───────┼───────┼───────┼───────┼──────┐    ┌───────┼────────┼────────┼────────┼───────┼─────────┼────────┤
  //    KC_LSFT,TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),      TO(0),  TO(0),   TO(0),   TO(0),   TO(0),  TO(0),    KC_LSFT,
  // //└───────┴───────┴───────┴───┬───┴──┬────┴─┬─────┴┬─────┘    └───┬───┴───┬────┴──┬─────┴─┬──────┴───────┴─────────┴────────┘
  //                                TO(0), TO(0), TO(0),                TO(0),  TO(0),  TO(0)
  //                            // └──────┴──────┴──────┘              └───────┴───────┴───────┘
  // ),

  [_SUPER_NAV] = LAYOUT( // 3 (NEW)
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌────────┬────────┬────────┬───────┬─────────┬────────┐
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      RM_ON,   RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├────────┼────────┼────────┼───────┼─────────┼────────┤
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      RM_OFF,  RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├────────┼────────┼────────┼───────┼─────────┼────────┤
     TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),                      KC_G,    TO(4),   TO(5),   TO(6),  TO(7),    TO(0),
  //├───────┼───────┼───────┼───────┼───────┼───────┼──────┐    ┌───────┼────────┼────────┼────────┼───────┼─────────┼────────┤
     KC_LSFT,TO(0),  TO(0),  TO(0),  TO(0),  TO(0),  TO(0),      TO(0),  TO(0),   TO(0),   TO(0),   TO(0),  TO(0),    KC_LSFT,
  //└───────┴───────┴───────┴───┬───┴──┬────┴─┬─────┴┬─────┘    └───┬───┴───┬────┴──┬─────┴─┬──────┴───────┴─────────┴────────┘
                                 TO(0), TO(0), TO(0),                TO(0),  TO(0),  TO(0)
                             // └──────┴──────┴──────┘              └───────┴───────┴───────┘
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
     KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_LALT,        KC_RALT,   KC_N, KC_M, KC_COMM, KC_DOT,  TO(0),   KC_SLSH,
  //└──────┴────────┴──────┴───┬──┴────┬─┴──────┬─┴───┬────┘    └───┬────┴───┬─┴─────┼────────┼────────┴────────┴────────┘
                                KC_ESC, KC_SPC,  KC_RCTL,                KC_LCTL, KC_SPC,  KC_DEL
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

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void slashCmd_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            register_code16(LGUI(KC_SLASH)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_SCLN);
            register_code16(KC_SCLN);
            break;
        default:
            break;
    }
}

void slashCmd_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(LGUI(KC_SLASH));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SCLN);
            break;
        default:
            break;
    }
}

void cCmd_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_C);
            break;
        case TD_SINGLE_HOLD:
            register_code16(LGUI(KC_C)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_C);
            register_code16(KC_C);
            break;
        default:
            break;
    }
}

void cCmd_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(LGUI(KC_C));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        default:
            break;
    }
}

void xCmd_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_X);
            break;
        case TD_SINGLE_HOLD:
            register_code16(LGUI(KC_X)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_X);
            register_code16(KC_X);
            break;
        default:
            break;
    }
}

void xCmd_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_X);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(LGUI(KC_X));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_X);
            break;
        default:
            break;
    }
}

void vCmd_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_V);
            break;
        case TD_SINGLE_HOLD:
            register_code16(LGUI(KC_V)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_V);
            register_code16(KC_V);
            break;
        default:
            break;
    }
}

void vCmd_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_V);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(LGUI(KC_V));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_V);
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
  [TD_COMMA_QUEST] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_QUES), // Tap once for comma/<, twice for a question mark
  [TD_SLASH_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slashCmd_finished, slashCmd_reset),
  [TD_C_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cCmd_finished, cCmd_reset),
  [TD_X_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xCmd_finished, xCmd_reset),
  [TD_V_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vCmd_finished, vCmd_reset),
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
