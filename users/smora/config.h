/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Force enable NKRO
#define FORCE_NKRO

/* Tap-Hold Configuration Options */
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 120
#define TAPPING_TERM_PER_KEY
#define LONG_TAPPING_TERM 0
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef MOUSEKEY_ENABLE
// Mouse key speed and acceleration.
  #undef MOUSEKEY_DELAY
  #define MOUSEKEY_DELAY          0
  #undef MOUSEKEY_INTERVAL
  #define MOUSEKEY_INTERVAL       16
  #undef MOUSEKEY_MAX_SPEED
  #define MOUSEKEY_MAX_SPEED      3
  #undef MOUSEKEY_TIME_TO_MAX
  #define MOUSEKEY_TIME_TO_MAX    40
  // Mouse wheel
  #undef MOUSEKEY_WHEEL_DELAY
  #define MOUSEKEY_WHEEL_DELAY    0
#endif



