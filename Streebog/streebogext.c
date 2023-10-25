#include <stdlib.h>
#include <stdint.h>
#include "gost3411-2012-core.h"
#include "streebogext.h"

GOST34112012Context *streebog_new(void)
{
    return malloc(sizeof(GOST34112012Context));
}

void streebog_delete(GOST34112012Context *state)
{
    free(state);
    state = NULL;
}

RETURN_t streebog_init(GOST34112012Context *state, uint32_t bit_len)
{
    if (bit_len != 256u && bit_len != 512u)
    {
        return BAD_PARAM;
    }
    GOST34112012Init(state, bit_len);
}

void streebog_update(GOST34112012Context *state, void *input, size_t in_len)
{
    GOST34112012Update(state, input, in_len);
}

void streebog_final(GOST34112012Context *state, void *output, size_t out_len)
{
    if (out_len * 8 < state->digest_size)
    {
        return;
    }
    GOST34112012Final(state, output);
}
