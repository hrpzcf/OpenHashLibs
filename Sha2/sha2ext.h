#ifndef SHA2EXT_H_
#define SHA2EXT_H_

#include "Hacl_Hash_SHA2.h"

#ifndef EXPORT_DLL_FUNCS
    #define DllExport
#else
    #define DllExport __declspec(dllexport)
#endif

DllExport Hacl_Streaming_MD_state_32 *sha224_new(void);
DllExport void sha224_init(Hacl_Streaming_MD_state_32 *state);
DllExport Hacl_Streaming_Types_error_code sha224_update(Hacl_Streaming_MD_state_32 *state, void *input, uint32_t input_len);
DllExport void sha224_final(Hacl_Streaming_MD_state_32 *state, void *output, uint32_t output_len);
DllExport void sha224_delete(Hacl_Streaming_MD_state_32 *state);

#endif // SHA2EXT_H_
