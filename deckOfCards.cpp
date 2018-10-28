#include "deckOfCards.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

DeckOfCards::DeckOfCards() {

}

void DeckOfCards::shuffleDeck(Card *deck, const int SIZE_OF_DECK) {
    for (int i = 0; i < SIZE_OF_DECK; i++) {
        int random = (rand() + time(0)) % SIZE_OF_DECK;
        Card temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

void DeckOfCards::initializeBoard(Card *deck, Card *board, Card *&nextCard) {
    for (int i = 0; i < 3; i++) {
        board[i] = deck[i];
        *nextCard++;
    }
}

void DeckOfCards::fillCard(Card *deck, Card *board, int userCard, Card *&nextCard) {
    board[userCard] = *nextCard;
    *nextCard++;
}

std::string DeckOfCards::printDeck(Card *deck, const int SIZE_OF_DECK) {
    std::string output = "";
    for (int i = 0; i < SIZE_OF_DECK; i++) {
        output += deck[i].printCard() + "\n--------------------\n";
    }
    return output;
}

std::string DeckOfCards::printBoard(Card *board, const int SIZE_OF_BOARD) {
    std::string output = "";
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        output += board[i].printCard() + "\n--------------------\n";
    }
    return output;
}

//const int SIZE_OF_DECK = 5; //should be deck of 64

//DeckOfCards::DeckOfCards(){
//    deck = new Card[SIZE_OF_DECK];
//    currentCard = 0;
//    //Have a file with all the cards and read it
//    deck[0] = Card("Violent Star", 3, "Keep", "Deal 2 dammage to the monster...");
//    deck[1] = Card("Sharp Shooter", 4, "Keep", "You destroy Jets that are not in...");
//    deck[2] = Card("Of Another World", 6, "Keep", "You can use hearts as energy and energy as hearts");
//    deck[3] = Card("Extra Head", 7, "Keep", "You get 1 extra die");
//    deck[4] = Card("Ego Trip", 3, "Keep", "Gain 1 energy when you take superstar");
//}

//DeckOfCards::~DeckOfCards(){

//}

//void DeckOfCards::shuffleDeck(){
//    currentCard = 0;
//    for(int i = 0; i < SIZE_OF_DECK; i++){
//        int random = (rand() + time(0)) % SIZE_OF_DECK;
//        Card temp = deck[i];
//        deck[i] = deck[random];
//        deck[random] = temp;
//    }
//}

//std::string DeckOfCards::printDeck() const {
//    std::string output = "";
//    for(int i = 0; i < SIZE_OF_DECK; i++){
//        output += deck[i].printCard() + "\n--------------------\n";
//    }
//    return output;
//}

//Card DeckOfCards::dealCard(){
//    //no more cards, deck needs to be reshuffled
//    if(currentCard >= SIZE_OF_DECK)
//        shuffleDeck();

//    if(currentCard < SIZE_OF_DECK)
//        return(deck[currentCard++]);

//    //give the top card
//    return (deck[0]);
//}



