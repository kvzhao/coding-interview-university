cmake_minimum_required(VERSION 3.10)
project(linked_list)

add_definitions(-std=c++17)
add_definitions(-Werror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
    main.cc
    linked_list.cc
)

add_executable(ll ${SOURCE_FILES} ${HEADER_FILES})