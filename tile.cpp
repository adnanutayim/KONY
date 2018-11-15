#include "tile.h"


Tile::Tile(){
    activeSide = 0;
}

void Tile::setSide(int sideNum, string name, int cost, int energy, int health, int victory) {
    side[sideNum].setName(name);
    side[sideNum].setCost(cost);
    side[sideNum].setEnergy(energy);
    side[sideNum].setHealth(health);
    side[sideNum].setVictory(victory);
}

void Tile::setZone(int num) {
    zone = num;
}

void Tile::flip() {
    activeSide++;
    if (activeSide > 2) {
        activeSide = 2;
    }
}

bool Tile::isDestoryed() {
    return (activeSide >= 2);
}

void Tile::setStack(int num) {
    stack = num;
}

void Tile::setlocation(int zoneNum, int stackNum) {
    zone = zoneNum;
    stack = stackNum;
}

int Tile::getZone() {
    return zone;
}
int Tile::getActiveSide() {
    return activeSide;
}

int Tile::getStackNumber() {
    return stack;
}
Side Tile::getSide(int num) {
    return side[num];
}
