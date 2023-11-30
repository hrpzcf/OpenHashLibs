cmake_minimum_required(VERSION 3.27.0)
project(crc32 VERSION 0.1.0)

include_directories("CRC32")

set(src "CRC32/Crc32.cpp")

add_library(${PROJECT_NAME} STATIC ${src})
