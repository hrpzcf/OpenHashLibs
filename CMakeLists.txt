cmake_minimum_required (VERSION 3.27.0)
project ("OpenHashLibs")

add_subdirectory("./Blake2/build32")
add_subdirectory("./Blake2/build64")

add_subdirectory("./Whirlpool/build32")
add_subdirectory("./Whirlpool/build64")
