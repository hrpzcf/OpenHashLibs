#ifndef XXHASHEXT_H_
#define XXHASHEXT_H_

#include "xxhash.h"

// XXH32
XXH_errorcode XXH32_reset_noSeed(XXH32_state_t *state);
// XXH64
XXH_errorcode XXH64_reset_noSeed(XXH64_state_t *state);

#endif // XXHASHEXT_H_
