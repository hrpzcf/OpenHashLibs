#include "xxhashext.h"
#include "xxh_x86dispatch.h"

// XXH32

XXH32_state_t *xxh32_new(void)
{
    return XXH32_createState();
}

XXH_errorcode xxh32_init(XXH32_state_t *state)
{
    return XXH32_reset(state, (XXH32_hash_t)0);
}

XXH_errorcode xxh32_update(XXH32_state_t *state, const void *input, size_t length)
{
    return XXH32_update(state, input, length);
}

XXH32_hash_t xxh32_final(const XXH32_state_t *state)
{
    return XXH32_digest(state);
}

XXH_errorcode xxh32_delete(XXH32_state_t *state)
{
    return XXH32_freeState(state);
}

// XXH64

XXH64_state_t *xxh64_new(void)
{
    return XXH64_createState();
}

XXH_errorcode xxh64_init(XXH64_state_t *state)
{
    return XXH64_reset(state, (XXH64_hash_t)0);
}

XXH_errorcode xxh64_update(XXH64_state_t *state, const void *input, size_t length)
{
    return XXH64_update(state, input, length);
}

XXH64_hash_t xxh64_final(const XXH64_state_t *state)
{
    return XXH64_digest(state);
}

XXH_errorcode xxh64_delete(XXH64_state_t *state)
{
    return XXH64_freeState(state);
}

// XXH3-64

XXH3_state_t *xxh3_64_new(void)
{
    return XXH3_createState();
}

XXH_errorcode xxh3_64_init(XXH3_state_t *state)
{
    return XXH3_64bits_reset(state);
}

XXH_errorcode xxh3_64_update(XXH3_state_t *state, const void *input, size_t length)
{
    return XXH3_64bits_update(state, input, length);
}

XXH64_hash_t xxh3_64_final(const XXH3_state_t *state)
{
    return XXH3_64bits_digest(state);
}

XXH_errorcode xxh3_64_delete(XXH3_state_t *state)
{
    return XXH3_freeState(state);
}

// XXH3-128

XXH3_state_t *xxh3_128_new(void)
{
    return XXH3_createState();
}

XXH_errorcode xxh3_128_init(XXH3_state_t *state)
{
    return XXH3_128bits_reset(state);
}

XXH_errorcode xxh3_128_update(XXH3_state_t *state, const void *input, size_t length)
{
    return XXH3_128bits_update(state, input, length);
}

XXH128_hash_t xxh3_128_final(const XXH3_state_t *state)
{
    return XXH3_128bits_digest(state);
}

XXH_errorcode xxh3_128_delete(XXH3_state_t *state)
{
    return XXH3_freeState(state);
}
