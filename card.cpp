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
int Card::getId(){
    return id;
}
void Card::setCost(int c){
    cost = c;
}
int Card::getCost(){
    return cost;
}

std::string Card::printCard() const {
    return (name + "; Cost:" + std::to_string(cost) + "\n" + howToPlay + "\n" + effect + "\n\n");
}

int Card::displayId(){
    return id;
}




