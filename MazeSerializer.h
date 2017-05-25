//
// Created by Alvarado, Alejandro on 5/25/17.
//

#ifndef TEST_CLIENT_MAZESERIALIZER_H
#define TEST_CLIENT_MAZESERIALIZER_H

#include "Maze.h"

class MazeSerializer {
public:
      MazeSerializer();
      char* toBinary(Maze* maze);
      Maze* fromBinary(char* buffer);
};


#endif //TEST_CLIENT_MAZESERIALIZER_H
