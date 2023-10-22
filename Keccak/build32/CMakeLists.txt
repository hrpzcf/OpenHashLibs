cmake_minimum_required(VERSION 3.27.0)
project(keccak_x86 VERSION 0.1.0)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -m32)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -m32)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../../Output")

set(COMMON_FILES
        ../keccakext.c
        ../high/Keccak/FIPS202/KeccakHash.c
        ../high/Keccak/FIPS202/SimpleFIPS202.c
        ../high/Keccak/KeccakSponge.c
        )

set(AVX_FILES
        ../low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c
        ../low/KeccakP-1600-times2/SIMD128/KeccakP-1600-times2-SIMD128.c
        )

set(AVX2_FILES
        ../low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c
        ../low/KeccakP-1600-times2/SIMD128/KeccakP-1600-times2-SIMD128.c
        ../low/KeccakP-1600-times4/AVX2/KeccakP-1600-times4-SIMD256.c
        )

set(AVX512_FILES
        ../low/KeccakP-1600/AVX512/C/KeccakP-1600-AVX512.c
        ../low/KeccakP-1600-times2/AVX512/KeccakP-1600-times2-SIMD512.c
        ../low/KeccakP-1600-times4/AVX512/KeccakP-1600-times4-SIMD512.c
        ../low/KeccakP-1600-times8/AVX512/KeccakP-1600-times8-SIMD512.c
        )

set(GENERIC_FILES
        ../low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c
        )

set(COMMON_INCLUDES
        ..
        ../common
        ../high/common
        ../high/Keccak
        ../high/Keccak/FIPS202
        )

set(AVX_INCLUDES
        ../low/common
        ../low/KeccakP-1600/common
        ../low/KeccakP-1600/plain-64bits
        ../low/KeccakP-1600/plain-64bits/lcua-shld
        ../low/KeccakP-1600-times2/SIMD128
        ../low/KeccakP-1600-times2/SIMD128/SSSE3-ua
        )

set(AVX2_INCLUDES
        ../low/common
        ../low/KeccakP-1600/common
        ../low/KeccakP-1600/plain-64bits
        ../low/KeccakP-1600/plain-64bits/ua
        ../low/KeccakP-1600-times2/SIMD128
        ../low/KeccakP-1600-times2/SIMD128/SSSE3-u2
        ../low/KeccakP-1600-times4/AVX2
        ../low/KeccakP-1600-times4/AVX2/u12
        )

set(AVX512_INCLUDES
        ../low/KeccakP-1600/AVX512/C/u12
        ../low/KeccakP-1600/AVX512/C
        ../low/KeccakP-1600-times2/AVX512
        ../low/KeccakP-1600-times2/AVX512/AVX512u12
        ../low/KeccakP-1600-times4/AVX512
        ../low/KeccakP-1600-times4/AVX512/AVX512u12
        ../low/KeccakP-1600-times8/AVX512
        ../low/KeccakP-1600-times8/AVX512/u12
        )

set(GENERIC_INCLUDES
        ../low/common
        ../low/KeccakP-1600/common
        ../low/KeccakP-1600/plain-64bits
        ../low/KeccakP-1600/plain-64bits/ua
        )

if ("${OHT_FLAVOR}" STREQUAL "SSE2")
    set(FILES ${COMMON_FILES} ${GENERIC_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${GENERIC_INCLUDES})
elseif ("${OHT_FLAVOR}" STREQUAL "AVX")
    set(FILES ${COMMON_FILES} ${AVX_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX_INCLUDES})
elseif ("${OHT_FLAVOR}" STREQUAL "AVX2")
    set(FILES ${COMMON_FILES} ${AVX2_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX2_INCLUDES})
elseif ("${OHT_FLAVOR}" STREQUAL "AVX512")
    set(FILES ${COMMON_FILES} ${AVX512_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX512_INCLUDES})
else ()
    message(FATAL_ERROR "OHT_FLAVOR not set.")
endif ()

add_library(${PROJECT_NAME} SHARED ${FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR})
