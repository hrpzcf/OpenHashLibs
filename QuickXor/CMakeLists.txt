cmake_minimum_required(VERSION 3.27.0)
project(quickxor VERSION 0.1.0)

include_directories(.)
aux_source_directory(. src)

add_library(${PROJECT_NAME} STATIC ${src})
