#ifndef BLAKE2EXT_H_
#define BLAKE2EXT_H_

#include "blake2.h"

blake2s_state *blake2s_new();
blake2sp_state *blake2sp_new();
blake2b_state *blake2b_new();
blake2bp_state *blake2bp_new();
blake2xs_state *blake2xs_new();
blake2xb_state *blake2xb_new();

void blake2_delete(void *state);

#endif // BLAKE2EXT_H_
