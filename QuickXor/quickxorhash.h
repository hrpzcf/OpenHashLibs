#ifndef QUICKXOR_H_
#define QUICKXOR_H_

#include <stdint.h>

#if defined(__cplusplus)
extern "C"
{
#endif

#define QUICKXORHASH_SIZE 20
#define QUICKXORHASH_BLOCK_SIZE (20 * 11 * 8)

  typedef struct qxhash
  {
    uint8_t bytes[QUICKXORHASH_BLOCK_SIZE];
    uint64_t size;
  } qxhash_t;

  void qxhash_init(qxhash_t *ctx);
  void qxhash_update(qxhash_t *ctx, const uint8_t *data, size_t size);
  void qxhash_final(const qxhash_t *ctx, uint8_t *out);

#if defined(__cplusplus)
}
#endif

#endif // QUICKXOR_H_
