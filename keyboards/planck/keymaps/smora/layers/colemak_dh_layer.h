/* Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |  '   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   ^  |   :  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  I3  | Alt  | Num  | SYM  |  NAV |  NUM |FRENCH|Tab   |  ^   |   ¨  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_DH] = LAYOUT_planck_grid(
    KC_ESC,   LGUI_T(FR_Q),    LALT_T(FR_W),    LCTL_T(FR_F),     LSFT_T(FR_P),    FR_B,     FR_J,         RSFT_T(FR_L),    RCTL_T(FR_U),     LALT_T(FR_Y),      RGUI_T(FR_QUOT),    KC_BSPC,
    KC_LSFT,  FR_A,    FR_R,    FR_S,     FR_T,    FR_G,     FR_M,      FR_N,       FR_E,     FR_I,      FR_O,       KC_ENT,
    KC_LSFT,  FR_Z,    FR_X,    FR_C,     FR_D,    V_FRENCH, FR_K,      FR_H,       FR_COMM,  FR_DOT,    FR_CIRC,    FR_COLN,
    I3,       I3,      KC_LALT, KC_LCTL,  SYM_ESC, NAV_SPC,  NUM_BSPC,  FRENCH_ENT, KC_TAB,   FR_CIRC,   FR_DIAE,    KC_LGUI
),
