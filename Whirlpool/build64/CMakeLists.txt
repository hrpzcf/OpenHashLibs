cmake_minimum_required(VERSION 3.27.0)
project(whirlpool_x64 VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../Output")

include_directories(..)
aux_source_directory(.. src)

add_library(whirlpool_x64 SHARED ${src})

set_target_properties(whirlpool_x64 PROPERTIES PREFIX "")
