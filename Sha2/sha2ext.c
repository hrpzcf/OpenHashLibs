#include <stdlib.h>
#include <string.h>
#include "Hacl_Hash_SHA2.h"

Hacl_Streaming_MD_state_32 *sha224_new(void)
{
    return Hacl_Streaming_SHA2_create_in_224();
}

void sha224_delete(Hacl_Streaming_MD_state_32 *state)
{
    Hacl_Streaming_SHA2_free_224(state);
}

void sha224_init(Hacl_Streaming_MD_state_32 *state)
{
    Hacl_Streaming_SHA2_init_224(state);
}

Hacl_Streaming_Types_error_code sha224_update(Hacl_Streaming_MD_state_32 *state, void *input, uint32_t input_len)
{
    return Hacl_Streaming_SHA2_update_224(state, input, input_len);
}

void sha224_final(Hacl_Streaming_MD_state_32 *state, void *output, uint32_t output_len)
{
    if (output_len < 224 / 8)
    {
        return;
    }
    Hacl_Streaming_SHA2_finish_224(state, output);
}
