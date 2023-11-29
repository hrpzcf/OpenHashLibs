cmake_minimum_required(VERSION 3.27.0)
project(quickxor VERSION 0.1.0)

include_directories(
    "QuickXorHash"
)
set(src
    "QuickXorHash/quickxorhash.c"
    "additional.c"
)

add_library(${PROJECT_NAME} STATIC ${src})
