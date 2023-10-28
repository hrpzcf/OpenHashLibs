#include <stdlib.h>
#include <string.h>
#include "whirlpool.h"
#include "whirlpoolext.h"

whirlpool_state *whirlpool_new()
{
    return malloc(sizeof(whirlpool_state));
    ;
}

void whirlpool_init(whirlpool_state *state)
{
    WHIRLPOOLinit(state);
}

void whirlpool_update(whirlpool_state *state, const void *input, size_t inlen)
{
    WHIRLPOOLadd(input, inlen * 8, state);
}

void whirlpool_final(whirlpool_state *state, void *output, size_t outlen)
{
    if (outlen != WHIRLPOOL_DIGESTBYTES)
    {
        return;
    }
    WHIRLPOOLfinalize(state, output);
}

void whirlpool_delete(whirlpool_state *state)
{
    free(state);
    state = NULL;
}
