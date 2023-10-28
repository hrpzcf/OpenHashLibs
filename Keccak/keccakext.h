#ifndef KECCAKEXT_H_
#define KECCAKEXT_H_

#include "KeccakHash.h"

#ifndef EXPORT_DLL_FUNCS
    #define DllExport
#else
    #define DllExport __declspec(dllexport)
#endif

DllExport Keccak_HashInstance *keccak_new(void);
DllExport HashReturn sha3_init(Keccak_HashInstance *state, int32_t bit_size);
DllExport HashReturn sha3_update(Keccak_HashInstance *state, void *input, size_t in_size);
DllExport HashReturn sha3_final(Keccak_HashInstance *state, void *output, size_t out_size);
DllExport void keccak_delete(Keccak_HashInstance *state);

#endif // KECCAKEXT_H_
