#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "card.h"
#include <string>

class DeckOfCards
{
public:
    DeckOfCards(Card*);
    void shuffleDeck(Card*, const int);
    void initializeBoard(Card*, Card*, Card*&, const int);
    void fillCard(Card*, int, Card*&);
    std::string printDeck(Card*, const int);
    std::string printBoard(Card*, const int);
    std::string showCard(Card*, int, const int);
private:
    Card *nextCard;

};

//class DeckOfCards
//{

//private:
//    Card *deck;
//    int currentCard;
//public:
//    DeckOfCards();
//    ~DeckOfCards();
//    void shuffleDeck();
//    std::string printDeck() const;
//    Card dealCard();
//};

#endif // DECKOFCARDS_H
