#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "diceroll.h"
#include "deckOfCards.h"
#include <diceroll.h>
#include "string.h"
#include "deckOfTiles.h"

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

//    deckOfCards deck;
//    card currentCard;
//    deck.printDeck();
//    deck.shuffleDeck();
//    cout << "shuffle" << endl;
//    deck.printDeck();
//    cout << "deal top card to player" << endl;
//    currentCard = deck.dealCard();
//    cout << currentCard.printCard() << endl;

//    DeckOfTiles tileDeck;
//    Tile currentTile;
//    tileDeck.printDeckTiles();
//    tileDeck.shuffleTiles();
//    cout << "shuffle" << endl;
//    tileDeck.printDeckTiles();
//    cout << "deal" << endl;
//    currentTile = tileDeck.dealTile();
//    cout << currentTile.printTile() << endl;
//    //when flipping tile specify which tile is being flipped
//    currentTile = tileDeck.flipTile(6);
//    cout << "flip" << endl;
//    cout << currentTile.printTile() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
