/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"
#include "action_layer.h"

// Layer shorthand
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | DEL    | /      | *      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | ESC    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSP | 7      | 8      | 9      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | 4      | 5      | 6      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT | 1      | 2      | 3      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LED    | LCTRL  | LALT   | LGUI   | LOWER  | SPACE  | SPACE  | RAISE  | LEFT   | DOWN   | UP     | RIGHT  | 0      | .      | ENTER  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = { /* QWERTY */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  KC_PSLS,  KC_PAST, KC_PMNS },
  { KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_P7,   KC_P8,   KC_P9   },
  { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_P4,   KC_P5,   KC_P6   },
  { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_P1,   KC_P2,   KC_P3   },
  { BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_P0,   KC_PDOT, KC_PENT },
 },

/* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | {      |        |        |        |        |        | _      | +      |        | }      | |      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | ISO ~  | ISO |  |        |        | ENTER  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        | NEXT   | VOL-   | VOL +  | PLAY   |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LOWER] = { /* LOWER */
  { _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______ },
  { _______, KC_LCBR, _______, _______, _______, _______, _______, KC_UNDS,    KC_PLUS,    _______, KC_RCBR, KC_PIPE, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, S(KC_NUHS), S(KC_NUBS), _______, _______, KC_ENT,  _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______ },
 },

/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | [      |        |        |        |        |        | -      | =      |        | ]      | \      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | ISO #  | ISO /  |        |        | ENTER  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        | NEXT   | VOL-   | VOL +  | PLAY   |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RAISE] = { /* RAISE */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, KC_LBRC, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, KC_RBRC, KC_BSLS, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, _______, KC_ENT,  _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______ },
 },

/* ADJUST
 * .----------------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |         |           |        |        |         |         |          |        |        |        |        |        |        |
 * |--------+--------+---------+-----------+--------+--------+---------+---------+----------+--------+--------+--------+--------+--------+--------|
 * |        | RESET  |RGB PLAIN|RGB BREATHE|RGB RAIN|RGB GRAD|RGB SWIRL|RGB SNAKE|RGB KNIGHT|RGB XMAS|        |        |        |        |        |
 * |--------+--------+---------+-----------+--------+--------+---------+---------+----------+--------+--------+--------+--------+--------+--------|
 * |        |        |         |           |        |        |         | QWERTY  |          |        |        |        |        |        |        |
 * |--------+--------+---------+-----------+--------+--------+---------+---------+----------+--------+--------+--------+--------+--------+--------|
 * |        |        |RGB TOG  | RGB MODE  |RGB HUE-|RGB HUE+|RGB SAT- |RGB SAT+ | RGB BRI- |RGB BRI+|        |        |        |        |        |
 * |--------+--------+---------+-----------+--------+--------+---------+---------+----------+--------+--------+--------+--------+--------+--------|
 * |        |        |         |           |        |        |         |         |          |        |        |        |        |        |        |
 * '----------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_ADJUST] = { /* ADJUST */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, RESET,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_G,RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}