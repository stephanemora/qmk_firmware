/*
 *
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  Enter |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  I3    |   Z  |   X  |   C  |   D  |   V  | LGui | LAlt |  | Tab  | Bksp |   K  |   H  | ,  ? |   .  |   ^  |  :   / |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust|LCtrl | Num  | Space| Nav  |  | Bksp | Bksp | Sym  | Tab  | Mute |
 *                        |      |      |      | /Nav |      |  | /Fr  | /Fr  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_ESC,        LGUI_T(FR_Q),   LALT_T(FR_W),     LCTL_T(FR_F),     LSFT_T(FR_P),     FR_B,                                                                      FR_J,       RSFT_T(FR_L),  RCTL_T(FR_U),     LALT_T(FR_Y),  RGUI_T(FR_QUOT),  KC_BSPC,
     OSM(MOD_LSFT), FR_A,           FR_R,             FR_S,             FR_T,             FR_G,                                                                      FR_M,       FR_N,          FR_E,             FR_I,          FR_O,             KC_ENT,
     I3,            FR_Z,           FR_X,             FR_C,             FR_D,             FR_V,          _______,    _______,       _______,          _______,       FR_K,       FR_H ,         FR_COMM,          FR_DOT,        FR_CIRC,          FR_COLN,
                                    ADJUST,           ADJUST,           SYM_ESC,          NAV_SPC,       _______,    _______,       NUM_KC_BSPC,      FRENCH_ENT,    KC_TAB,     KC_MUTE
    ),
