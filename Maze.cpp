#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include "Maze.h"

Tile& Maze::getTileAt(int row, int col)const {
    return this->tiles[row][col];
}

Maze::Maze(size_t rows, size_t cols) : cols(cols),
                                       rows(rows)
{
    this->tiles = new Tile*[rows];
    srand(time(0));

    for (int r = 0; r < rows; r++)
    {
        this->tiles[r] = new Tile[cols];
        for (int c = 0; c < cols; c++)
        {
            Tile* t = new Tile();
            t->row = r;
            t->col = c;

            t->hasWallAt[DIRECTION_UP] = r == 0;
            t->hasWallAt[DIRECTION_DOWN] = r == rows - 1;
            t->hasWallAt[DIRECTION_LEFT] = c == 0;
            t->hasWallAt[DIRECTION_RIGHT] = c == cols - 1;

//            bool hasWall = r == rows - 1 && c == 0;
//            t->hasWallAt[DIRECTION_UP] = hasWall;
//            t->hasWallAt[DIRECTION_DOWN] = hasWall;
//            t->hasWallAt[DIRECTION_LEFT] = hasWall;
//            t->hasWallAt[DIRECTION_RIGHT] = hasWall;


            tiles[r][c] = *t;
        }
    }
}

size_t Maze::getRows()const {
    return this->rows;
}


size_t Maze::getCols()const {
    return this->cols;
}

int Maze::getSuccessors(int row, int col, Tile* (&result)[]) const {

    if ( row < 0 || col < 0 || row >= rows || col >= cols )
        return -1;

    int successorCount = 0;

    Tile t = getTileAt(row, col);

    if (!t.hasWallAt[DIRECTION_LEFT] && col > 0) {
        result[DIRECTION_LEFT] = &getTileAt(row, col - 1);
        successorCount++;
    }

    if (!t.hasWallAt[DIRECTION_UP] && row > 0) {
        result[DIRECTION_UP] = &getTileAt(row - 1, col);
        successorCount++;
    }

    if (!t.hasWallAt[DIRECTION_RIGHT] && col < cols - 1) {
        result[DIRECTION_RIGHT] = &getTileAt(row, col + 1);
        successorCount++;
    }

    if (!t.hasWallAt[DIRECTION_DOWN] && row < rows - 1) {
        result[DIRECTION_DOWN] = &getTileAt(row + 1, col);
        successorCount++;
    }

    return successorCount;
}

