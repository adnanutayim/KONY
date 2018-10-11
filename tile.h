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
    int zone;
    Rewards rewardType;
    int durability;
    int numOfReward;
    bool isUnit;
    bool isDestroyed;


public:
    Tile();
    Tile(Buildings, int, Rewards, int, int, bool);
    ~Tile();

    Buildings getBuilding();
    void setBuilding(Buildings);

    Units getUnit();
    void setUnit(Units);

    int getZone();
    void setZone(int);

    Rewards getRewardType();
    void setRewardType(Rewards);

    int getDurability();
    void setDurability(int);

    int getNumOfReward();
    void setNumOfReward(int);

    bool getIsUnit();
    void setIsUnit(bool);

    bool getIsDestroyed();
    void setIsDestroyed(bool);

    std::string printTile();
};

#endif // TILE_H
