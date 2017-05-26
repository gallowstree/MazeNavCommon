//
// Created by Alvarado, Alejandro on 4/15/17.
//

#ifndef TEST_CLIENT_TILE_H
#define TEST_CLIENT_TILE_H


class Tile {
public:
    bool hasWallAt[4] = {false, false, false, false};
    int row;
    int col;

    Tile();

    virtual ~Tile();
};


#endif //TEST_CLIENT_TILE_H
