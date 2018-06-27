cmake_minimum_required(VERSION 3.8)
project(Farmer)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/main.cpp src/util/CharSeq.cpp src/util/CharSeq.h)
add_executable(Farmer ${SOURCE_FILES})