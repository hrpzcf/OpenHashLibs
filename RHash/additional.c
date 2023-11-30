#include <stdlib.h>
#include "gost12.h"
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

whirlpool_ctx *rhash_whirlpool_new(void)
{
    return malloc(sizeof(whirlpool_ctx));
}

void rhash_whirlpool_delete(whirlpool_ctx *state)
{
    rhash_algo_delete(state);
}
