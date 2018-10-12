#include "deckOfTiles.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

const int NUM_OF_TILES = 7;

DeckOfTiles::DeckOfTiles(){
//Initialize deck of tiles, 45 tiles, 15 of each building type, 5 of each durability (unit)?
    tileDeck = new Tile[NUM_OF_TILES];
    currentTile = 0;
//Tile::Tile(Buildings b, int d, Units u, Rewards rt, int nor, int z, bool iu)
    tileDeck[0] = Tile(HighRise, 1, Star, 1, 1, false);
    tileDeck[1] = Tile(HighRise, 2, Star, 2, 3, false);
    tileDeck[2] = Tile(HighRise, 3, Star, 3, 5, false);
    tileDeck[3] = Tile(Hospital, 2, Heart, 2, 2, false);
    tileDeck[4] = Tile(Hospital, 3, Heart, 3, 4, false);
    tileDeck[5] = Tile(PowerPlant, 2, Energy, 2, 1, false);
    tileDeck[6] = Tile(PowerPlant, 3, Energy, 3, 5, false);

}
DeckOfTiles::~DeckOfTiles(){
//delete the tile array
}

void DeckOfTiles::shuffleTiles(){
    for(int i = 0; i < NUM_OF_TILES; i++){
        int random = (rand() + time(0)) % NUM_OF_TILES;
        Tile temp = tileDeck[i];
        tileDeck[i] = tileDeck[random];
        tileDeck[random] = temp;
    }
}

std::string DeckOfTiles::printDeckTiles(){
    std::string out = "";
    for(int i = 0; i < NUM_OF_TILES; i++){
        out += tileDeck[i].printTile() + "\n--------------------\n";
//        cout << tileDeck[i].printTile() << endl;
    }

    return out;
}

Tile DeckOfTiles::dealTile(){
    //no more cards, deck needs to be reshuffled
    if(currentTile > NUM_OF_TILES)
     shuffleTiles();

    if(currentTile < NUM_OF_TILES)
        return(tileDeck[currentTile++]);

    //give the top card
    return (tileDeck[0]);
}

//Maybe use pointers?
Tile DeckOfTiles::flipTile(int tileNum){
    Tile t = tileDeck[tileNum];
    switch (t.getDurability()) {
    case 1: t.setRewardType(Heart); t.setUnit(Infantry); break;
    case 2: t.setRewardType(Energy); t.setUnit(Jet); break;
    case 3: t.setRewardType(Star); t.setUnit(Tank); break;
    }

    int dur = t.getDurability();
    dur++;
    t.setDurability(dur);
    t.setIsUnit(true);

    //sets the tile in the deck to be a unit
    tileDeck[tileNum] = t;

    return(t);
}

//Maybe use pointers?
Tile DeckOfTiles::destroyTile(int tileNum){
    Tile t = tileDeck[tileNum];
    t.setIsDestroyed(true);
    return (t);
}

bool DeckOfTiles::isOutOfTiles(){
    if(currentTile >= NUM_OF_TILES)
        return true;
    return false;
}
