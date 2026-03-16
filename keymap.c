/* meishi2 Binary Numpad - フィンガーバイナリーテンキー */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_8,    /* KEY0 = 小指 = bit3 = 1000 = 8 */
        KC_4,    /* KEY1 = 薬指 = bit2 = 0100 = 4 */
        KC_2,    /* KEY2 = 中指 = bit1 = 0010 = 2 */
        KC_1     /* KEY3 = 人差指 = bit0 = 0001 = 1 */
    ),
};

/* --- 2キー同時押し (6パターン) --- */
const uint16_t PROGMEM combo_3[]     = {KC_2, KC_1, COMBO_END};
const uint16_t PROGMEM combo_5[]     = {KC_4, KC_1, COMBO_END};
const uint16_t PROGMEM combo_6[]     = {KC_4, KC_2, COMBO_END};
const uint16_t PROGMEM combo_9[]     = {KC_8, KC_1, COMBO_END};
const uint16_t PROGMEM combo_0[]     = {KC_8, KC_2, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_8, KC_4, COMBO_END};

/* --- 3キー同時押し (4パターン) --- */
const uint16_t PROGMEM combo_7[]     = {KC_4, KC_2, KC_1, COMBO_END};
const uint16_t PROGMEM combo_plus[]  = {KC_8, KC_2, KC_1, COMBO_END};
const uint16_t PROGMEM combo_star[]  = {KC_8, KC_4, KC_1, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {KC_8, KC_4, KC_2, COMBO_END};

/* --- 4キー同時押し (1パターン) --- */
const uint16_t PROGMEM combo_dot[]   = {KC_8, KC_4, KC_2, KC_1, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_3,     KC_3),
    COMBO(combo_5,     KC_5),
    COMBO(combo_6,     KC_6),
    COMBO(combo_7,     KC_7),
    COMBO(combo_9,     KC_9),
    COMBO(combo_0,     KC_0),
    COMBO(combo_plus,  KC_KP_PLUS),
    COMBO(combo_minus, KC_KP_MINUS),
    COMBO(combo_star,  KC_KP_ASTERISK),
    COMBO(combo_slash, KC_KP_SLASH),
    COMBO(combo_dot,   KC_KP_DOT),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);
