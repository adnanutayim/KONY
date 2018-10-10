#include "tile.h"
//enum Buildings {Hospital, PowerPlant, HighRise};
//enum Units {Infantry, Jet, Tank};
//enum Neighborhood {}; //where the tiles are placed
//enum Rewards {Heart, Energy, Star};
std::string Building[3] = {"Hospital", "Power Plant", "High Rise"};
std::string Unit[3] = {"Infantry", "Jet", "Tank"};
//std::string Hood[];
std::string Reward[3] = {"Heart", "Energy", "Star"};


Tile::Tile(){
//Create a default constructor
}

Tile::Tile(Buildings b, int d, Units u, Rewards rt, int nor, Neighborhood n, bool iu){
    building = b;
    durability = d;
    unit = u;
    rewardType = rt;
    numOfReward = nor;
    hood = n;
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

Neighborhood Tile::getNeighborhood(){
    return hood;
}
void Tile::setNeighborhood(Neighborhood n){
    hood = n;
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

std::string Tile::printTile(){
    if(!isUnit){
        //Show the building side of the tile
        //return(Building[building] + ", " + durability + ", " + numOfReward + ", " + Reward[rewardType]);
    }
    else{
        //Show the unit side of the tile
        //return(Unit[unit] + ", ");
    }
}
