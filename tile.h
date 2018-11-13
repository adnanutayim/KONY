#ifndef TILE_H
#define TILE_H

#include "side.h"
#include <iostream>
using namespace std;


class Tile{

private:
    int zone;
    int stack;
    int activeSide;
    Side side [2];




public:
    Tile();
    void setSide(int side, string name, int cost, int energy, int health, int victory);
    void setZone(int num);
    void setStack(int num);
    void setlocation(int zoneNum, int stackNum);
    void flip();
    bool isDestoryed();
};

#endif // TILE_H
