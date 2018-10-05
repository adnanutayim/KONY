#include "deck.h"
#include <stdlib.h>
#include <time.h>

deck::deck()
{
    createDeck();
}

void deck::createDeck(){
    card arrCard[64];
}

void deck::shuffleDeck(card cardArr[]){
    srand(time(0));

    for(int i = 0; i < 64; i++){
        int r = i + (rand() % (64 - 1));
        std::swap(cardArr[i], cardArr[r]);
    }
}



