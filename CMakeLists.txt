cmake_minimum_required(VERSION 3.5)
project(dynamic-buffer)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
#add_compile_options(-O2)
#add_compile_options(-g)

file(GLOB SOURCE_FILES "${SRC_DIR}/Demo.cpp" "${SRC_DIR}/buffer.hpp")
add_executable(buffer_demo ${SOURCE_FILES})

include_directories(${SRC_DIR})
