#include "card.h"

card::card(){
}

card::card(std::string c, std::string e, std::string h){
    cost = c;
    effect = e;
    howToPlay = h;
}

std::string card::printCard() const {
    return (cost + ", " + effect + ", " + howToPlay);
}
