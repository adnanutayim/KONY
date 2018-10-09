#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <string>

class deckOfCards
{

private:
    card *deck;
    int currentCard;
public:
    deckOfCards();
    void shuffleDeck();
    void printDeck() const;
    card dealCard();
};

#endif // DECK_H
