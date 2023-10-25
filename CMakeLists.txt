cmake_minimum_required (VERSION 3.27.0)
project("bridge" VERSION 0.1.0)

add_definitions(-DEXPORT_DLL_FUNCS)

set(OHT_FLAVOR "SSE2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/Output")

add_subdirectory("Blake2")
add_subdirectory("CrcHash")
add_subdirectory("Keccak")
add_subdirectory("QuickXor")
add_subdirectory("Sha2")
add_subdirectory("Streebog")
add_subdirectory("Whirlpool")

add_library(${PROJECT_NAME} SHARED "bridge.c")

target_link_libraries(${PROJECT_NAME}
        "-Wl,--whole-archive"
        blake2
        crchash
        keccak
        quickxor
        sha2
        streebog
        whirlpool
        "-Wl,--no-whole-archive"
    )

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

if (CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_x86.dll")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_x64.dll")
else()
    message(FATAL_ERROR "Project ${PROJECT_NAME} compile fialed")
endif()
