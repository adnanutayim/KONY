#include "card.h"

Card::Card(){
}

Card::Card(std::string n, int c, std::string h, std::string e){
    name = n;
    cost = c;
    howToPlay = h;
    effect = e;
}

Card::~Card(){

}

//maybe use getters and setters??

std::string Card::printCard() const {
    return (name + "; Cost:" + std::to_string(cost) + "\n" + howToPlay + "\n" + effect);
}


