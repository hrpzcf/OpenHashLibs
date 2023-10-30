#include <stdlib.h>
#include "gost3411-2012-core.h"
#include "streebogext.h"

GOST34112012Context *GOST34112012New(void)
{
    return malloc(sizeof(GOST34112012Context));
}

void GOST34112012Delete(GOST34112012Context *state)
{
    free(state);
    state = NULL;
}
