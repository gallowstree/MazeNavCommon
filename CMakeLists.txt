cmake_minimum_required(VERSION 3.6)
project(MazeNavCommon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HashMap.h)
add_executable(MazeNavCommon ${SOURCE_FILES})