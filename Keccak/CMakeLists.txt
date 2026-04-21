cmake_minimum_required(VERSION 3.27.0)
project(keccak VERSION 0.1.0)

set(HIGHLEVEL_INCLUDE
    "XKCP/lib/common"
    "XKCP/lib/high/Keccak"
    "XKCP/lib/high/Keccak/FIPS202"
    "."
)

set(HIGHLEVEL_SOURCES
    "XKCP/lib/high/Keccak/KeccakSponge.c"
    "XKCP/lib/high/Keccak/FIPS202/KeccakHash.c"
    "XKCP/lib/high/Keccak/FIPS202/SimpleFIPS202.c"
    "additional.c"
)

# ==============================================================================

set(GENERIC32_INCLUDE
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/plain-32bits-inplace"
)

set(GENERIC32_SOURCES
    "XKCP/lib/low/KeccakP-1600/plain-32bits-inplace/KeccakP-1600-inplace32BI.c"
)

# ==============================================================================

set(GENERIC64_INCLUDE_PURE
    "XKCP/lib/low/common"
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
)
set(GENERIC64_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600/plain-64bits/KeccakP-1600-opt64.c"
)

set(GENERIC64_INCLUDE
    ${GENERIC64_INCLUDE_PURE}
    "XKCP/lib/low/KeccakP-1600/plain-64bits/SnP"
)
set(GENERIC64_SOURCES
    ${GENERIC64_SOURCES_PURE}
)

# ==============================================================================

set(K1600X2_SIMD128_PURE
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128"
)
set(K1600X2_SSSE3_INCLUDE_PURE
    ${K1600X2_SIMD128_PURE}
)
set(K1600X2_SSSE3_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600-times2/SIMD128/KeccakP-1600-times2-SIMD128.c"
)
set_source_files_properties(${K1600X2_SSSE3_SOURCES_PURE} PROPERTIES
    COMPILE_FLAGS "-mssse3"
)

# ==============================================================================

set(AVX2_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600/AVX2"
)
set(AVX2_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600/AVX2/KeccakP-1600-AVX2.s"
)

set(AVX2_INCLUDE
    ${AVX2_INCLUDE_PURE}
    "XKCP/lib/low/KeccakP-1600/AVX2/SnP"
)
set(AVX2_SOURCES
    ${AVX2_SOURCES_PURE}
)

# ===========================================

set(K1600X4_AVX2_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600/common"
    "XKCP/lib/low/KeccakP-1600-times4/AVX2"
)
set(K1600X4_AVX2_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600-times4/AVX2/KeccakP-1600-times4-AVX2.c"
)
set_source_files_properties(${K1600X4_AVX2_SOURCES_PURE} PROPERTIES
    COMPILE_FLAGS "-mavx2"
)

# ==============================================================================

set(AVX512_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600/AVX512"
    "XKCP/lib/low/KeccakP-1600/plain-64bits"
)
set(AVX512_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600/AVX512/KeccakP-1600-AVX512.s"
)

set(AVX512_INCLUDE
    ${AVX512_INCLUDE_PURE}
    "XKCP/lib/low/KeccakP-1600/AVX512/SnP"
)
set(AVX512_SOURCES
    ${AVX512_SOURCES_PURE}
)

# ===========================================

set(K1600X2_AVX512_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600-times2/AVX512"
)
set(K1600X2_AVX512_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600-times2/AVX512/KeccakP-1600-times2-AVX512.c"
)
set_source_files_properties(${K1600X2_AVX512_SOURCES_PURE} PROPERTIES
    COMPILE_FLAGS "-mavx512f -mavx512vl"
)

# ===========================================

set(K1600X4_AVX512_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600-times4/AVX512"
)
set(K1600X4_AVX512_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600-times4/AVX512/KeccakP-1600-times4-AVX512.c"
)
set_source_files_properties(${K1600X4_AVX512_SOURCES_PURE} PROPERTIES
    COMPILE_FLAGS "-mavx512f -mavx512vl"
)

# ===========================================

set(K1600X8_AVX512_INCLUDE_PURE
    "XKCP/lib/low/KeccakP-1600-times8/AVX512"
)
set(K1600X8_AVX512_SOURCES_PURE
    "XKCP/lib/low/KeccakP-1600-times8/AVX512/KeccakP-1600-times8-AVX512.c"
)
set_source_files_properties(${K1600X8_AVX512_SOURCES_PURE} PROPERTIES
    COMPILE_FLAGS "-mavx512f -mavx512vl"
)

# ==============================================================================

set(K1600_X86_64_DISPATCH_INCLUDE
    "XKCP/lib/low/x86-64-dispatch"
)
set(K1600_X86_64_DISPATCH_SOURCES
    "XKCP/lib/low/x86-64-dispatch/x86-64-dispatch.c"
)

# ==============================================================================

set(PREFERRED_INSTRUCTION "DISPATCH")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit builds: select implementation based on PREFERRED_INSTRUCTION
    if ("${PREFERRED_INSTRUCTION}" STREQUAL "DISPATCH")
        set(SOURCES ${HIGHLEVEL_SOURCES}
            ${K1600_X86_64_DISPATCH_SOURCES}
            ${GENERIC64_SOURCES_PURE}
            ${AVX2_SOURCES_PURE}
            ${AVX512_SOURCES_PURE}
            ${K1600X2_SSSE3_SOURCES_PURE}
            ${K1600X2_AVX512_SOURCES_PURE}
            ${K1600X4_AVX2_SOURCES_PURE}
            ${K1600X4_AVX512_SOURCES_PURE}
            ${K1600X8_AVX512_SOURCES_PURE}
        )
        set(INCLUDES ${HIGHLEVEL_INCLUDE}
            ${K1600_X86_64_DISPATCH_INCLUDE}
            ${GENERIC64_INCLUDE_PURE}
            ${AVX2_INCLUDE_PURE}
            ${AVX512_INCLUDE_PURE}
            ${K1600X2_SSSE3_INCLUDE_PURE}
            ${K1600X2_AVX512_INCLUDE_PURE}
            ${K1600X4_AVX2_INCLUDE_PURE}
            ${K1600X4_AVX512_INCLUDE_PURE}
            ${K1600X8_AVX512_INCLUDE_PURE}
        )
    elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "GENERIC")
        set(SOURCES ${HIGHLEVEL_SOURCES} ${GENERIC64_SOURCES})
        set(INCLUDES ${HIGHLEVEL_INCLUDE} ${GENERIC64_INCLUDE})
    elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX2")
        set(SOURCES ${HIGHLEVEL_SOURCES} ${AVX2_SOURCES})
        set(INCLUDES ${HIGHLEVEL_INCLUDE} ${AVX2_INCLUDE})
    elseif ("${PREFERRED_INSTRUCTION}" STREQUAL "AVX512")
        set(SOURCES ${HIGHLEVEL_SOURCES} ${AVX512_SOURCES})
        set(INCLUDES ${HIGHLEVEL_INCLUDE} ${AVX512_INCLUDE})
    else ()
        message(FATAL_ERROR "Invalid PREFERRED_INSTRUCTION: ${PREFERRED_INSTRUCTION}")
    endif ()
else ()
    # 32-bit builds: use plain-32bits-inplace implementation
    set(SOURCES ${HIGHLEVEL_SOURCES} ${GENERIC32_SOURCES})
    set(INCLUDES ${HIGHLEVEL_INCLUDE} ${GENERIC32_INCLUDE})
endif ()

# Enable assembly file support for MinGW/GCC
enable_language(ASM)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -x assembler-with-cpp -Wa,-defsym,old_gas_syntax=1")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

if ((CMAKE_SIZEOF_VOID_P EQUAL 8) AND
    ("${PREFERRED_INSTRUCTION}" STREQUAL "DISPATCH"))
    # Add compile definitions
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        XKCP_has_x86_64_CPU_detection
    )
endif()
