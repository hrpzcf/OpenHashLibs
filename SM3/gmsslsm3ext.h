#ifndef GMSSLSM3EXT_H_
#define GMSSLSM3EXT_H_

#include "gmssl/sm3.h"

SM3_CTX *sm3_new(void);
void sm3_delete(SM3_CTX *state);

#endif // GMSSLSM3EXT_H_
