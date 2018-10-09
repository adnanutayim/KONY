#include "deckOfCards.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

const int SIZE_OF_DECK = 5; //should be deck of 64

deckOfCards::deckOfCards(){
    deck = new card[SIZE_OF_DECK];
    currentCard = 0;
    deck[0] = card("1", "freeze", "keep");
    deck[1] = card("2", "burn", "discard");
    deck[2] = card("3", "capture", "discard");
    deck[3] = card("4", "shield", "keep");
    deck[4] = card("5", "sword", "keep");
}

void deckOfCards::shuffleDeck(){
    for(int i = 0; i < SIZE_OF_DECK; i++){
        int random = (rand() + time(0)) % SIZE_OF_DECK;
        card temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

void deckOfCards::printDeck() const {
    for(int i = 0; i < SIZE_OF_DECK; i++){
        cout << deck[i].printCard() << endl;
    }
}

card deckOfCards::dealCard(){
    //no more cards, deck needs to be reshuffled
    if(currentCard > SIZE_OF_DECK)
     shuffleDeck();

    if(currentCard < SIZE_OF_DECK)
        return(deck[currentCard++]);

    //give the top card
    return (deck[0]);
}



