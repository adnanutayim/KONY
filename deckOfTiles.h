#ifndef DECKOFTILES_H
#define DECKOFTILES_H

#include "tile.h"

class DeckOfTiles{
private:
    Tile *tileDeck;
    int currentTile;
public:
    DeckOfTiles();
    ~DeckOfTiles();
    void shuffleTiles();
    void printDeckTiles();
    Tile dealTile();
    Tile flipTile(int);
    Tile destroyTile(int);
    bool isOutOfTiles();
};

#endif // DECKOFTILES_H
