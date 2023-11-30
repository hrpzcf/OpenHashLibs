cmake_minimum_required(VERSION 3.27.0)
project(crchash VERSION 0.1.0)

set(src
    "crc32.cpp"
    "crc64.cpp"
)

add_library(${PROJECT_NAME} STATIC ${src})
