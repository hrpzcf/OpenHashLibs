#include "xxhash.h"

// XXH32
XXH_errorcode XXH32_reset_noSeed(XXH32_state_t *state)
{
    return XXH32_reset(state, (XXH32_hash_t)0);
}

// XXH64
XXH_errorcode XXH64_reset_noSeed(XXH64_state_t *state)
{
    return XXH64_reset(state, (XXH64_hash_t)0);
}
