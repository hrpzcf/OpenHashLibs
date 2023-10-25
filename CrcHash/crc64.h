#ifndef CRC64_H_
#define CRC64_H_

#include <cstdint>

#ifdef EXPORT_DLL_FUNCS
    #define DllExport __declspec(dllexport)
#else
    #define DllExport __declspec(dllimport)
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

    DllExport uint64_t crc64_update(uint64_t crc, const void *buf, size_t len);

#if defined(__cplusplus)
}
#endif

#endif // CRC64_H_
