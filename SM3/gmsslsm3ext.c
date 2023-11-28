#include <stdlib.h>
#include "gmssl/sm3.h"
#include "gmsslsm3ext.h"

SM3_CTX *sm3_new(void)
{
    return malloc(sizeof(SM3_CTX));
}

void sm3_delete(SM3_CTX *state)
{
    free(state);
    state = NULL;
}
