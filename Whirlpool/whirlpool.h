#ifndef HASH_WHIRLPOOL_H
#define HASH_WHIRLPOOL_H

#include <stdint.h>

#define DllExport __declspec(dllexport)

/*
 * Whirlpool-specific definitions.
 */

#define WHIRLPOOL_DIGESTBYTES 64
#define WHIRLPOOL_DIGESTBITS  (8*WHIRLPOOL_DIGESTBYTES) /* 512 */

#define WBLOCKBYTES 64
#define WBLOCKBITS  (8*WBLOCKBYTES) /* 512 */

#define LENGTHBYTES 32
#define LENGTHBITS  (8*LENGTHBYTES) /* 256 */

typedef struct WHIRLPOOLstruct
{
	unsigned char  bitLength[LENGTHBYTES]; /* global number of hashed bits (256-bit counter) */
	unsigned char  buffer[WBLOCKBYTES]; /* buffer of data to hash */
	int bufferBits;           /* current number of bits on the buffer */
	int bufferPos;            /* current (possibly incomplete) byte slot on the buffer */
	uint64_t hash[WHIRLPOOL_DIGESTBYTES / 8];    /* the hashing state */
} WHIRLPOOLstruct, whirlpool_state;


void WHIRLPOOLinit(struct WHIRLPOOLstruct* const structpointer);
void WHIRLPOOLadd(const unsigned char* const source, unsigned long sourceBits, struct WHIRLPOOLstruct* const structpointer);
void WHIRLPOOLfinalize(struct WHIRLPOOLstruct* const structpointer, unsigned char* const result);

DllExport void whirlpool_init(whirlpool_state* state);
DllExport void whirlpool_final(whirlpool_state* state, void* output, size_t outlen);
DllExport void whirlpool_update(whirlpool_state* state, const void* input, size_t inlen);
DllExport whirlpool_state* whirlpool_new();
DllExport void whirlpool_delete(whirlpool_state* state);

#endif
