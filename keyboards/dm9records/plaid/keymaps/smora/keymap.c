/* Copyright 2019 Takuya Urakawa (dm9records.com)
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
#include "keymap_french.h"

enum plaid_layers {
  _COLEMAK_DH,
  _FRENCH,
  _I3,
  _NUM,
  _SYM,
  _NAV,
  _ADJUST
};

enum plaid_keycodes {
  COLEMAK_DH = SAFE_RANGE,
  FRENCH,
  EXT_PLV,
  LED_1,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_0,
  KC_SECRET_1 = 100
};

// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM          MO(_SYM)
#define FRENCH_BSPC  LT(_FRENCH, KC_BSPC)
#define NUM          MO(_NUM)
#define I3_BSPC      LT(_I3, KC_BSPC)
#define I3           MO(_I3)
#define NAV          TT(_NAV)
#define NAV_SPC      LT(_NAV, KC_SPC)
#define FRENCH       OSL(_FRENCH)
#define NUM_BSPC     LT(_NUM, KC_BSPC)
#define FRENCH_ENT   LT(_FRENCH, KC_ENT)
#define SYM_ESC      LT(_SYM, KC_ESC)
#define V_FRENCH     LT(_FRENCH, FR_V)

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
    KC_LCTL,
    KC_RCTL,
    KC_LALT,
    KC_RALT,
    KC_LSFT,
    KC_RSFT,
    KC_LGUI,
    KC_RGUI,
    NUM,
    SYM
};

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

#undef KC_UNDO
#undef KC_CUT
#undef KC_COPY
#undef KC_PSTE
#define KC_UNDO LCTL(FR_Z)
#define KC_CUT  LCTL(FR_X)
#define KC_COPY LCTL(FR_C)
#define KC_PSTE LCTL(FR_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


#include "layers/num_layer.h"
#include "layers/nav_layer.h"
#include "layers/colemak_dh_layer.h"
#include "layers/french_layer.h"
#include "layers/i3_layer.h"
#include "layers/sym_layer.h"



/* Adjust (Num + Sym)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    _______, QK_BOOT, LED_1,    LED_2,  LED_3,  LED_4,  LED_5,LED_6, LED_7, LED_8, LED_9, LED_0,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, COLEMAK, _______, _______, KC_SECRET_1,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

/*
* q = Toggle Red LED state, deactivates any other modes
* w = Toggle Green LED state, deactivates any other modes
* e = Set RED LED to modifier mode
* r = Set GREEN LED to modifier mode
* t = Set RED LED to Blinkinlights mode
* y = set GREEN LED to Blinkinlights mode
* u = set RED LED to Keypress mode
* i = set GREEN LED to Keypress mode
* o = set RED LED to Carriage mode
* p = set GREEN LED to Carriage mode
*/

};

//Setup config struct for LED
typedef union {
  uint32_t raw;
  struct {
    uint8_t  red_mode :8;
    uint8_t  green_mode :8;
  };
} led_config_t;
led_config_t led_config;

//Set leds to saved state during powerup
void keyboard_post_init_user(void) {
  // set LED pin modes
  setPinOutput(LED_RED);
  setPinOutput(LED_GREEN);

  // Call the post init code.
  led_config.raw = eeconfig_read_user();

  if(led_config.red_mode == LEDMODE_ON) {
      writePinHigh(LED_RED);
  }

  if(led_config.green_mode == LEDMODE_ON) {
      writePinHigh(LED_GREEN);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  led_config.raw = 0;
  led_config.red_mode = LEDMODE_ON;
  led_config.green_mode = LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
  eeconfig_update_user(led_config.raw);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FRENCH, _SYM, _ADJUST);
}

void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
    switch (led_mode) {
      case LEDMODE_MODS:
        for (int i=0;i<sizeof(modifiers) / sizeof(modifiers[0]);i++) {
          if(keycode==modifiers[i]) {
            if (record->event.pressed) {
              writePinHigh(led);
            }
            else {
              writePinLow(led);
            }
          }
        }
        break;
      case LEDMODE_BLINKIN:
        if (record->event.pressed) {
          if(rand() % 2 == 1) {
            if(rand() % 2 == 0) {
              writePinLow(led);
            }
            else {
              writePinHigh(led);
            }
          }
        }
        break;
      case LEDMODE_KEY:
        if (record->event.pressed) {
          writePinHigh(led);
          return;
        }
        else {
          writePinLow(led);
          return;
        }
        break;
      case LEDMODE_ENTER:
        if (keycode==KC_ENT) {
          writePinHigh(led);
        }
        else {
          writePinLow(led);
        }
        break;

    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* If the either led mode is keypressed based, call the led updater
     then let it fall through the keypress handlers. Just to keep
     the logic out of this procedure */
  if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_RED, led_config.red_mode, keycode, record);
  }
  if (led_config.green_mode >= LEDMODE_MODS && led_config.green_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_GREEN, led_config.green_mode, keycode, record);
  }
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case LED_1:
      if (record->event.pressed) {
        if (led_config.red_mode==LEDMODE_ON) {
            led_config.red_mode=LEDMODE_OFF;
            writePinLow(LED_RED);
        }
        else {
            led_config.red_mode=LEDMODE_ON;
            writePinHigh(LED_RED);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_2:
      if (record->event.pressed) {
        if (led_config.green_mode==LEDMODE_ON) {
            led_config.green_mode=LEDMODE_OFF;
            writePinLow(LED_GREEN);
        }
        else {
            led_config.green_mode=LEDMODE_ON;
            writePinHigh(LED_GREEN);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_3:
      led_config.red_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_4:
      led_config.green_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_5:
      led_config.red_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_6:
      led_config.green_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_7:
      led_config.red_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_8:
      led_config.green_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_9:
      led_config.red_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_0:
      led_config.green_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
  }
  return true;
}

/*
*
* TAPDANCES
*
*/

//Tap Dance Declarations
enum tapdances {
  TD_LSFT_CAPS = 0
};

void dance_sft_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_LSFT);
  } else {
    set_oneshot_mods (MOD_LSFT);
  }
}

void dance_sft_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_LSFT);
  } else {
    unregister_code (MOD_LSFT);
  }
}

tap_dance_action_t tap_dance_actions[] = {
 [TD_LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_sft_finished, dance_sft_reset)
};