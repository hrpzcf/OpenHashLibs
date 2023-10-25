#ifndef QUICKXOREXT_H_
#define QUICKXOREXT_H_

#include "quickxorhash.h"

#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

DllExport qxhash_t *qxhash_new(void);
DllExport void qxhash_init(qxhash_t *ctx);
DllExport void qxhash_update(qxhash_t *ctx, const uint8_t *data, size_t size);
DllExport void qxhash_final(const qxhash_t *ctx, uint8_t *out);
DllExport void qxhash_delete(qxhash_t *state);

#endif // QUICKXOREXT_H_
