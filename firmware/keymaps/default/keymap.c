/**
 * @file keymap.c
 * @author sohamax (sohamsnpt)
 * @brief Finalized High-Performance Hackpad Firmware
 * @version 1.0
 * @date 2026-03-29
 * @copyright Copyright (c) 2026 sohamax. All rights reserved.
 */

#include QMK_KEYBOARD_H

/* ==========================================================================
   CONFIGURATION CONSTANTS (Easy to change later!)
   ========================================================================== */
#define BASE_HUE 160   // Blue base color
#define BASE_SAT 255   // Full saturation
#define BASE_VAL 40    // Dim glow for idle keys
#define ACTIVE_VAL 255 // Bright white for pressed keys

/*
 * KEYMAP LAYOUT: 3x3 ORTHO
 * ┌──────────┬──────────┬──────────┐
 * │   ESC    │ (EMPTY)  │ (EMPTY)  │
 * ├──────────┼──────────┼──────────┤
 * │    Q     │    W     │ F24/MUTE │
 * ├──────────┼──────────┼──────────┤
 * │    A     │    S     │    D     │
 * └──────────┴──────────┴──────────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        KC_ESC,  XXXXXXX, XXXXXXX, 
        KC_Q,    KC_W,    KC_F24,     // F24:  secret "Dead Key" for apps
        KC_A,    KC_S,    KC_D        
    )
};

/* ==========================================================================
   GLOBAL VARIABLES (For Animation & Lighting)
   ========================================================================== */
uint32_t anim_timer = 0;
uint8_t  last_input_count = 0;

/* ==========================================================================
   ROTARY ENCODER LOGIC
   ========================================================================== */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (clockwise) {
            tap_code(KC_VOLU); // Volume Up
        } else {
            tap_code(KC_VOLD); // Volume Down
        }
    }
    return true;
}

/* ==========================================================================
   PER-KEY RGB LIGHTING HELPERS
   ========================================================================== */
#ifdef RGBLIGHT_ENABLE
uint8_t get_led_index(uint8_t row, uint8_t col) {
    if (row == 0 && col == 0) return 0; // Esc
    if (row == 1 && col == 0) return 2; // Q
    if (row == 1 && col == 1) return 3; // W
    if (row == 1 && col == 2) return 4; // Encoder Click
    if (row == 2 && col == 0) return 5; // A
    if (row == 2 && col == 1) return 6; // S
    if (row == 2 && col == 2) return 7; // D
    return 255;
}
#endif

/* ==========================================================================
   THE "BRAIN" - Merged Logic for Lights & Cat
   ========================================================================== */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // 1. BONGO CAT LOGIC
    if (record->event.pressed) {
        last_input_count = 10;
        anim_timer = timer_read();
    }

    // 2. REACTIVE LIGHTING LOGIC
#ifdef RGBLIGHT_ENABLE
    uint8_t led = get_led_index(record->event.key.row, record->event.key.col);
    if (led != 255) {
        if (record->event.pressed) {
            rgblight_setrgb_at(255, 255, 255, led); // Flash White
        } else {
            rgblight_sethsv_at(BASE_HUE, BASE_SAT, BASE_VAL, led); // Back to Blue
        }
    }
#endif
    return true;
}

/* ==========================================================================
   RGB SYSTEM INIT & SCAN
   ========================================================================== */
#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    for (uint8_t i = 0; i < 8; i++) {
        if (i != 1) rgblight_sethsv_at(BASE_HUE, BASE_SAT, BASE_VAL, i); 
    }
}

void matrix_scan_user(void) {
    static uint8_t hue = 0;
    hue++; 
    rgblight_sethsv_at(hue, 255, 255, 1); // LED 1 is ALWAYS Rainbow
}
#endif

/* ==========================================================================
   BONGO CAT INTERFACE
   ========================================================================== */
#ifdef OLED_ENABLE
static void render_bongo_cat(void) {
    static const char PROGMEM cat_resting[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0x11, 0x08, 0x04, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM cat_tapping[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x1F, 0x1F, 0x08, 0x04, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    if (last_input_count > 0) {
        oled_write_raw_P(cat_tapping, sizeof(cat_tapping));
    } else {
        oled_write_raw_P(cat_resting, sizeof(cat_resting));
    }
}

/* ==========================================================================
   OLED DISPLAY INTERFACE (With Splash Screen)
   ========================================================================== */

   // How long the splash screen stays (3000ms = 3 seconds)
#define SPLASH_SCREEN_TIME 3000 

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    // --- STAGE 1: THE SPLASH SCREEN ---
    // If the time since plug-in is less than 3 seconds
    if (timer_read() < SPLASH_SCREEN_TIME) {
        oled_set_cursor(3, 1);
        oled_write_P(PSTR(">>> SOHAMAX <<<"), false);
        oled_set_cursor(4, 2);
        oled_write_P(PSTR("SYSTEM ACTIVE"), false);
        return false; // Exit early so the cat doesn't show yet
    }

    // --- STAGE 2: THE MAIN INTERFACE ---
    // This part only runs AFTER 3 seconds have passed
    if (timer_elapsed(anim_timer) > 150) {
        last_input_count = 0;
    }

    render_bongo_cat();

    oled_set_cursor(7, 0); 
    oled_write_P(PSTR("SOHAMAX"), false);
    
    oled_set_cursor(7, 2);
    oled_write_P(PSTR("MODE: GAMING"), false);

    return false;
}
#endif
