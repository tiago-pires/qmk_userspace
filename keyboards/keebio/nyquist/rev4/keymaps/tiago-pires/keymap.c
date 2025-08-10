// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _DVORAK,
    _SHORTCUTS,
    _SYMBOLS,
    _ADJUST
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  SHORTCUTS,
  SYMBOLS,
  ADJUST,
};

// Keyboard Shortcuts
#define TABCTL LCTL_T(KC_TAB)
#define ASTCTL LCTL_T(LSFT(KC_ASTR))
#define SLSHCTL LCTL_T(KC_SLSH)
#define ESCCTL LCTL_T(KC_ESC)
#define SPCSYM LT(_SYMBOLS, KC_SPC)
#define PLYSHT LT(_SHORTCUTS, KC_MPLY)
#define CLK1LWR LT(_SHORTCUTS, KC_BTN1)
#define CLK2CMD LGUI_T(KC_ESC)
#define BKSSFT MT(MOD_LSFT, KC_BSLS)
#define ESCCMD LGUI_T(KC_ESC)
#define EQLCTL LGUI_T(KC_EQL)
#define MINCTL RCTL_T(KC_MINS)
#define ZERCTL RCTL_T(KC_0)
#define ENTCTL RCTL_T(KC_ENT)
#define TLDCTL LCTL_T(KC_TILDE)
#define ENTSFT RSFT_T(KC_ENT)
#define ALTWINX LALT_T(LCMD(KC_W))
#define SLHSFT MT(MOD_LSFT, KC_SLSH)
#define UNDSFT MT(MOD_LSFT, KC_UNDS)

#define COPY LCMD(KC_C)
#define PASTE LCMD(KC_V)
#define CUT LCMD(KC_X)
#define SLCTALL LCMD(KC_A)
#define UNDO LCMD(KC_Z)
#define REDO LCMD(LSFT(KC_Z))
#define CMDTAB LCMD(KC_TAB)
#define ZOOMIN LCMD(LSFT(KC_EQL))
#define ZOOMOUT LCMD(LSFT(KC_MINS))
#define SAVE LCMD(KC_S)
#define GROUP LCMD(KC_G)
#define SCRSHOT LCMD(LSFT(KC_4))
#define SEARCH LCMD(KC_F)

#define INSP LCMD(LSFT(KC_C))
#define CHRMOB LCMD(LSFT(KC_M))
#define REFRSH LCMD(KC_R)
#define INSPX KC_F12

#define FIGGRD KC_G
#define FIGSLT KC_V
#define FIGDEV KC_D
#define FIGMUI LCMD(KC_BSLS)
#define QUITAPP LCMD(KC_Q)

#define DSGPAN KC_SPC
#define WFFPRV LCMD(LSFT(KC_P))
#define WFELMS LGUI_T(KC_Z)
#define WFDSKT KC_1
#define WFTABL KC_2
#define WFMOBL KC_3
#define WFMOBP KC_4
#define WFELMT KC_Z
#define WFMVUP LCMD(KC_UP)
#define WFMVDW LCMD(KC_DOWN)
#define RAYCAST LCMD(KC_SPC)
#define DUPLICT LCMD(KC_D)
#define CLSEWIN LCMD(KC_W)
#define ALTCDEL LALT_T(LCMD(KC_BSPC))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = LAYOUT_ortho_5x12(
  WFMOBP,   WFMOBL,   WFTABL,   WFDSKT,   DSGPAN,   INSPX,              KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,
  KC_GRV,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,               KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_BSPC,
  TABCTL,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,               KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     ENTCTL,
  BKSSFT,   KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,               KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     BKSSFT,
  FIGMUI,   KC_VOLD,  KC_VOLU,  ALTCDEL,  ESCCMD,   PLYSHT,             SPCSYM,   ESCCMD,   KC_LALT,  KC_DOWN,  KC_UP,    KC_RGHT
),

[_SHORTCUTS] = LAYOUT_ortho_5x12(
  FIGDEV,   FIGGRD,   ZOOMOUT,  ZOOMIN,   GROUP,    QUITAPP,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  KC_BSPC,  SEARCH,   REFRSH,   SCRSHOT,  CHRMOB,   DUPLICT,            _______,  KC_PIPE,  KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_BSPC,
  ENTCTL,   SLCTALL,  INSP,     COPY,     PASTE,    CUT,                KC_CIRC,  KC_AMPR,  KC_LPRN,  KC_RPRN,  KC_SLSH,  MINCTL,
  REDO,     UNDO,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,           _______,  _______,  KC_LBRC,  KC_RBRC,  KC_EQL,   KC_UNDS,
  WFFPRV,   WFELMS,   FIGSLT,   ALTWINX,  ESCCMD,   KC_LGUI,            RAYCAST,  ESCCMD,   KC_LALT,  _______,  _______,  _______
),

[_SYMBOLS] = LAYOUT_ortho_5x12(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  KC_TILDE, KC_DQUO,  KC_LABK,  KC_RABK,  _______,  _______,            _______,  KC_7,     KC_8,     KC_9,     KC_0,     _______,
  KC_QUES,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            _______,  KC_4,     KC_5,     KC_6,     KC_MINS,  ZERCTL,
  ENTSFT,   KC_COLON, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,           KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,   _______,
  _______,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,            _______,  ESCCMD,   KC_0,     _______,  _______,  _______
),

[_ADJUST] =  LAYOUT_ortho_5x12(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  _______,  QK_BOOT,  RGB_TOG,  RGB_MOD,  RGB_HUD,  RGB_HUI,            RGB_SAD,  RGB_SAI,  RGB_VAD,  RGB_VAI,  _______,  KC_DEL,
  _______,  _______,  _______,  AU_ON,    AU_OFF,   AG_NORM,            AG_SWAP,  _______,  _______,  DVORAK,   _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______
)


};

#ifdef AUDIO_ENABLE
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case SHORTCUTS:
      if (record->event.pressed) {
        layer_on(_SHORTCUTS);
        update_tri_layer(_SHORTCUTS, _SYMBOLS, _ADJUST);
      } else {
        layer_off(_SHORTCUTS);
        update_tri_layer(_SHORTCUTS, _SYMBOLS, _ADJUST);
      }
      return false;
      break;
    case SYMBOLS:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        update_tri_layer(_SHORTCUTS, _SYMBOLS, _ADJUST);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer(_SHORTCUTS, _SYMBOLS, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DVORAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_SHORTCUTS] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_SYMBOLS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
