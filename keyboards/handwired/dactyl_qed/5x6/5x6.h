#pragma once

#include "dactyl_manuform.h"
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVX__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

#define X__ KC_NO

#define LAYOUT_5x6(\
  L00, L01, L02, L03, L04, L05,         R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,         R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,         R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34,                   R30, R31, R32, R33, R34, \
                      L40, L41,         R40, R41,                     \
                 L42, L43, L44,         R42, R43, R44                 \
  ) \
  { \
/*        0    1    2    3    4    5  */ \
/* 0 */ { L00, L01, L02, L03, L04, L05 }, \
/* 1 */ { L10, L11, L12, L13, L14, L15 }, \
/* 2 */ { L20, L21, L22, L23, L24, L25 }, \
/* 3 */ { L30, L31, L32, L34, L43, L40 }, \
/* 4 */ { X__, X__, L33, L42, L44, L41 }, \
/*        0    1    2    3    4    5  */  \
/* 0 */ { R05, R04, R03, R02, R01, R00 }, \
/* 1 */ { R15, R14, R13, R12, R11, R10 }, \
/* 2 */ { R25, R24, R23, R22, R21, R20 }, \
/* 3 */ { R34, R33, R32, R30, R43, R41 }, \
/* 4 */ { X__, X__, R31, R44, R42, R40 } \
}
