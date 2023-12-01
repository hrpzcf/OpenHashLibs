cmake_minimum_required(VERSION 3.27.0)
project(rhash VERSION 0.1.0)

include_directories("RHash/librhash")

add_library(${PROJECT_NAME} STATIC
    # common files
    "RHash/librhash/byte_order.c"
    # for ed2k algorithm
    "RHash/librhash/ed2k.c"
    # for md4/ed2k algorithm
    "RHash/librhash/md4.c"
    # for ripemd160 algorithm
    "RHash/librhash/ripemd-160.c"
    # for sha224 algorithm
    "RHash/librhash/sha256.c"
    # for whirlpool algorithm
    "RHash/librhash/whirlpool.c"
    "RHash/librhash/whirlpool_sbox.c"
    # additional of many algorithms
    "additional.c"
)
