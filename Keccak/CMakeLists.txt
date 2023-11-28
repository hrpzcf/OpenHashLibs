cmake_minimum_required(VERSION 3.27.0)
project(keccak VERSION 0.1.0)

set(PREFERRED_INSTRUCTION "SSE2")

set(COMMON_FILES
    "XKCP/lib/high/Keccak/KeccakSponge.c"
    "XKCP/lib/high/Keccak/FIPS202/KeccakHash.c"
    "XKCP/lib/high/Keccak/FIPS202/SimpleFIPS202.c"
    "additional.c"
)

set(AVX_FILES
    "XKCP/lib/low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128/KeccakP-1600-times2-SIMD128.c"
)

set(AVX2_FILES
    "XKCP/lib/low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128/KeccakP-1600-times2-SIMD128.c"
    "XKCP/lib/low/KeccakP-1600-times4/AVX2/KeccakP-1600-times4-SIMD256.c"
)

set(AVX512_FILES
    "XKCP/lib/low/KeccakP-1600/AVX512/C/KeccakP-1600-AVX512.c"
    "XKCP/lib/low/KeccakP-1600-times2/AVX512/KeccakP-1600-times2-SIMD512.c"
    "XKCP/lib/low/KeccakP-1600-times4/AVX512/KeccakP-1600-times4-SIMD512.c"
    "XKCP/lib/low/KeccakP-1600-times8/AVX512/KeccakP-1600-times8-SIMD512.c"
)

set(GENERIC_FILES
    "XKCP/lib/low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c"
)

set(COMMON_INCLUDES
    "XKCP/lib/common"
    "XKCP/lib/high/common"
    "XKCP/lib/high/Keccak"
    "XKCP/lib/high/Keccak/FIPS202"
    "."
)

set(AVX_INCLUDES
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
    "XKCP/lib/low/KeccakP-1600/plain-64bits/lcua-shld"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128/SSSE3-ua"
)

set(AVX2_INCLUDES
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
    "XKCP/lib/low/KeccakP-1600/plain-64bits/ua"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128/SSSE3-u2"
    "XKCP/lib/low/KeccakP-1600-times4/AVX2"
    "XKCP/lib/low/KeccakP-1600-times4/AVX2/u12"
)

set(AVX512_INCLUDES
    "XKCP/lib/low/KeccakP-1600/AVX512/C/u12"
    "XKCP/lib/low/KeccakP-1600/AVX512/C"
    "XKCP/lib/low/KeccakP-1600-times2/AVX512"
    "XKCP/lib/low/KeccakP-1600-times2/AVX512/AVX512u12"
    "XKCP/lib/low/KeccakP-1600-times4/AVX512"
    "XKCP/lib/low/KeccakP-1600-times4/AVX512/AVX512u12"
    "XKCP/lib/low/KeccakP-1600-times8/AVX512"
    "XKCP/lib/low/KeccakP-1600-times8/AVX512/u12"
)

set(GENERIC_INCLUDES
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
    "XKCP/lib/low/KeccakP-1600/plain-64bits/ua"
)

if ("${PREFERRED_INSTRUCTION}" STREQUAL "SSE2")
    set(FILES ${COMMON_FILES} ${GENERIC_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${GENERIC_INCLUDES})
elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX")
    set(FILES ${COMMON_FILES} ${AVX_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX_INCLUDES})
elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX2")
    set(FILES ${COMMON_FILES} ${AVX2_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX2_INCLUDES})
elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX512")
    set(FILES ${COMMON_FILES} ${AVX512_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${AVX512_INCLUDES})
else ()
    message(FATAL_ERROR "PREFERRED_INSTRUCTION not set.")
endif ()

add_library(${PROJECT_NAME} STATIC ${FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDES}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
