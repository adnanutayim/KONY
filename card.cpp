#include "card.h"

Card::Card(){
}

Card::Card(std::string c, std::string h, std::string e){
    cost = c;
    howToPlay = h;
    effect = e;
}

Card::~Card(){

}

//maybe use getters and setters??

std::string Card::printCard() const {
    return (cost + ", " + howToPlay + ", " + effect);
}


