#include "card.h"

Card::Card(){
}

Card::Card(int i, std::string n, int c, std::string h, std::string e, int v, int en, int hp){
    id = i;
    name = n;
    cost = c;
    howToPlay = h;
    effect = e;
    vp = v;
    energy = en;
    health = hp;
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

int Card::getVp(){
    return vp;
}
void Card::setVp(int v){
    vp = v;
}

int Card::getEnergy(){
    return energy;
}
void Card::setEnergy(int e){
    energy = e;
}

int Card::getHealth(){
    return health;
}
void Card::setHeath(int h){
    health = h;
}
