cmake_minimum_required(VERSION 3.5)
project(dynamic-buffers)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB SOURCE_FILES "${SRC_DIR}/Demo.cpp")
add_executable(buffer_demo ${SOURCE_FILES})

include_directories(${SRC_DIR})
