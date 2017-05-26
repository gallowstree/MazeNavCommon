//
// Created by Alvarado, Alejandro on 5/25/17.
//

#ifndef TEST_CLIENT_MAZESERIALIZER_H
#define TEST_CLIENT_MAZESERIALIZER_H

#include "Maze.h"

#define MARKER_BEGIN_MAZE "3.14"
#define DIMENSIONS_OFFSET 4
#define TILE_OFFSET DIMENSIONS_OFFSET +

const char beginMazeMarker[] = "3.14";
const  size_t dimensionsOffset = strlen(beginMazeMarker); //Length of MARKER_BEGIN_MAZE
const  size_t tilesOffset = dimensionsOffset + 2; //Dimension block takes one byte for rows, one for cols
const char endMazeMarker[] = "420!";


class MazeSerializer {
public:
      MazeSerializer();
      char toBinary(const Tile* tile);
      void toBinary(const Maze *maze, char *buffer);
      Maze* fromBinary(const char* buffer);

    char pack(const Tile *t1, const Tile *t2);

    size_t calculateSize(Maze *maze);


    void unpack(char c, Tile *t1, Tile *t2);
};


#endif //TEST_CLIENT_MAZESERIALIZER_H
