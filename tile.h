#ifndef TILE_H
#define TILE_H

#include <string>

enum Buildings {Hospital, PowerPlant, HighRise};
enum Units {Infantry, Jet, Tank};
enum Neighborhood {}; //where the tiles are placed
enum Rewards {Heart, Energy, Star};


class Tile{
private:
    Buildings building;
    Units unit;
    Neighborhood hood;
    Rewards rewardType;
    int durability;
    int numOfReward;
    bool isUnit; //so we know that once dead it is removed from board

public:
    Tile();
    Tile(Buildings, int, Units, Rewards, int, Neighborhood, bool);
    ~Tile();

    Buildings getBuilding();
    void setBuilding(Buildings);

    Units getUnit();
    void setUnit(Units);

    Neighborhood getNeighborhood();
    void setNeighborhood(Neighborhood);

    Rewards getRewardType();
    void setRewardType(Rewards);

    int getDurability();
    void setDurability(int);

    int getNumOfReward();
    void setNumOfReward(int);

    bool getIsUnit();
    void setIsUnit(bool);

    std::string printTile();
};

#endif // TILE_H
