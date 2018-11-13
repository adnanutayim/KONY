#ifndef DECKOFTILES_H
#define DECKOFTILES_H

#include "tile.h"

class DeckOfTiles{
private:
    Tile *nextTile;
public:
    DeckOfTiles(Tile*);
    ~DeckOfTiles();
    void shuffleTiles(Tile*, const int);
    std::string printDeckTiles(Tile*, const int);
    Tile dealTile();
    void flipTile(int, Tile*);
    void destroyTile(Tile*, int, Tile*&);
    bool isOutOfTiles();
};

#endif // DECKOFTILES_H
