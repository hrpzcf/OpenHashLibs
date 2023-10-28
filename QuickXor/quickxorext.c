#include <stdlib.h>
#include "quickxorhash.h"
#include "quickxorext.h"

qxhash_t *quickxor_new(void)
{
    return malloc(sizeof(qxhash_t));
}

void quickxor_init(qxhash_t *ctx)
{
    qxhash_init(ctx);
}

void quickxor_update(qxhash_t *ctx, const uint8_t *data, size_t size)
{
    qxhash_update(ctx, data, size);
}

void quickxor_final(const qxhash_t *ctx, uint8_t *out)
{
    qxhash_final(ctx, out);
}

void quickxor_delete(qxhash_t *state)
{
    free(state);
    state = NULL;
}
