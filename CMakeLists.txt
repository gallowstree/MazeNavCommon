cmake_minimum_required(VERSION 3.6)
project(MazeNavCommon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HashMap.h HashNode.h Maze.h Maze.cpp Queue.h Stack.h Tile.h Tile.cpp MazeSerializer.cpp MazeSerializer.h Search.cpp Search.h)
add_library(MazeNavCommon ${SOURCE_FILES})
#add_executable(MazeNavCommon ${SOURCE_FILES})