#ifndef QUICKXOREXT_H_
#define QUICKXOREXT_H_

#include "quickxorhash.h"

struct qxhash *qxhash_new(void);
void qxhash_delete(struct qxhash *state);

#endif // QUICKXOREXT_H_
