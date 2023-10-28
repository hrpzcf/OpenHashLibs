#include <stdlib.h>
#include "blake3.h"
#include "blake3ext.h"

blake3_hasher *blake3_new(void)
{
    return malloc(sizeof(blake3_hasher));
}

void blake3_init(blake3_hasher *self)
{
    blake3_hasher_init(self);
}

void blake3_update(blake3_hasher *self, const void *input, size_t input_len)
{
    blake3_hasher_update(self, input, input_len);
}

void blake3_final(const blake3_hasher *self, uint8_t *output, size_t output_len)
{
    blake3_hasher_finalize(self, output, output_len);
}

void blake3_delete(blake3_hasher *self)
{
    free(self);
    self = NULL;
}
