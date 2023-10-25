#include <stdlib.h>
#include "quickxorhash.h"
#include "quickxorext.h"

qxhash_t *qxhash_new(void)
{
    return malloc(sizeof(qxhash_t));
}

void qxhash_delete(qxhash_t *state)
{
    free(state);
    state = NULL;
}
