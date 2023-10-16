#include <stdlib.h>
#include <string.h>
#include "whirlpool.h"

whirlpool_state* whirlpool_new() {
	whirlpool_state* state = malloc(sizeof(whirlpool_state));
	return state;
}

void whirlpool_delete(whirlpool_state* state) {
	if (NULL != state) {
		free(state);
		state = NULL;
	}
}

void whirlpool_init(whirlpool_state* state) {
	WHIRLPOOLinit(state);
}

void whirlpool_final(whirlpool_state* state, void* output, size_t outlen) {
	if (outlen != WHIRLPOOL_DIGESTBYTES) {
		memset(output, 0, outlen);
	}
	else
	{
		WHIRLPOOLfinalize(state, output);
	}
}

void whirlpool_update(whirlpool_state* state, const void* input, size_t inlen) {
	WHIRLPOOLadd(input, inlen * 8, state);
}
