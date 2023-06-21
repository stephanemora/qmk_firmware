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
     KC_ESC,        FR_Q,   FR_W,   FR_F,           FR_P,           FR_B,                                                                      FR_J,        FR_L,           FR_U,           FR_Y,           FR_QUOT,        KC_BSPC,
     OSM(MOD_LSFT), LGUI_T(FR_A),   LALT_T(FR_R),   LCTL_T(FR_S),   LSFT_T(FR_T),   FR_G,                                                      FR_M,        RSFT_T(FR_N),   RCTL_T(FR_E),   LALT_T(FR_I),   RGUI_T(FR_O),   KC_ENT,
     I3,            FR_Z,   FR_X,   FR_C,           FR_D,           FR_V,           _______,    _______,       _______,      _______,          FR_K,        FR_H ,          FR_COMM,        FR_DOT,         FR_CIRC,        FR_COLN,
                                    ADJUST,         KC_LCTL,        SYM_ESC,        NAV_SPC,    _______,       _______,      NUM_KC_BSPC,      FRENCH_ENT,  KC_TAB,         KC_MUTE
    ),
