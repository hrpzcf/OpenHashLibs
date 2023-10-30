#include <stdlib.h>
#include "whirlpool.h"
#include "whirlpoolext.h"

WhirlpoolState *WHIRLPOOLnew()
{
    return malloc(sizeof(WhirlpoolState));
}

void WHIRLPOOLdelete(WhirlpoolState *state)
{
    free(state);
    state = NULL;
}
