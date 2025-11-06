 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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


extern uint8_t is_master;

enum layers {
    _BASE,
    _NUMBER,
    _SYMBOL,
    _FUN,
    _NAV,
    _MEDIA,
    _MOUSE,
};

#define NUMBER(n) LT(_NUMBER, n)
#define SYMBOL(n) LT(_SYMBOL, n)
#define FUN(n) LT(_FUN, n)
#define NAV(n) LT(_NAV, n)
#define MEDIA(n) LT(_MEDIA, n)
#define MOUSE(n) LT(_MOUSE, n)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * ,----------------------------------.                    ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |Sup(A)|Alt(S)|Ctrl(D)|Sh(F)|   G  |-------.    ,-------|   H  |Sh(J)|Ctrl(K)|Alt(L)|Sup(;)|
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |Esc   |Space | / Tab   /       \Enter \  |BackSp|      |      |
 *            |      |MEDIA | NAV  |/  FUN  /         \ SYM  \ | NUM  |      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_BASE] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX                ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  XXXXXXX,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T                   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,XXXXXXX,
  XXXXXXX,LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,KC_H,LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN),XXXXXXX,
  XXXXXXX,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,XXXXXXX,XXXXXXX,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,XXXXXXX,
       XXXXXXX, MEDIA(KC_ESC), NAV(KC_SPC), MOUSE(KC_TAB), SYMBOL(KC_ENT), NUMBER(KC_BSPC), FUN(KC_BSPC), XXXXXXX
),

/* NUMBER
 * ,----------------------------------.                    ,----------------------------------.
 * |   [  |   7  |   8  |   9  |   ]  |                    |      |      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |   ;  |   4  |   5  |   6  |   =  |-------.    ,-------|      |      |      |      |      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   \  |-------|    |-------|      |      |      |      |      |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |  >   |  0   | /  -    /       \      \  |      |      |      |
 *            |      |      |      |/       /         \      \ | NUM  |      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_NUMBER] = LAYOUT(
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,KC_LBRC,KC_7   ,KC_8   ,KC_9   ,KC_RBRC                ,_______,_______,_______,_______,_______,_______,
  _______,KC_SCLN,KC_4   ,KC_5   ,KC_6   ,KC_EQL                 ,_______,_______,_______,_______,_______,_______,
  _______,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_BSLS,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,KC_0   ,KC_MINS,_______,_______,_______,_______
),

/* SYMBOL
 * ,----------------------------------.                    ,----------------------------------.
 * |   {  |   &  |   *  |   (  |   }  |                    |      |      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |   :  |   $  |   %  |   ^  |   +  |-------.    ,-------|      |      |      |      |      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   |  |-------|    |-------|      |      |      |      |      |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |  (   |  )   | /  _    /       \  SYM \  |      |      |      |
 *            |      |      |      |/       /         \      \ |      |      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_SYMBOL] = LAYOUT(
  _______,_______   ,_______,_______,_______,_______                   ,_______,_______,_______,_______,_______,_______,
  _______,S(KC_LBRC),S(KC_7),S(KC_8),S(KC_9),S(KC_RBRC)                ,_______,_______,_______,_______,_______,_______,
  _______,S(KC_SCLN),S(KC_4),S(KC_5),S(KC_6),S(KC_EQL)                 ,_______,_______,_______,_______,_______,_______,
  _______,S(KC_GRV) ,S(KC_1),S(KC_2),S(KC_3),S(KC_BSLS),_______,_______,_______,_______,_______,_______,_______,_______,
                             _______,S(KC_9),S(KC_0),S(KC_MINS),_______,_______,_______,_______
),

/* FUN
 * ,----------------------------------.                    ,----------------------------------.
 * |  F12 |  F7  |  F8  |  F9  |      |                    |      |      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |  F11 |  F4  |  F5  |  F6  |      |-------.    ,-------|      |      |      |      |      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |  F10 |  F1  |  F2  |  F3  |      |-------|    |-------|      |      |      |      |      |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |      |      | /       /       \      \  |      |      |      |
 *            |      |      |      |/       /         \      \ |      | FUN  |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_FUN] = LAYOUT(
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,KC_F12 ,KC_F7  ,KC_F8  ,KC_F9  ,_______                ,_______,_______,_______,_______,_______,_______,
  _______,KC_F11 ,KC_F4  ,KC_F5  ,KC_F6  ,_______                ,_______,_______,_______,_______,_______,_______,
  _______,KC_F10 ,KC_F1  ,KC_F2  ,KC_F3  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,_______,_______
),

/* NAV
 * ,----------------------------------.                    ,----------------------------------.
 * |      |      |      |      |      |                    |      |      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |      |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |      |      |      |      |      |-------|    |-------|INSERT| HOME | PG_DN| PG_UP| END  |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |      |      | /       /       \      \  |      |      |      |
 *            |      |      | NAV  |/       /         \      \ |      |      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_NAV] = LAYOUT(
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,_______,KC_INS ,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,
                          _______,_______,_______,_______,_______,_______,_______,_______
),

/* MEDIA
 * ,----------------------------------.                    ,----------------------------------.
 * |      |      |      |      |      |                    | PRINT|      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |      |      |      |      |      |-------.    ,-------| BACK | VOL- | VOL+ | FWD  |      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |      |      |      |      |      |-------|    |-------|      |      |      |      |      |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |      |      | /       /       \ STOP \  | PLAY | MUTE |      |
 *            |      | MEDIA|      |/       /         \      \ | PAUSE|      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_MEDIA] = LAYOUT(
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,KC_PSCR,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,KC_MSTP,KC_MPLY,KC_MUTE,_______
),

/* MOUSE
 * ,----------------------------------.                    ,----------------------------------.
 * |      |      |      |      |      |                    | PRINT|      |      |      |      |
 * |------+------+------+------+------|                    |------+------+------+------+------|
 * |      |      |      |      |      |-------.    ,-------| BACK | VOL- | VOL+ | FWD  |      |
 * |------+------+------+------+------|       |    |       |------+------+------+------+------|
 * |      |      |      |      |      |-------|    |-------|      |      |      |      |      |
 * `----------------------------------/       /     \      \----------------------------------'
 *            |      |      |      | /       /       \ STOP \  | PLAY | MUTE |      |
 *            |      |      |      |/ MOUSE /         \      \ | PAUSE|      |      |
 *            `----------------------------'           '------''--------------------'
 */

 [_MOUSE] = LAYOUT(
  _______,_______,_______,_______,_______,_______                ,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,KC_PSCR,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______                ,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,KC_MSTP,KC_MPLY,KC_MUTE,_______
)
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case _FUN:
            oled_write_ln_P(PSTR("FUN"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("MED"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOU"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}
#endif // OLED_ENABLE
