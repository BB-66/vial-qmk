/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2016 Priyadi Iman Nurcahyo <priyadi@priyadi.net>
RP2040 (splitkb Liatris) port, 2026: AVR USART/INT/BUSYWAIT driver
configuration removed; PS/2 handled by the RP2040 PIO "vendor" driver.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Pseudo-matrix size.
 * This is NOT a physical row/column matrix: Scan Code Set 3 codes
 * (0x00-0x87) are mapped into a 17x8 grid, where
 *   row = scancode >> 3   (keycode bits 6-4 and up)
 *   col = scancode & 0x07 (keycode bits 2-0)
 * Do not change these to match the membrane -- the membrane is the
 * IBM controller's problem, not ours.
 */
#define MATRIX_ROWS 17
#define MATRIX_COLS 8

/*
 * PS/2 pins for the RP2040 PIO ("vendor") driver.
 *
 * Hardware constraint of the PIO driver: the CLOCK pin MUST be the
 * GPIO immediately following the DATA pin.
 *
 * Wiring on the Liatris (per the level-shifter harness):
 *   IBM DATA  -> TXS0108E B2->A2 -> GP2
 *   IBM CLOCK -> TXS0108E B1->A1 -> GP3
 */
#define PS2_DATA_PIN  GP2
#define PS2_CLOCK_PIN GP3

/* Uncomment ONLY if you later enable RGBLIGHT/RGB_MATRIX on the
 * Liatris's onboard WS2812B and the two drivers collide over PIO0.
 * Not needed for this build; RGB stays disabled.
 */
// #define PS2_PIO_USE_PIO1

/* key combination for bootmagic/command */
#define IS_COMMAND() ( \
    get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RCTL)) \
)
