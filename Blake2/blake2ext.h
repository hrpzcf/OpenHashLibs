#ifndef BLAKE2EXT_H_
#define BLAKE2EXT_H_

#include "blake2.h"

#ifndef EXPORT_DLL_FUNCS
    #define DllExport
#else
    #define DllExport __declspec(dllexport)
#endif

DllExport blake2s_state *blake2s_new();
DllExport blake2sp_state *blake2sp_new();
DllExport blake2b_state *blake2b_new();
DllExport blake2bp_state *blake2bp_new();
DllExport blake2xs_state *blake2xs_new();
DllExport blake2xb_state *blake2xb_new();
DllExport void blake2_delete(void *state);

#endif // BLAKE2EXT_H_
