/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                                     KC_PGUP,  KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                     KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,
      _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
    ),
