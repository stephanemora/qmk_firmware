// clang-format off
/* Extend
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬─────────┬─────────┬──────┬─────────┬──────┬──────┐
 * │      │ MS B1│MS Up │ MS B2│ WH Up│      │Ctrl Up  │Ctrl Lft │  Up  │Crl Rgt  │ PgDn │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼─────────┼─────────┼──────┼─────────┼──────┼──────┤
 * │      │MS Lf │MS Dw │MS Rgt│ WH Dw│      │Ctrl Down│ Left    │ Down │ Right   │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼─────────┼─────────┼──────┼─────────┼──────┼──────┤
 * │      │ Undo │  Cut │ Copy │ Paste│      │         │WH Lft   │ MS B3│WH Rgt   │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼─────────┼─────────┼──────┼─────────┼──────┼──────┤
 * │      │      │      │      │      │      │         │  Ins    │      │         │      │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴─────────┴─────────┴──────┴─────────┴──────┴──────┘
 */

[_NAV] = LAYOUT_planck_grid(
    _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, C(KC_UP),    C(KC_LEFT), KC_UP,   C(KC_RGHT),  KC_PGUP, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, C(KC_DOWN),  KC_LEFT,    KC_DOWN, KC_RIGHT,    KC_PGDN, _______,
    _______, _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______,     _______,    KC_WH_L, KC_BTN3,     KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______, _______,     KC_INS,     _______, _______,     _______, _______
),
