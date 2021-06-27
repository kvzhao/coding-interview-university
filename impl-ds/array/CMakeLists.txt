
cmake_minimum_required(VERSION 3.10)

project(array)

add_definitions(-std=c++14)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cc IVector.cc)
add_executable(arrays ${SOURCE_FILES})