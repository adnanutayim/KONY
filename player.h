#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "monsters.h"


class Player
{
private:
    int numberOfPlayers;
    int playerNumber;
    std::string playerName;
    enum Monsters character;
    int victoryPoints;
    int health;
    int energy;
    //zone
    //Vector for buying and holding cards
public:
    Player();
    Player(std::string);
    ~Player();

    int getNumberOfPlayers();
    void setNumberOfPlayers(int);

    int getPlayerNumber();
    void setPlayerNumber(int);

    std::string getPlayerName();
    void setPlayerName(std::string);

    int getVictoryPoints();
    void setVictoryPoints(int);

    int getHealth();
    void setHealth(int);

    int getEnergy();
    void setEnergy(int);

    enum Monsters getMonster();
    void setMonster(enum Monsters);
};

#endif // PLAYER_H
