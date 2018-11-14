#include "deckOfTiles.h"
#include <time.h>
#include <iostream>
#include "game.h"
#include "time.h"

using std::endl;
using std::cout;

DeckOfTiles::DeckOfTiles(){

    // Initialization
    numOfZones = Game::getInstance()->getMap()->getGraph()->getNumOfNodes() - 1;
    stacksPerZone = 3;
    int tilesPerStack = 3;
    numOfTiles = numOfZones * stacksPerZone * tilesPerStack;

    tiles = new Tile [numOfTiles];

    // Create Tiles
    for (int i = 0; i < numOfTiles; i++) {
        tiles[i] = createTile(i);
    }

    shuffleTiles();
    dealTiles();

}

DeckOfTiles::~DeckOfTiles() {
    delete [] tiles;
    tiles = NULL;
}

Tile DeckOfTiles::createTile(int type) {

    Tile t;
    if (type % 3 == 0) {
        // HighRise/Infantry
        t.setSide(0, "High Rise", 1, 0, 0, 2);
        t.setSide(1, "Infantry", 1, 0, 2, 0);

    } else if (type % 3 == 1) {
        // Hospital/Jet
        t.setSide(0, "Hospital", 3, 0, 3, 0);
        t.setSide(1, "Jet", 3, 2, 0, 0);

    } else if (type % 3 == 2) {
        // Powerplant/Tank
        t.setSide(0, "Power Plant", 3, 3, 0, 0);
        t.setSide(1, "Tank", 4, 0, 0, 3);

    }

    return t;
}


void DeckOfTiles::shuffleTiles() {
    srand (time(NULL));
    for (int i = 0; i < numOfTiles; i++) {
        int j = rand() % numOfTiles;
        // swap i & j
        Tile temp = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = temp;
    }
}

void DeckOfTiles::dealTiles() {
    // Round-Robin dealing
    for (int i = 0; i < numOfTiles; i++) {
        tiles[i].setZone((i % numOfZones) + 1);
        tiles[i].setStack(i % 3);
    }
}

int DeckOfTiles::getNumOfTiles() {
    return numOfTiles;
}

Tile* DeckOfTiles::getTiles() {
    return tiles;
}
