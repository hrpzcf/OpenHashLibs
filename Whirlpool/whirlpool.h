#ifndef HASH_WHIRLPOOL_H
#define HASH_WHIRLPOOL_H

#include <stdint.h>

/*
 * Whirlpool-specific definitions.
 */

#define WHIRLPOOL_DIGESTBYTES 64
#define WHIRLPOOL_DIGESTBITS (8 * WHIRLPOOL_DIGESTBYTES) /* 512 */

#define WBLOCKBYTES 64
#define WBLOCKBITS (8 * WBLOCKBYTES) /* 512 */

#define LENGTHBYTES 32
#define LENGTHBITS (8 * LENGTHBYTES) /* 256 */

typedef struct
{
    unsigned char bitLength[LENGTHBYTES];     /* global number of hashed bits (256-bit counter) */
    unsigned char buffer[WBLOCKBYTES];        /* buffer of data to hash */
    int bufferBits;                           /* current number of bits on the buffer */
    int bufferPos;                            /* current (possibly incomplete) byte slot on the buffer */
    uint64_t hash[WHIRLPOOL_DIGESTBYTES / 8]; /* the hashing state */
} WhirlpoolStruct;

void whirlpool_init(WhirlpoolStruct *const structptr);
void whirlpool_update(WhirlpoolStruct *const structptr, const unsigned char *const source, uint64_t sourceBytes);
void whirlpool_final(WhirlpoolStruct *const structptr, unsigned char *const result);

#endif
