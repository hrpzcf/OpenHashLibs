#ifndef QUICKXOREXT_H_
#define QUICKXOREXT_H_

#include "quickxorhash.h"

#ifndef EXPORT_DLL_FUNCS
    #define DllExport
#else
    #define DllExport __declspec(dllexport)
#endif

DllExport qxhash_t *quickxor_new(void);
DllExport void quickxor_init(qxhash_t *ctx);
DllExport void quickxor_update(qxhash_t *ctx, const uint8_t *data, size_t size);
DllExport void quickxor_final(const qxhash_t *ctx, uint8_t *out);
DllExport void quickxor_delete(qxhash_t *state);

#endif // QUICKXOREXT_H_
