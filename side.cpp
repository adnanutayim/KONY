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

string Side::getDescription() {
    std::string desc = name;
    desc += " ";
    desc += std::to_string(cost);
    desc += " Gives ";

    if (energy != 0) {
        desc += to_string(energy);
        desc += " Energy";

    } else if (health != 0) {
        desc += to_string(health);
        desc += " Health";

    } else if (victory != 0) {
        desc += to_string(victory);
        desc += " Victory";

    }

    return desc;
}

string Side::getName() {
    return name;
}
int Side::getCost() {
    return cost;
}
int Side::getEnergy() {
    return energy;
}
int Side::getHealth() {
    return health;
}
int Side::getVictory() {
    return victory;
}
