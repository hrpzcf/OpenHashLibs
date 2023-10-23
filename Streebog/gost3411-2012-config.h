#ifndef CONFIG_H__
#define CONFIG_H__

#if defined(__SSE4_1__)
#define __GOST3411_HAS_SSE41__
#elif defined(__SSE2__)
#define __GOST3411_HAS_SSE2__
#elif defined(__MMX__)
#define __GOST3411_HAS_MMX__
#endif

#endif
