#include <stdlib.h>
#include "additional.h"
#include "blake3.h"

blake3_hasher *blake3_hasher_new(void)
{
    return malloc(sizeof(blake3_hasher));
}

void blake3_hasher_delete(blake3_hasher *self)
{
    free(self);
    self = NULL;
}
