cmake_minimum_required(VERSION 3.27.0)
project(xxhash VERSION 0.1.0)

include_directories("xxHash")
set(src
    "xxHash/xxhash.c"
    "xxHash/xxh_x86dispatch.c"
    "additional.c"
)

add_library(${PROJECT_NAME} STATIC ${src})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    XXH_DEBUGLEVEL=0
    XXH_FORCE_MEMORY_ACCESS=1
)
