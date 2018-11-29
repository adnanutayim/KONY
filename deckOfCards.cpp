#include "deckOfCards.h"
#include <time.h>
#include <iostream>

using std::endl;
using std::cout;

DeckOfCards::DeckOfCards(Card *deck) {
    deck[0] = Card(1, "Subterranean Cable", 0, "Discard", "+4 ENERGY_POINT and take 4 damage", 0, 4, -4); //IMPLEMENT
    deck[1] = Card(2, "Sharp Shooter", 4, "Keep", "You can destroy Jets that are not in your borough", 0, 0, 0);
    deck[2] = Card(3, "Tesla Cannon", 5, "Discard", "+2 VICTORY_POINT", 2, 0, 0); //IMPLEMENT
    deck[3] = Card(4, "Extra Head", 7, "Keep", "You get 1 extra die", 0, 0, 0);
    deck[4] = Card(5, "Ego Trip", 3, "Keep", "Gain 1 energy when you take superstar", 0, 0, 0);
    deck[5] = Card(6, "Hailing Cabs", 5, "Keep", "Take 2 dammage to your result", 0, 0, -2); //IMPLEMENT
    deck[6] = Card(7, "Next Stage", 4, "Discard", "Lose all your VICTORY_POINT.Gain 1 ENERGY_POINT VICTORY_POINT you lost this way.", -1, 0, 0); //IMPLEMENT
    deck[7] = Card(8, "Power Substation", 5, "Discard", "+1 victory point and +8 energies and take 3 dammage", 1, 8, 0); //IMPLEMENT
}

void DeckOfCards::shuffleDeck(Card *deck, const int SIZE_OF_DECK) {
    for (int i = 0; i < SIZE_OF_DECK; i++) {
        int random = (rand() + time(0)) % SIZE_OF_DECK;
        Card temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

void DeckOfCards::initializeBoard(Card *deck, Card *board, Card *&nextCard, const int SIZE_OF_BOARD) {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board[i] = deck[i];
        *nextCard++;
    }
}

void DeckOfCards::fillCard(Card *board, int userCard, Card *&nextCard) {
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

std::string DeckOfCards::showCard(Card *deck, int id, const int SIZE_OF_DECK){
    std::string output = "";
    for(int i = 0; i < SIZE_OF_DECK; i++){
        if(deck[i].getId() == id){
            output += deck[i].printCard();
        }
    }

    return output;
}
