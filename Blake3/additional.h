#ifndef BLAKE3EXT_H_
#define BLAKE3EXT_H_

#include "blake3.h"

blake3_hasher *blake3_hasher_new(void);
void blake3_hasher_delete(blake3_hasher *self);

#endif // BLAKE3EXT_H_
