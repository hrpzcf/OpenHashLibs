cmake_minimum_required (VERSION 3.27.0)
project ("OpenHashLibs")

set(OHT_FLAVOR "SSE2")

add_subdirectory("./Blake2/build32")
add_subdirectory("./Blake2/build64")

add_subdirectory("./CrcHash/build32")
add_subdirectory("./CrcHash/build64")

add_subdirectory("./Keccak/build32")
add_subdirectory("./Keccak/build64")

add_subdirectory("./QuickXor/build32")
add_subdirectory("./QuickXor/build64")

add_subdirectory("./Sha2/build32")
add_subdirectory("./Sha2/build64")

add_subdirectory("./Streebog/build32")
add_subdirectory("./Streebog/build64")

add_subdirectory("./Whirlpool/build32")
add_subdirectory("./Whirlpool/build64")
