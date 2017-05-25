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

            for (int w = 0; w < 4; w++)
                t->hasWallAt[w] = (bool) (rand() % 2);
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

int Maze::getSucessors(int row, int col, Tile *&result[]) const {

    if ( row < 0 || col < 0 || row >= rows || col >= cols )
        return -1;

    int sucessorCount = 0;

    Tile t = getTileAt(row, col);

    if (!t.hasWallAt[DIRECTION_LEFT] && col > 0) {
        result[DIRECTION_LEFT] = &getTileAt(row, col - 1);
        sucessorCount++;
    }

    if (!t.hasWallAt[DIRECTION_UP] && row > 0) {
        result[DIRECTION_UP] = &getTileAt(row - 1, col);
        sucessorCount++;
    }

    if (!t.hasWallAt[DIRECTION_RIGHT] && col < cols - 1) {
        result[DIRECTION_RIGHT] = &getTileAt(row, col + 1);
        sucessorCount++;
    }


    if (!t.hasWallAt[DIRECTION_DOWN] && row < rows - 1) {
        result[DIRECTION_LEFT] = &getTileAt(row + 1, col);
        sucessorCount++;
    }

    return sucessorCount;
}

