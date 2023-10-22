cmake_minimum_required(VERSION 3.27.0)
project(blake2_x64 VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../Output")

include_directories(..)
aux_source_directory(.. src)

add_library(${PROJECT_NAME} SHARED ${src})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
