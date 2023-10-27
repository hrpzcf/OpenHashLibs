#ifndef XXHASHEXT_H_
#define XXHASHEXT_H_

#include "xxh_x86dispatch.h"

#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

DllExport XXH32_state_t *xxh32_new(void);
DllExport XXH_errorcode xxh32_init(XXH32_state_t *state);
DllExport XXH_errorcode xxh32_update(XXH32_state_t *state, const void *input, size_t length);
DllExport XXH32_hash_t xxh32_final(const XXH32_state_t *state);
DllExport XXH_errorcode xxh32_delete(XXH32_state_t *state);

// XXH64

DllExport XXH64_state_t *xxh64_new(void);
DllExport XXH_errorcode xxh64_init(XXH64_state_t *state);
DllExport XXH_errorcode xxh64_update(XXH64_state_t *state, const void *input, size_t length);
DllExport XXH64_hash_t xxh64_final(const XXH64_state_t *state);
DllExport XXH_errorcode xxh64_delete(XXH64_state_t *state);

// XXH3-64

DllExport XXH3_state_t *xxh3_64_new(void);
DllExport XXH_errorcode xxh3_64_init(XXH3_state_t *state);
DllExport XXH_errorcode xxh3_64_update(XXH3_state_t *state, const void *input, size_t length);
DllExport XXH64_hash_t xxh3_64_final(const XXH3_state_t *state);
DllExport XXH_errorcode xxh3_64_delete(XXH3_state_t *state);

// XXH3-128

DllExport XXH3_state_t *xxh3_128_new(void);
DllExport XXH_errorcode xxh3_128_init(XXH3_state_t *state);
DllExport XXH_errorcode xxh3_128_update(XXH3_state_t *state, const void *input, size_t length);
DllExport XXH128_hash_t xxh3_128_final(const XXH3_state_t *state);
DllExport XXH_errorcode xxh3_128_delete(XXH3_state_t *state);

#endif // XXHASHEXT_H_
