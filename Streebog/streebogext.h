#ifndef STREEBOGEXT_H_
#define STREEBOGEXT_H_

#include <stdint.h>
#include "gost3411-2012-core.h"

#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

typedef enum
{
    OK,
    BAD_PARAM,
    FAIL,
} RETURN_t;

DllExport GOST34112012Context *streebog_new(void);
DllExport RETURN_t streebog_init(GOST34112012Context *state, uint32_t bit_len);
DllExport void streebog_update(GOST34112012Context *state, void *input, size_t in_len);
DllExport void streebog_final(GOST34112012Context *state, void *output, size_t out_len);
DllExport void streebog_delete(GOST34112012Context *state);

#endif // STREEBOGEXT_H_
