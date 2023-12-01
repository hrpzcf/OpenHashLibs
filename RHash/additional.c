#include <stdlib.h>
#include "ed2k.h"
#include "has160.h"
#include "md4.h"
#include "ripemd-160.h"
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

// ed2k
ed2k_ctx *rhash_ed2k_new(void)
{
    return malloc(sizeof(ed2k_ctx));
}

void rhash_ed2k_delete(ed2k_ctx *state)
{
    rhash_algo_delete(state);
}

// has160
has160_ctx *rhash_has160_new(void)
{
    return malloc(sizeof(has160_ctx));
}

void rhash_has160_delete(has160_ctx *state)
{
    rhash_algo_delete(state);
}

// md4
md4_ctx *rhash_md4_new(void)
{
    return malloc(sizeof(md4_ctx));
}

void rhash_md4_delete(md4_ctx *state)
{
    rhash_algo_delete(state);
}

// ripemd160
ripemd160_ctx *rhash_ripemd160_new(void)
{
    return malloc(sizeof(ripemd160_ctx));
}

void rhash_ripemd160_delete(ripemd160_ctx *state)
{
    rhash_algo_delete(state);
}

// sha224
sha256_ctx *rhash_sha224_new(void)
{
    return malloc(sizeof(sha256_ctx));
}

void rhash_sha224_delete(sha256_ctx *state)
{
    rhash_algo_delete(state);
}

// whirlpool
whirlpool_ctx *rhash_whirlpool_new(void)
{
    return malloc(sizeof(whirlpool_ctx));
}

void rhash_whirlpool_delete(whirlpool_ctx *state)
{
    rhash_algo_delete(state);
}
