#ifndef DECKOFTILES_H
#define DECKOFTILES_H

#include "tile.h"

class DeckOfTiles{
private:
    Tile *tiles;
    int numOfTiles;
    Tile createTile(int type);
    void shuffleTiles();
    void dealTiles();
    int numOfZones;
    int stacksPerZone;

public:
    DeckOfTiles();
    ~DeckOfTiles();

};

#endif // DECKOFTILES_H
