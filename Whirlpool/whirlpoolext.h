#ifndef WHIRLPOOLEXT_H_
#define WHIRLPOOLEXT_H_

#include <stdint.h>
#include "whirlpool.h"

#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

DllExport whirlpool_state* whirlpool_new();
DllExport void whirlpool_init(whirlpool_state* state);
DllExport void whirlpool_final(whirlpool_state* state, void* output, size_t outlen);
DllExport void whirlpool_update(whirlpool_state* state, const void* input, size_t inlen);
DllExport void whirlpool_delete(whirlpool_state* state);

#endif // WHIRLPOOLEXT_H_
