 /* Copyright 2020 Naoki Katahira
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

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _MOUSE,
  _NAV,
  _SWERTY,
  _SYM,
  _NUM,
};


#define SWE_O UP(SE_O, SE_OS)
#define SWE_A UP(SE_AE, SE_AES)
#define SWE_OA UP(SE_OA, SE_OAS)

// Left-hand home row mods
#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)

// Right-hand home row mod
#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)


enum unicode_names { SE_O, SE_OS, SE_AE,SE_AES, SE_OA, SE_OAS };

const uint32_t PROGMEM unicode_map[] = {
    [SE_OS] = 0x00D6,  // Ö
    [SE_O] = 0x00F6,  // Ö
    [SE_AE] = 0x00E4,  // Ä
    [SE_AES] = 0x00C4,  // Ä
    [SE_OAS] = 0x00C5,  // Ã
    [SE_OA] = 0x00E5  // Ã
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 [_QWERTY] = LAYOUT(
 KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
 KC_NO,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
 KC_NO,     HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                   KC_H,    HRM_J,   HRM_K,   HRM_L,  HRM_SCLN, KC_QUOT,
 TG(_SWERTY),KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC, KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH,   KC_DOT,
                     TG(_MOUSE),   MO(_NAV), LT(_NUM,KC_ESC), LT(_SYM,KC_SPC), KC_ENT, KC_BSPC, KC_TAB, KC_DEL),

[_MOUSE] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            TG(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX),

[_NAV] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

[_SWERTY] = LAYOUT(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SWE_OA,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SWE_O,   SWE_A,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

 [_SYM] = LAYOUT(
 KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
 XXXXXXX,  XXXXXXX, XXXXXXX, KC_MINS,  KC_PLUS, KC_CIRC,                      KC_DLR, KC_RBRC, KC_LBRC, KC_TILD, KC_GRV,    KC_MINS,
 XXXXXXX,  KC_AMPR, KC_PERC, KC_HASH,   KC_AT, KC_EXLM,                      KC_DQUO, KC_RPRN, KC_LPRN, KC_PIPE, XXXXXXX,  KC_QUOT,
 TG(3),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, XXXXXXX,     XXXXXXX,  KC_QUOT, KC_RCBR, KC_LCBR, KC_BSLS, XXXXXXX,  XXXXXXX,
                           XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,KC_EQUAL, XXXXXXX, XXXXXXX),

 [_NUM] = LAYOUT(
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                  XXXXXXX, KC_1,       KC_2,    KC_3, XXXXXXX, XXXXXXX,
 XXXXXXX, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,                  XXXXXXX, KC_4,       KC_5,    KC_6, XXXXXXX, XXXXXXX,
 XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,XXXXXXX,  XXXXXXX,XXXXXXX, KC_7,       KC_8,    KC_9, XXXXXXX, XXXXXXX,
                            XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  XXXXXXX,  KC_0, XXXXXXX, XXXXXXX)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};


//new

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case _NAV:
        oled_write_ln_P(PSTR("Nav"), false);
        break;
    case _MOUSE:
        oled_write_ln_P(PSTR("Mouse"), false);
        break;
    case _SWERTY:
        oled_write_ln_P(PSTR("SWERTY"), false);
        break;
    case _NUM:
        oled_write_ln_P(PSTR("Num"), false);
        break;
    case _SYM:
        oled_write_ln_P(PSTR("Sym"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }

  } else {
      render_logo();
  }
    return false;
}
#endif // OLED_ENABLE

