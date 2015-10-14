cmake_minimum_required(VERSION 3.3)
project(remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/duplicate_element.cpp
    src/duplicate_element.h
        src/main.cpp
    src/search.h src/merge_sort.cpp src/merge_sort.h src/max.cpp src/max.h src/poll.cpp src/poll.h)

add_executable(remake ${SOURCE_FILES})