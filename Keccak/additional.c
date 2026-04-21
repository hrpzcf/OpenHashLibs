#include <stdlib.h>
#include <string.h>
#include "KeccakHash.h"

#ifdef XKCP_has_x86_64_CPU_detection
    #include "x86-64-dispatch.h"
#endif

Keccak_HashInstance *Keccak_New(void)
{
#ifdef XKCP_has_x86_64_CPU_detection
    static int cpu_features_initialized = 0;
    if (!cpu_features_initialized)
    {
        XKCP_EnableAllCpuFeatures();
        cpu_features_initialized = 1;
    }
#endif
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
