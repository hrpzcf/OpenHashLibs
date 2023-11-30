#include <stdlib.h>
#include <string.h>
#include "KeccakHash.h"

Keccak_HashInstance *keccak_new(void)
{
    return malloc(sizeof(Keccak_HashInstance));
}

void keccak_delete(Keccak_HashInstance *state)
{
    free(state);
    state = NULL;
}

HashReturn sha3_init(Keccak_HashInstance *state, int32_t bit_size)
{
    switch (bit_size)
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

HashReturn sha3_update(Keccak_HashInstance *state, void *input, size_t in_size)
{
    return Keccak_HashUpdate(state, input, in_size * 8);
}

HashReturn sha3_final(Keccak_HashInstance *state, void *output, size_t out_size)
{
    if (out_size * 8 < state->fixedOutputLength)
    {
        return KECCAK_BAD_HASHLEN;
    }
    return Keccak_HashFinal(state, output);
}
