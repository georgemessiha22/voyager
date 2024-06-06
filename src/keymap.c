#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_LOCK,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    LT(3,KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_QUOTE,       KC_LEFT_ALT,    
                                                    KC_LEFT_GUI,    LT(2,KC_SPACE),                                 LT(1,KC_SPACE), MT(MOD_LCTL, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_EQUAL,       KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_LEFT_GUI,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_SYSTEM_SLEEP,RGB_TOG,        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,MAC_LOCK,                                       KC_INSERT,      KC_DELETE,      KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, 
    LED_LEVEL,      KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         AS_TOGG,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUI,        RGB_HUD,        RGB_MODE_FORWARD,RGB_SLD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_LEFT_GUI,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,                                   KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL1,                                   KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL2,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_MS_WH_DOWN,                                  KC_MS_WH_UP,    KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            return TAPPING_TERM -55;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {191,252,225}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {139,246,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,246,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,246,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,246,190}, {139,246,190}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {139,246,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,246,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {191,252,225}, {139,246,190}, {0,0,255}, {0,0,255}, {191,252,225}, {191,252,225}, {191,252,225}, {139,246,190}, {139,246,190}, {139,246,190} },

    [1] = { {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {0,0,0}, {162,218,204}, {162,218,204}, {162,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {162,218,204}, {162,218,204}, {162,218,204}, {162,218,204}, {0,0,0}, {83,246,58}, {162,218,204}, {162,218,204}, {162,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {40,211,255}, {0,0,0}, {0,0,0}, {213,217,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {3,218,204}, {2,244,118}, {2,244,118}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {213,217,245}, {213,217,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {85,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {0,218,204}, {43,218,204}, {0,0,0}, {159,218,204}, {159,218,204}, {159,218,204}, {0,0,0}, {0,0,0}, {123,218,204}, {255,246,142}, {123,218,204}, {123,218,204}, {0,0,0}, {0,0,0}, {43,218,204}, {43,218,204}, {43,218,204}, {43,218,204}, {0,0,0}, {139,246,190}, {139,246,190}, {85,218,204}, {85,218,204}, {0,0,0}, {85,218,204}, {0,0,0}, {0,0,0}, {85,218,204}, {85,218,204}, {12,218,204}, {85,218,204}, {43,218,204}, {0,0,0}, {85,218,204}, {12,218,204}, {12,218,204}, {12,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {139,246,190}, {139,246,190} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,71}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,71}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,71}, {0,0,0}, {86,255,71}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,71}, {0,218,204}, {86,255,71}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,71}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_LOCK:
      HCS(0x19E);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



