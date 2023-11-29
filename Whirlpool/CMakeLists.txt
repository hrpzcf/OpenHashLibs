cmake_minimum_required(VERSION 3.27.0)
project(whirlpool VERSION 0.1.0)

include_directories(".")
set(src
    "whirlpool.c"
    "additional.c"
)

add_library(${PROJECT_NAME} STATIC ${src})
