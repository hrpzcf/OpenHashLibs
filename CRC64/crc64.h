#ifndef CRC64_H_
#define CRC64_H_

#include <cstdint>

#if defined(__cplusplus)
extern "C"
{
#endif

    uint64_t crc64_update(uint64_t crc, const void *buf, size_t len);

#if defined(__cplusplus)
}
#endif

#endif // CRC64_H_
