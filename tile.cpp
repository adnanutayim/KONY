#include "tile.h"
//enum Buildings {Hospital, PowerPlant, HighRise};
//enum Units {Infantry, Jet, Tank};
//enum Neighborhood {}; //where the tiles are placed
//enum Rewards {Heart, Energy, Star};
std::string Building[3] = {"Hospital", "Power Plant", "High Rise"};
std::string Unit[3] = {"Infantry", "Jet", "Tank"};
int zone[5] = {1, 2, 3, 4, 5};
std::string Reward[3] = {"Heart", "Energy", "Star"};


Tile::Tile(){
//Create a default constructor
}

Tile::Tile(Buildings b, int d, Rewards rt, int nor, int z, bool iu){
    building = b;
    durability = d;
//   unit = u;
    rewardType = rt;
    numOfReward = nor;
    zone = z;
    isUnit = iu;
}

Tile::~Tile(){

}

Buildings Tile::getBuilding(){
    return building;
}
void Tile::setBuilding(Buildings b){
    building = b;
}

Units Tile::getUnit(){
    return unit;
}
void Tile::setUnit(Units u){
    unit = u;
}

int Tile::getZone(){
    return zone;
}
void Tile::setZone(int z){
    zone = z;
}

Rewards Tile::getRewardType(){
    return rewardType;
}
void Tile::setRewardType(Rewards rt){
    rewardType = rt;
}

int Tile::getDurability(){
    return durability;
}
void Tile::setDurability(int d){
    durability = d;
}

int Tile::getNumOfReward(){
    return numOfReward;
}
void Tile::setNumOfReward(int nor){
    numOfReward = nor;
}

bool Tile::getIsUnit(){
    return isUnit;
}
void Tile::setIsUnit(bool iu){
    isUnit = iu;
}

bool Tile::getIsDestroyed(){
    return isDestroyed;
}
void Tile::setIsDestroyed(bool isdes){
    isDestroyed = isdes;
}

std::string Tile::printTile(){
    if(isUnit){
        //Show the unit side of the tile
        return(Unit[unit] + "; Durability: " + std::to_string(durability) + "\n" + std::to_string(numOfReward) + " " + Reward[rewardType]+ "\nDestroyed?" + std::to_string(isDestroyed));

    }
    else{
        //Show the building side of the tile
        return(Building[building] + "; Durability: " + std::to_string(durability) + "\n" + std::to_string(numOfReward) + " " + Reward[rewardType]);
    }
}
