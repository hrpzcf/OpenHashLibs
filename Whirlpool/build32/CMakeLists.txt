cmake_minimum_required(VERSION 3.27.0)
project(whirlpool_x86 VERSION 0.1.0)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -m32)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -m32)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../Output")

include_directories(..)
aux_source_directory(.. src)

add_library(whirlpool_x86 SHARED ${src})

set_target_properties(whirlpool_x86 PROPERTIES PREFIX "")
