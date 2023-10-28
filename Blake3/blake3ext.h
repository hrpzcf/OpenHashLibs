#ifndef BLAKE3EXT_H_
#define BLAKE3EXT_H_

#include "blake3.h"

#ifndef EXPORT_DLL_FUNCS
    #define DllExport
#else
    #define DllExport __declspec(dllexport)
#endif

DllExport blake3_hasher *blake3_new(void);
DllExport void blake3_init(blake3_hasher *self);
DllExport void blake3_update(blake3_hasher *self, const void *input, size_t input_len);
DllExport void blake3_final(const blake3_hasher *self, uint8_t *output, size_t output_len);
DllExport void blake3_delete(blake3_hasher *self);

#endif // BLAKE3EXT_H_
