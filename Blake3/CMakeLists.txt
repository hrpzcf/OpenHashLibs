cmake_minimum_required(VERSION 3.27)
project(blake3 VERSION 0.1.0 DESCRIPTION "BLAKE3 C implementation" LANGUAGES C ASM)

# default SIMD compiler flag configuration (can be overriden by toolchains or CLI)
if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    set(BLAKE3_CFLAGS_SSE2 "/arch:SSE2" CACHE STRING "the compiler flags to enable SSE2")
    # MSVC has no dedicated sse4.1 flag (see https://learn.microsoft.com/en-us/cpp/build/reference/arch-x86?view=msvc-170)
    set(BLAKE3_CFLAGS_SSE4.1 "/arch:AVX" CACHE STRING "the compiler flags to enable SSE4.1")
    set(BLAKE3_CFLAGS_AVX2 "/arch:AVX2" CACHE STRING "the compiler flags to enable AVX2")
    set(BLAKE3_CFLAGS_AVX512 "/arch:AVX512" CACHE STRING "the compiler flags to enable AVX512")
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(BLAKE3_CFLAGS_SSE2 "-msse2" CACHE STRING "the compiler flags to enable SSE2")
    set(BLAKE3_CFLAGS_SSE4.1 "-msse4.1" CACHE STRING "the compiler flags to enable SSE4.1")
    set(BLAKE3_CFLAGS_AVX2 "-mavx2" CACHE STRING "the compiler flags to enable AVX2")
    set(BLAKE3_CFLAGS_AVX512 "-mavx512f -mavx512vl" CACHE STRING "the compiler flags to enable AVX512")
endif()

# library target
add_library(${PROJECT_NAME}
    blake3.c
    blake3ext.c
    blake3_dispatch.c
    blake3_portable.c
)

# optional SIMD sources
macro(BLAKE3_DISABLE_SIMD)
    set(BLAKE3_SIMD_AMD64_ASM OFF)
    set(BLAKE3_SIMD_X86_INTRINSICS OFF)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        BLAKE3_NO_SSE2
        BLAKE3_NO_SSE41
        BLAKE3_NO_AVX2
        BLAKE3_NO_AVX512
    )
endmacro()

if((CMAKE_SIZEOF_VOID_P EQUAL 8) OR BLAKE3_USE_AMD64_ASM)
    set(BLAKE3_SIMD_AMD64_ASM ON)
    if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        enable_language(ASM_MASM)
        target_sources(${PROJECT_NAME} PRIVATE
            blake3_avx2_x86-64_windows_msvc.asm
            blake3_avx512_x86-64_windows_msvc.asm
            blake3_sse2_x86-64_windows_msvc.asm
            blake3_sse41_x86-64_windows_msvc.asm
        )
    elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
        if (WIN32)
            target_sources(${PROJECT_NAME} PRIVATE
                blake3_avx2_x86-64_windows_gnu.S
                blake3_avx512_x86-64_windows_gnu.S
                blake3_sse2_x86-64_windows_gnu.S
                blake3_sse41_x86-64_windows_gnu.S
            )
        else()
            BLAKE3_DISABLE_SIMD()
        endif()
    else()  
        BLAKE3_DISABLE_SIMD()
    endif()

elseif(((CMAKE_SIZEOF_VOID_P EQUAL 4) OR BLAKE3_USE_X86_INTRINSICS)
       AND DEFINED BLAKE3_CFLAGS_SSE2
       AND DEFINED BLAKE3_CFLAGS_SSE4.1
       AND DEFINED BLAKE3_CFLAGS_AVX2
       AND DEFINED BLAKE3_CFLAGS_AVX512)
    set(BLAKE3_SIMD_X86_INTRINSICS ON)
    target_sources(${PROJECT_NAME} PRIVATE
        blake3_avx2.c
        blake3_avx512.c
        blake3_sse2.c
        blake3_sse41.c
    )
    set_source_files_properties(blake3_avx2.c PROPERTIES COMPILE_FLAGS "${BLAKE3_CFLAGS_AVX2}")
    set_source_files_properties(blake3_avx512.c PROPERTIES COMPILE_FLAGS "${BLAKE3_CFLAGS_AVX512}")
    set_source_files_properties(blake3_sse2.c PROPERTIES COMPILE_FLAGS "${BLAKE3_CFLAGS_SSE2}")
    set_source_files_properties(blake3_sse41.c PROPERTIES COMPILE_FLAGS "${BLAKE3_CFLAGS_SSE4.1}")

else()
    BLAKE3_DISABLE_SIMD()
endif()
