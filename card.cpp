#include "card.h"

Card::Card(){
}

Card::Card(int i, std::string n, int c, std::string h, std::string e){
    id = i;
    name = n;
    cost = c;
    howToPlay = h;
    effect = e;
}

Card::~Card(){

}

void Card::setId(int i){
    id = i;
}
//maybe use getters and setters??

std::string Card::printCard() const {
    return (name + "; Cost:" + std::to_string(cost) + "\n" + howToPlay + "\n" + effect);
}

int Card::displayId(){
    return id;
}




