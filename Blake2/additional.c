#include <stdlib.h>
#include "blake2.h"

void blake2_delete(void *state)
{
    free(state);
    state = NULL;
}

blake2s_state *blake2s_new()
{
    return malloc(sizeof(blake2s_state));
}

blake2sp_state *blake2sp_new()
{
    return malloc(sizeof(blake2sp_state));
}

blake2b_state *blake2b_new()
{
    return malloc(sizeof(blake2b_state));
}

blake2bp_state *blake2bp_new()
{
    return malloc(sizeof(blake2bp_state));
}

blake2xs_state *blake2xs_new()
{
    return malloc(sizeof(blake2xs_state));
}

blake2xb_state *blake2xb_new()
{
    return malloc(sizeof(blake2xb_state));
}
