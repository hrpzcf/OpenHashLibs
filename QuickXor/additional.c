#include <stdlib.h>
#include "quickxorhash.h"

struct qxhash *qxhash_new(void)
{
    return malloc(sizeof(struct qxhash));
}

void qxhash_delete(struct qxhash *state)
{
    free(state);
    state = NULL;
}
