cmake_minimum_required(VERSION 3.10)
project(merge_sort)

add_definitions(-std=c++17)
add_definitions(-Werror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
	main.cc
	merge_sort.cc
)

add_executable(merge_sort ${SOURCE_FILES} ${HEADER_FILES})