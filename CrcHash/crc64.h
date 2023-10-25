#pragma once
#include <cstdint>

#if defined(__cplusplus)
extern "C"
{
#endif

    uint64_t crc64(uint64_t crc, const void *buf, size_t len);

#if defined(__cplusplus)
}
#endif
