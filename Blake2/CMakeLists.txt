cmake_minimum_required(VERSION 3.27.0)
project(blake2 VERSION 0.1.0)

include_directories("Blake2/sse")

add_library(${PROJECT_NAME} STATIC
    "Blake2/sse/blake2b.c"
    "Blake2/sse/blake2bp.c"
    "Blake2/sse/blake2s.c"
    "Blake2/sse/blake2sp.c"
    "Blake2/sse/blake2xb.c"
    "Blake2/sse/blake2xs.c"
    "additional.c"
)
