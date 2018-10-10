#include "deckOfCards.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

const int SIZE_OF_DECK = 5; //should be deck of 64

DeckOfCards::DeckOfCards(){
    deck = new Card[SIZE_OF_DECK];
    currentCard = 0;
    //Have a file with all the cards and read it
    deck[0] = Card("1", "keep", "freeze");
    deck[1] = Card("2", "discard", "burn");
    deck[2] = Card("3", "discard", "heal");
    deck[3] = Card("4", "keep", "skip");
    deck[4] = Card("5", "discard", "fly");
}

DeckOfCards::~DeckOfCards(){

}

void DeckOfCards::shuffleDeck(){
    for(int i = 0; i < SIZE_OF_DECK; i++){
        int random = (rand() + time(0)) % SIZE_OF_DECK;
        Card temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

void DeckOfCards::printDeck() const {
    for(int i = 0; i < SIZE_OF_DECK; i++){
        cout << deck[i].printCard() << endl;
    }
}

Card DeckOfCards::dealCard(){
    //no more cards, deck needs to be reshuffled
    if(currentCard > SIZE_OF_DECK)
     shuffleDeck();

    if(currentCard < SIZE_OF_DECK)
        return(deck[currentCard++]);

    //give the top card
    return (deck[0]);
}



