#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    BASE,
    NAV,
    NUM,
    MDA,
    SYM,
    ADJ
};

enum custom_keycodes {
    SENDIO = SAFE_RANGE,
};

#define MOD_A LSFT_T(KC_A)
#define MOD_S LCTL_T(KC_S)
#define MOD_D LALT_T(KC_D)
#define MOD_F LGUI_T(KC_F)

#define MOD_Z LSFT_T(KC_Z)
#define MOD_X LCTL_T(KC_X)
#define MOD_C LALT_T(KC_C)
#define MOD_V LGUI_T(KC_V)

#define MOD_J    RGUI_T(KC_J)
#define MOD_K    LALT_T(KC_K)
#define MOD_L    RCTL_T(KC_L)
#define MOD_SCLN RSFT_T(KC_SCLN)

#define MOD_M    RGUI_T(KC_M)
#define MOD_COMM LALT_T(KC_COMM)
#define MOD_DOT  RCTL_T(KC_DOT)
#define MOD_SLSH RSFT_T(KC_SLSH)

#define ESC_CMD LGUI_T(KC_ESC)
#define BSP_SFT LSFT_T(KC_BSPC)
#define SPC_NUM LT(NUM, KC_SPC)
#define ENT_SYM LT(SYM, KC_ENT)
#define DEL_NAV LT(NAV, KC_DEL)

#define SLEEP   C(G(KC_Q))
#define SCRNSHT S(G(KC_4))
#define MUTEMT  S(C(A(G(KC_G))))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CMD,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   MOD_Z,   MOD_X,   MOD_C,   MOD_V,    KC_B,                         KC_N,   MOD_M,MOD_COMM, MOD_DOT,MOD_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD, BSP_SFT, DEL_NAV,    ENT_SYM, SPC_NUM, KC_LCTL
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    MO(ADJ), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MINS,    KC_4,    KC_5,    KC_6,  KC_EQL,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,    KC_0, KC_MINS,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* [NUM] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*     _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      _______, _______, _______, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     _______, KC_MINS,    KC_4,    KC_5,    KC_6,  KC_EQL,                      _______, _______, _______, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      _______, _______, _______, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         _______,    KC_0, KC_MINS,    _______, _______, _______ */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ), */

  [MDA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       MUTEMT, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_MPLY, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_BRMD, KC_BRMU, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* [SYM] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      _______, _______, _______, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     _______, KC_UNDS,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_BRMD, KC_BRMU, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      _______, _______, _______, _______, _______, _______, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______ */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ), */

  [ADJ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, SCRNSHT, XXXXXXX,                      NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

const uint16_t PROGMEM enter_combo[]  = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM io_combo[]  = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM copy_combo[]   = {MOD_X, MOD_C, COMBO_END};
const uint16_t PROGMEM paste_combo[]  = {MOD_C, MOD_V, COMBO_END};
const uint16_t PROGMEM adjust_combo[] = {KC_TAB, KC_BSLS, COMBO_END};
const uint16_t PROGMEM reset_combo[]  = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM caps_combo[]   = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM sleep_combo[]  = {KC_P, KC_BSLS, COMBO_END};
const uint16_t PROGMEM ctab_combo[]   = {KC_W, KC_E, COMBO_END};
combo_t key_combos[] = {
    //COMBO(enter_combo,  KC_ENT),
    //COMBO(copy_combo,   G(KC_C)),
    //COMBO(paste_combo,  G(KC_V)),
    COMBO(io_combo,       SENDIO),
    COMBO(adjust_combo,   OSL(ADJ)),
    COMBO(reset_combo,    QK_BOOT),
    COMBO(caps_combo,     QK_CAPS_WORD_TOGGLE),
    COMBO(sleep_combo,    SLEEP),
    COMBO(ctab_combo,     C(KC_TAB)),
};
size_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_CMD:
            return 0;
        case MOD_Z:
        case MOD_SLSH:
            return 170;
        case MOD_X:
        case MOD_C:
        case MOD_V:
        case MOD_M:
        case MOD_COMM:
        case MOD_DOT:
           return 220;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSP_SFT:
        case ESC_CMD:
            return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOD_Z:
        case MOD_SLSH:
        case MOD_X:
        case MOD_C:
        case MOD_V:
        case MOD_M:
        case MOD_COMM:
        case MOD_DOT:
        case SPC_NUM:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOD_Z:
        case MOD_SLSH:
        case MOD_X:
        case MOD_C:
        case MOD_V:
        case MOD_M:
        case MOD_COMM:
        case MOD_DOT:
        case SPC_NUM:
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSP_SFT:
            return false;
        default:
            return true;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_CMD:
        case SPC_NUM:
            return true;
        default:
            return false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_O:
        case KC_Q ... KC_Z:
        case KC_SCLN:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            // Deactivate Caps Word.
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SENDIO:
            if (record->event.pressed) {
                SEND_STRING("l;");
            }
           break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    oled_set_cursor(0, 6);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case ADJ:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            break;
    }
    uint8_t mods = get_mods();
    if (mods & MOD_MASK_CTRL) {
        oled_write_ln_P(PSTR("CTRL"), false);
    }
    if (mods & MOD_MASK_ALT) {
        oled_write_ln_P(PSTR("OPT"), false);
    }
    if (mods & MOD_MASK_SHIFT) {
        oled_write_ln_P(PSTR("SHFT"), false);
    }
    if (mods & MOD_MASK_GUI) {
        oled_write_ln_P(PSTR("CMD"), false);
    }
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock || is_caps_word_on()) {
        oled_write_ln_P(PSTR("CAPS"), false);
    }

    // Make sure screen is clear
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

bool rendered_logo = false;
void oled_render_logo(void) {
    static const char PROGMEM logo[] = {
        0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc4, 0xc4, 0x06, 0x0e,
        0x1e, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x78,
        0x70, 0x60, 0x21, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // Only render the logo once so it doesn't prevent the screen from going to sleep
    if (!rendered_logo) {
        oled_write_raw_P(logo, sizeof(logo));
        rendered_logo = true;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_logo();
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE
