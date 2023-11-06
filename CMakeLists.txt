cmake_minimum_required (VERSION 3.27.0)
project("hashalgs" VERSION 0.1.0)

set(USING_DEBUG_MODE 0)

if(NOT USING_DEBUG_MODE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/Output")
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$ENV{USERPROFILE}/AppData/Local/HashCalculator/Library")
endif()

add_subdirectory("Blake2")
add_subdirectory("Blake3")
add_subdirectory("CrcHash")
add_subdirectory("Keccak")
add_subdirectory("QuickXor")
add_subdirectory("Sha2")
add_subdirectory("Streebog")
add_subdirectory("Whirlpool")
add_subdirectory("XxHash")

add_library(${PROJECT_NAME} SHARED
    "hashalgs.c"
    "algexp.def"
)

target_link_libraries(${PROJECT_NAME}
    "-Wl,--whole-archive"
    blake2
    blake3
    crchash
    keccak
    quickxor
    sha2
    streebog
    whirlpool
    xxhash
    "-Wl,--no-whole-archive"
    -static-libgcc
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

if (USING_DEBUG_MODE)
    if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(FATAL_ERROR "@@@@@@ Please use a 64bit compiler")
    endif()
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "32.dll")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "64.dll")
else()
    message(FATAL_ERROR "Project ${PROJECT_NAME} compile fialed")
endif()
