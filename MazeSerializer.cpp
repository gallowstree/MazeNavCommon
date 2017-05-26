//
// Created by Alvarado, Alejandro on 5/25/17.
//

#include <string.h>
#include "MazeSerializer.h"
#include <cstdio>

MazeSerializer::MazeSerializer() {

}

void MazeSerializer::toBinary(const Maze *maze, char* buffer) {
    memcpy(buffer, beginMazeMarker, strlen(beginMazeMarker));
    buffer[dimensionsOffset] = (char)maze->getRows();
    buffer[dimensionsOffset + 1] = (char)maze->getCols();

    int pos = 0;
    for (int row = 0; row < maze->getRows(); row++) {
        for (int col = 0; col < maze->getCols(); col+=2) {
            buffer[tilesOffset + pos++] = pack(maze->getTileAt(row, col), maze->getTileAt(row, col + 1));
        }
    }

    memcpy(buffer + tilesOffset + pos, endMazeMarker, strlen(endMazeMarker));
}

Maze *MazeSerializer::fromBinary(const char *buffer) {
    size_t rows = (size_t)buffer[dimensionsOffset];
    size_t cols = (size_t)buffer[dimensionsOffset + 1];

    Maze *m = new Maze(rows, cols);

    int pos = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col+=2) {
            unpack(buffer[tilesOffset + pos++], m->getTileAt(row, col), m->getTileAt(row, col + 1));
        }
    }

    return m;
}

char MazeSerializer::toBinary(const Tile *tile) {
    char result = 0;
    result |= ((int)tile->hasWallAt[DIRECTION_LEFT] << DIRECTION_LEFT);
    result |= ((int)tile->hasWallAt[DIRECTION_UP] << DIRECTION_UP);
    result |= ((int)tile->hasWallAt[DIRECTION_RIGHT] << DIRECTION_RIGHT);
    result |= ((int)tile->hasWallAt[DIRECTION_DOWN] << DIRECTION_DOWN);
    return result;
}

void MazeSerializer::unpack(char c, Tile* t1, Tile* t2) {

    t2->hasWallAt[DIRECTION_LEFT] = (bool)(c & (1 << DIRECTION_LEFT));
    t2->hasWallAt[DIRECTION_UP] = (bool)(c & (1 << DIRECTION_UP));
    t2->hasWallAt[DIRECTION_RIGHT] = (bool)(c & (1 << DIRECTION_RIGHT));
    t2->hasWallAt[DIRECTION_DOWN] = (bool)(c & (1 << DIRECTION_DOWN));

    c = c >> 4;
    t1->hasWallAt[DIRECTION_LEFT] = (bool)(c & (1 << DIRECTION_LEFT));
    t1->hasWallAt[DIRECTION_UP] = (bool)(c & (1 << DIRECTION_UP));
    t1->hasWallAt[DIRECTION_RIGHT] = (bool)(c & (1 << DIRECTION_RIGHT));
    t1->hasWallAt[DIRECTION_DOWN] = (bool)(c & (1 << DIRECTION_DOWN));
}

char MazeSerializer::pack(const Tile* t1, const Tile* t2) {
    return (toBinary(t1) << 4 | (toBinary(t2)));
}

size_t MazeSerializer::calculateSize(Maze *maze) {
    return tilesOffset + (maze->getRows() * maze->getCols()) / 2 + strlen(endMazeMarker);
}
