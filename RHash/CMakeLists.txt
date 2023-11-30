cmake_minimum_required(VERSION 3.27.0)
project(rhash VERSION 0.1.0)

include_directories("RHash/librhash")
set(src
    # for whirlpool algorithm
    "RHash/librhash/byte_order.c"
    "RHash/librhash/whirlpool.c"
    "RHash/librhash/whirlpool_sbox.c"
    # additional of many algorithms
    "additional.c"
)

add_library(${PROJECT_NAME} STATIC ${src})
