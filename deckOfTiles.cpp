#include "deckOfTiles.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

DeckOfTiles::DeckOfTiles(Tile *tileDeck){
    tileDeck[0] = Tile(HighRise, 1, Star, 1, 2, false);
    tileDeck[1] = Tile(HighRise, 2, Star, 2, 3, false);
    tileDeck[2] = Tile(HighRise, 3, Star, 3, 4, false);
    tileDeck[3] = Tile(Hospital, 2, Heart, 2, 5, false);
    tileDeck[4] = Tile(Hospital, 3, Heart, 3, 2, false);
    tileDeck[5] = Tile(Hospital, 3, Heart, 3, 3, false);
    tileDeck[6] = Tile(Hospital, 3, Heart, 3, 4, false);
    tileDeck[7] = Tile(Hospital, 3, Heart, 3, 5, false);
    tileDeck[8] = Tile(PowerPlant, 2, Energy, 2, 2, false);
    tileDeck[9] = Tile(PowerPlant, 2, Energy, 2, 3, false);
    tileDeck[10] = Tile(PowerPlant, 2, Energy, 2, 4, false);
    tileDeck[11] = Tile(PowerPlant, 2, Energy, 2, 5, false);
    tileDeck[12] = Tile(PowerPlant, 3, Energy, 3, 2, false);
}
DeckOfTiles::~DeckOfTiles(){

}

void DeckOfTiles::shuffleTiles(Tile *tileDeck, const int NUM_OF_TILES){
    for(int i = 0; i < NUM_OF_TILES; i++){
        int random = (rand() + time(0)) % NUM_OF_TILES;
        Tile temp = tileDeck[i];
        tileDeck[i] = tileDeck[random];
        tileDeck[random] = temp;
    }
}

std::string DeckOfTiles::printDeckTiles(Tile *tileDeck, const int NUM_OF_TILES){
    std::string out = "";
    for(int i = 0; i < NUM_OF_TILES; i++){
        out += tileDeck[i].printTile() + "\n--------------------\n";
    }
    return out;
}

//Tile DeckOfTiles::dealTile(){
//    //no more cards, deck needs to be reshuffled
//    if(currentTile >= NUM_OF_TILES)
//     shuffleTiles();

//    if(currentTile < NUM_OF_TILES)
//        return(tileDeck[currentTile++]);

//    //give the top card
//    return (tileDeck[0]);
//}


void DeckOfTiles::flipTile(int tileNum, Tile *tileDeck){
    switch (tileDeck[tileNum].getDurability()) {
    case 1: tileDeck[tileNum].setRewardType(Heart); tileDeck[tileNum].setUnit(Infantry); break;
    case 2: tileDeck[tileNum].setRewardType(Energy); tileDeck[tileNum].setUnit(Jet); break;
    case 3: tileDeck[tileNum].setRewardType(Star); tileDeck[tileNum].setUnit(Tank); break;
    }

    int dur = tileDeck[tileNum].getDurability();
    dur++;
    tileDeck[tileNum].setDurability(dur);
    tileDeck[tileNum].setIsUnit(true);
}

//Maybe use pointers?
void DeckOfTiles::destroyTile(Tile *tileDeck, int userTile, Tile *&nextCard){
    tileDeck[userTile].setIsDestroyed(true);
}

//bool DeckOfTiles::isOutOfTiles(){
//    if(currentTile >= NUM_OF_TILES)
//        return true;
//    return false;
//}
