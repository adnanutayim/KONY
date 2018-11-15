#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "monsters.h"
#include "card.h"
#include "subject.h"


class Player : public Subject
{
private:
    int numberOfPlayers;
    int playerNumber;
    std::string playerName;
    enum Monsters character;
    int victoryPoints;
    int health;
    int energy;
    int zone;
    vector<int> playerCards; //Vector for buying and holding cards
    int rank;   // rank inside manhattan
    bool turn;


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

    void setTurn(bool);


    bool ownCard(int);
    void setRank(int);
    int getRank();
    void RollDice();
    void ResolveDice();
    void Move();
    bool BuyCards(int, int);
    int getZone();
    void setZone(int);
    string getName();
    void addEnergy(int);
    void addHealth(int);
    void addVictory(int);
    void hurt(int);
};

#endif // PLAYER_H
