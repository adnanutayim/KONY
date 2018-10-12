#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "card.h"
#include <string>

class DeckOfCards
{

private:
    Card *deck;
    int currentCard;
public:
    DeckOfCards();
    ~DeckOfCards();
    void shuffleDeck();
    std::string printDeck() const;
    Card dealCard();
};

#endif // DECKOFCARDS_H
