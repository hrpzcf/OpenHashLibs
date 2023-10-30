#ifndef STREEBOGEXT_H_
#define STREEBOGEXT_H_

#include "gost3411-2012-core.h"

GOST34112012Context *GOST34112012New(void);
void GOST34112012Delete(GOST34112012Context *state);

#endif // STREEBOGEXT_H_
