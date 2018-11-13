#include "side.h"

Side::Side()
{

}

void Side::setName(string name) {
    this->name = name;
}

void Side::setCost(int num) {
    cost = num;
}

void Side::setEnergy(int num) {
    energy = num;
}

void Side::setHealth(int num) {
    health = num;
}

void Side::setVictory(int num) {
    victory = num;
}
