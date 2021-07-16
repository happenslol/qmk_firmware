#pragma once

#include "quantum.h"

/* ONIBOX Keymap Definition Macro */

#define LAYOUT_all(\
    K00, K01, K02, K03,            K42,      \
    K10,                       K41,    K43,  \
    K11,   K20, K21,       K40,    K32,      \
    K12,             K22,      K31,    K33,  \
    K13,                   K30,              \
                        K23                  \
) { \
    { K00,  K01,  K02,  K03  }, \
    { K10,  K11,  K12,  K13  }, \
    { K20,  K21,  K22,  K23  }, \
    { K30,  K31,  K32,  K33  }, \
    { K40,  K41,  K42,  K43  }  \
}
