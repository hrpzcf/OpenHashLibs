#include <stdlib.h>
#include "gost12.h"
#include "sha256.h"
#include "whirlpool.h"

#if defined(_MSC_VER)
#define INLINE static __forceinline
#else
#define INLINE static inline __attribute__((always_inline))
#endif

INLINE void rhash_algo_delete(void *state)
{
    free(state);
    state = NULL;
}

sha256_ctx *rhash_sha224_new(void)
{
    return malloc(sizeof(sha256_ctx));
}

void rhash_sha224_delete(sha256_ctx *state)
{
    rhash_algo_delete(state);
}

whirlpool_ctx *rhash_whirlpool_new(void)
{
    return malloc(sizeof(whirlpool_ctx));
}

void rhash_whirlpool_delete(whirlpool_ctx *state)
{
    rhash_algo_delete(state);
}
