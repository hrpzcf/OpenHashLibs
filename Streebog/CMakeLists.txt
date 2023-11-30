cmake_minimum_required(VERSION 3.27.0)
project(streebog VERSION 0.1.0)

include_directories(
    "Streebog"
    "."
)

add_library(${PROJECT_NAME} STATIC
    "Streebog/gost3411-2012-core.c"
    "additional.c"
)
