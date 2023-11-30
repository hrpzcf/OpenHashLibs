cmake_minimum_required(VERSION 3.27.0)
project(sm3 VERSION 0.1.0)

include_directories("GmSSL/include")

add_library(${PROJECT_NAME} STATIC
    "GmSSL/src/sm3.c"
    "additional.c"
)
