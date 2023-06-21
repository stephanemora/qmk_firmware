#include "combos.h"
#include "keymap_french.h"

enum combos {
  NE_FR_EACU,
  EI_FR_EGRV,
  LU_FR_EGRV,
  UY_FR_UGRV,
  AR_FR_AGRV,
  FP_FR_AGRV,
  CD_FR_CCED,
  Hcomma_FR_EGRV,

  XC_FR_UGRV,
  ST_FR_AGRV,

  WF_VIM_SAVE,
  WFP_VIM_ALL_SAVE,
  RST_VIM_ALL_SAVE,

  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM ne_combo[] = {FR_N, FR_E, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {FR_E, FR_I, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {FR_L, FR_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {FR_U, FR_Y, COMBO_END};
const uint16_t PROGMEM ar_combo[] = {FR_A, FR_R, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {FR_F, FR_P, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {FR_C, FR_D, COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {FR_H, FR_COMM, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {FR_X, FR_C, COMBO_END};
const uint16_t PROGMEM st_combo[] = {FR_S, FR_T, COMBO_END};

const uint16_t PROGMEM wf_combo[] = {FR_W, FR_F, COMBO_END};
const uint16_t PROGMEM wfp_combo[] = {FR_W, FR_F, FR_P, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {FR_R, FR_S, FR_T, COMBO_END};

combo_t key_combos[] = {
  [NE_FR_EACU]       = COMBO(ne_combo, FR_EACU),
  [EI_FR_EGRV]       = COMBO(ei_combo, FR_EGRV),
  [LU_FR_EGRV]       = COMBO(lu_combo, FR_EGRV),
  [UY_FR_UGRV]       = COMBO(uy_combo, FR_UGRV),
  [AR_FR_AGRV]       = COMBO(ar_combo, FR_AGRV),
  [FP_FR_AGRV]       = COMBO(fp_combo, FR_AGRV),
  [CD_FR_CCED]       = COMBO(cd_combo, FR_CCED),
  [Hcomma_FR_EGRV]   = COMBO(hcomma_combo, FR_EGRV),
  [XC_FR_UGRV]       = COMBO(xc_combo, FR_UGRV),
  [ST_FR_AGRV]       = COMBO(st_combo, FR_AGRV),

  [WF_VIM_SAVE]      = COMBO_ACTION(wf_combo),
  [WFP_VIM_ALL_SAVE] = COMBO_ACTION(wfp_combo),
  [RST_VIM_ALL_SAVE] = COMBO_ACTION(rst_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case WF_VIM_SAVE:
      if (pressed) {
        //SEND_STRING(":w");
        tap_code16(FR_COLN);
        tap_code16(FR_W);
        tap_code16(KC_ENT);
      }
      break;
    case RST_VIM_ALL_SAVE:
      if (pressed) {
        //SEND_STRING(":wall");
        tap_code16(FR_COLN);
        tap_code16(FR_W);
        tap_code16(FR_A);
        tap_code16(FR_L);
        tap_code16(FR_L);
        tap_code16(KC_ENT);
      }
      break;
  }
}

