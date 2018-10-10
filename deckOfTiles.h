#ifndef DECKOFTILES_H
#define DECKOFTILES_H

#include "tile.h"

class DeckOfTiles{
private:
    Tile deckOfTiles[45];
    int currentTile;
public:
    DeckOfTiles();
    ~DeckOfTiles();
    void shuffleTiles();
    void printDeckTiles();
    void dealTile();
    void flipTile(Tile*);
    void destroyTile(Tile*);
    bool isOutOfTiles();
};

#endif // DECKOFTILES_H
