#include <stdlib.h>
#include <string.h>
#include "KeccakHash.h"

Keccak_HashInstance *Keccak_New(void)
{
    return malloc(sizeof(Keccak_HashInstance));
}

void Keccak_Delete(Keccak_HashInstance *state)
{
    free(state);
    state = NULL;
}

HashReturn sha3_init(Keccak_HashInstance *state, int32_t bit_length)
{
    switch (bit_length)
    {
    case 224:
        return Keccak_HashInitialize_SHA3_224(state);
    case 256:
        return Keccak_HashInitialize_SHA3_256(state);
    case 384:
        return Keccak_HashInitialize_SHA3_384(state);
    case 512:
        return Keccak_HashInitialize_SHA3_512(state);
    default:
        return KECCAK_BAD_HASHLEN;
    }
}
