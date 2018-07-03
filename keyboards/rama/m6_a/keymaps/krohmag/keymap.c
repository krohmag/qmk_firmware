#include "../../m6_a.h"

// Define Layers
#define _BASE 0
#define _FNX  1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base Layer
    [_BASE] = KEYMAP(
		LT(1, KC_MUTE),KC_VOLD,KC_VOLU,
        KC_MRWD,       KC_MPLY,KC_MFFD),

// Fn Layer
    [_FNX] = KEYMAP(
		KC_TRNS,KC_UP,  KC_SLEP,
        KC_RGHT,KC_DOWN,KC_LEFT)
};