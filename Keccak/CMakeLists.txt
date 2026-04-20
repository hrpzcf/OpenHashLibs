cmake_minimum_required(VERSION 3.27.0)
project(keccak VERSION 0.1.0)

set(COMMON_INCLUDES
    "XKCP/lib/common"
    "XKCP/lib/high/Keccak"
    "XKCP/lib/high/Keccak/FIPS202"
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/common"
    "."
)

set(COMMON_FILES
    "XKCP/lib/high/Keccak/KeccakSponge.c"
    "XKCP/lib/high/Keccak/FIPS202/KeccakHash.c"
    "XKCP/lib/high/Keccak/FIPS202/SimpleFIPS202.c"
    "additional.c"
)

# ==============================================================================

set(GENERIC32_INCLUDES
    "XKCP/lib/low/KeccakP-1600/plain-32bits-inplace"
)

set(GENERIC32_FILES
    "XKCP/lib/low/KeccakP-1600/plain-32bits-inplace/KeccakP-1600-inplace32BI.c"
)

# ==============================================================================

set(GENERIC64_INCLUDES
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
    "XKCP/lib/low/KeccakP-1600/plain-64bits/lcua"
)
set(GENERIC64_FILES
    "XKCP/lib/low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c"
)

# ==============================================================================

set(AVX2_INCLUDES
    "XKCP/lib/low/KeccakP-1600/AVX2"
)

set(AVX2_FILES
    "XKCP/lib/low/KeccakP-1600/AVX2/KeccakP-1600-AVX2.s"
)

# ==============================================================================

set(AVX512_INCLUDES
    "XKCP/lib/low/KeccakP-1600/AVX512"
)

set(AVX512_FILES
    "XKCP/lib/low/KeccakP-1600/AVX512/KeccakP-1600-AVX512.s"
)

set(PREFERRED_INSTRUCTION "GENERIC")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit builds: select implementation based on PREFERRED_INSTRUCTION
    if ("${PREFERRED_INSTRUCTION}" STREQUAL "GENERIC")
        set(FILES ${COMMON_FILES} ${GENERIC64_FILES})
        set(INCLUDES ${COMMON_INCLUDES} ${GENERIC64_INCLUDES})
    elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX2")
        set(FILES ${COMMON_FILES} ${AVX2_FILES})
        set(INCLUDES ${COMMON_INCLUDES} ${AVX2_INCLUDES})
    elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX512")
        set(FILES ${COMMON_FILES} ${AVX512_FILES})
        set(INCLUDES ${COMMON_INCLUDES} ${AVX512_INCLUDES})
    else ()
        message(FATAL_ERROR "Invalid PREFERRED_INSTRUCTION: ${PREFERRED_INSTRUCTION}")
    endif ()
else ()
    # 32-bit builds: use plain-32bits-inplace implementation
    set(FILES ${COMMON_FILES} ${GENERIC32_FILES})
    set(INCLUDES ${COMMON_INCLUDES} ${GENERIC32_INCLUDES})
endif ()

# Enable assembly file support for MinGW/GCC
enable_language(ASM)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -x assembler-with-cpp -Wa,-defsym,old_gas_syntax=1")

add_library(${PROJECT_NAME} STATIC ${FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDES}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add compile options for SIMD instruction sets (only for 64-bit builds)
if ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX2" AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_options(${PROJECT_NAME} PRIVATE -mavx2 -mbmi2)
elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX512" AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_options(${PROJECT_NAME} PRIVATE -mavx512f -mavx512vl)
endif ()
