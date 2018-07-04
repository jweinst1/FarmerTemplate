cmake_minimum_required(VERSION 3.8)
project(Farmer)

set(CMAKE_CXX_STANDARD 98)
include_directories(src/util)
set(SOURCE_FILES src/main.cpp src/util/CharSeq.cpp src/util/CharSeq.h src/util/CharStream.cpp src/util/CharStream.h src/util/IndexUtil.h src/util/IndexedStream.h src/util/AbstractTree.h src/objects/Values.cpp src/objects/Values.h)
add_executable(Farmer ${SOURCE_FILES})