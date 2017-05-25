//
// Created by Alvarado, Alejandro on 4/15/17.
//

#ifndef TEST_CLIENT_LABYRINTH_H
#define TEST_CLIENT_LABYRINTH_H


#include "Tile.h"

#define DIRECTION_LEFT 0
#define DIRECTION_UP 1
#define DIRECTION_RIGHT 2
#define DIRECTION_DOWN 3

class Maze {

private:
    Tile **tiles;
    size_t rows = 10;
    size_t cols = 10;
    int tileSize = 20;

public:
    Maze(size_t rows, size_t cols);
    Tile& getTileAt(int row, int col) const;


    //The third parameter expects a reference to an array of Tile pointers, which will be populated
    //with the successors of the tile at row, col. This array should be of size 4, as this is the max
    //number of successors without diagonal movement. Returns the number of successors or -1 if invalid params.
    int getSuccessors(int row, int col, Tile* (&result)[]) const;

    size_t getRows() const;
    size_t getCols() const;
};


#endif //TEST_CLIENT_LABYRINTH_H
