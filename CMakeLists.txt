cmake_minimum_required (VERSION 3.27.0)
project("hashalgs" VERSION 1.0.0)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/../HashCalculator/Costura-win-x86")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/../HashCalculator/Costura-win-x64")
else()
    message(FATAL_ERROR "Project ${PROJECT_NAME} compile fialed")
endif()

add_subdirectory("Blake2")
add_subdirectory("Blake3")
add_subdirectory("CRC32")
add_subdirectory("CRC64")
add_subdirectory("Keccak")
add_subdirectory("QuickXor")
add_subdirectory("RHash")
add_subdirectory("SM3")
add_subdirectory("Streebog")
add_subdirectory("XxHash")

add_library(${PROJECT_NAME} SHARED "algexp.def")

target_link_libraries(${PROJECT_NAME}
    "-Wl,--whole-archive"
    blake2
    blake3
    crc32
    crc64
    keccak
    quickxor
    rhash
    sm3
    streebog
    xxhash
    "-Wl,--no-whole-archive"
    -static-libgcc
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
