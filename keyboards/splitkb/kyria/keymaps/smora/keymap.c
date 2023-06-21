/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_french.h"

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

char wpm_str[10];

enum layers {
    _COLEMAK_DH = 0,
    _FRENCH,
    _I3,
    _NAV,
    _SYM,
    _NUM,
    _ADJUST,
};

enum kyria_keycodes {
  KC_SECRET_1 = 100
};


// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM             MO(_SYM)
#define NAV             TT(_NAV)
#define NAV_SPC         LT(_NAV, KC_SPC)
#define NUM             MO(_NUM)
#define SYM_SPC         LT(_SYM, KC_SPC)
#define ADJUST          MO(_ADJUST)
#define FRENCH          OSL(_FRENCH)
#define FRENCH_KC_BSPC  LT(_FRENCH, KC_BSPC)
#define NUM_KC_BSPC     LT(_NUM, KC_BSPC)
#define I3_BSPC         LT(_I3, KC_BSPC)
#define I3              MO(_I3)
#define FRENCH_ENT   LT(_FRENCH, KC_ENT)
#define SYM_ESC      LT(_SYM, KC_ESC)

#define CTL_ESC    MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT   MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS   MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT    MT(MOD_LALT, KC_ENT)
#define CIRC_DIAE  MT(FR_CIRC, FR_DIAE)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#include "layers/colemak_dh_layer.h"
#include "layers/sym_layer.h"
#include "layers/nav_layer.h"
#include "layers/num_layer.h"
#include "layers/i3_layer.h"
#include "layers/french_layer.h"
#include "layers/ajust_layer.h"



// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_secrets(keycode, record);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
#endif





#ifdef OLED_ENABLE
//#include "oled/bongo_cat.c"
//#include "oled/stargate.c"
//#include "oled/nerv.c"
//#include "oled/pokemon1.c"
//#include "oled/pokemon2.c"
//#include "oled/kyria_logo.c"
//#include "oled/kyria_nerv_logo.c"

static void render_status(void) {
    // QMK Logo and version information

    // QMK Logo and version information
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);

    oled_write_P(PSTR("       Kyria rev 2.1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("Colemak-DH\n"), false);
            break;
        case _FRENCH:
            oled_write_P(PSTR("French\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _I3:
            oled_write_P(PSTR("I3\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

/*
    uint8_t mods = get_mods() | get_weak_mods();
    oled_write_P(PSTR("\n"), false);
    oled_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR("     "), false);
    oled_write_P(PSTR("\n"), false);
*/
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        //render_logo();
    }
    return false;
}
#endif


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);

        } else {
            tap_code(KC_VOLD);
        }
#       ifdef OLED_DRIVER_ENABLE
        oled_on();
#       endif
    } else if (index == 0) {
        if(IS_LAYER_ON(_NUM)) {
            if(clockwise) {
                tap_code16(S(C(FR_Z)));
            } else {
                tap_code16(C(FR_Z));
            }
        } else if(IS_LAYER_ON(_FRENCH)) {
            if(clockwise) {
                tap_code16(KC_WH_D);
            } else {
                tap_code16(KC_WH_U);
            }
        } else {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
#           ifdef OLED_DRIVER_ENABLE
            oled_on();
#           endif
        }
    }
    return false;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(FR_A):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LALT_T(FR_R):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LCTL_T(FR_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LSFT_T(FR_T):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(FR_N):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(FR_E):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(FR_I):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(FR_O):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}
