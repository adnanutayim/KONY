#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "diceroll.h"
#include "deckOfCards.h"
#include <diceroll.h>
#include "string.h"
#include "deckOfTiles.h"
#include "welcomescreen.h"

//using namespace std;

int main(int argc, char *argv[])
{
//    bool states[8] = {0, 1, 0, 1, 1, 1, 0, 0};
//    int values[8] = {6, 0, 6, 0, 0, 0, 0, 0};

//    diceRoll dice;

//    dice.rollDice(states, values);

//    for (int i = 0; i<8; i++){
//        cout << values[i] << endl;
//    };

//    DeckOfCards deck;
//    Card currentCard;
//    deck.printDeck();
//    deck.shuffleDeck();
//    cout << "\nSHUFFLE\n" << endl;
//    deck.printDeck();
//    cout << "\nDEAL\n" << endl;
//    currentCard = deck.dealCard();
//    cout << currentCard.printCard() << endl;

//    DeckOfTiles tileDeck;
//    Tile currentTile;
//    tileDeck.printDeckTiles();
//    tileDeck.shuffleTiles();
//    cout << "\nSHUFFLE\n" << endl;
//    tileDeck.printDeckTiles();
//    cout << "\nDEAL\n" << endl;
//    currentTile = tileDeck.dealTile();
//    cout << currentTile.printTile() << endl;
//    //when flipping tile specify which tile is being flipped
//    currentTile = tileDeck.flipTile(6);
//    cout << "\nFLIP\n" << endl;
//    cout << currentTile.printTile() << endl;
//    cout << "\nDESTROY\n" << endl;
//    currentTile = tileDeck.destroyTile(6);
//    cout << currentTile.printTile() << endl;


    QApplication a(argc, argv);
    welcomeScreen ws;
    ws.show();

    return a.exec();
}
