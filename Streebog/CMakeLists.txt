cmake_minimum_required(VERSION 3.27.0)
project(streebog VERSION 0.1.0)

include_directories(
    "Streebog"
    "."
)

add_library(${PROJECT_NAME} STATIC
    "Streebog/gost3411-2012-core.c"
    "additional.c"
)

# 不建议启用 SSE4.1，会比当前默认 SSE2 慢。
# 如果要启用 SSE4.1，还要修改 gost3411-2012-core.c 的第 97 行，
# #ifdef __GOST3411_HAS_SSE2__ 改为：
# #if defined(__GOST3411_HAS_SSE2__) || defined(__GOST3411_HAS_SSE41__)
# 作者不用的原因可能是 SSE4.1 的实现方式有问题导致性能差。
# target_compile_options(${PROJECT_NAME} PRIVATE
#     -msse4.1
# )
