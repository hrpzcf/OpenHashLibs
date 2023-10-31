#include <stdlib.h>
#include "whirlpool.h"
#include "whirlpoolext.h"

WhirlpoolStruct *whirlpool_new()
{
    return malloc(sizeof(WhirlpoolStruct));
}

void whirlpool_delete(WhirlpoolStruct *state)
{
    free(state);
    state = NULL;
}
