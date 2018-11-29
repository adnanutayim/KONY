#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "monsters.h"
#include "card.h"
#include "subject.h"
#include "strategy.h"
#include "moderatestrategy.h"
#include "aggressivestrategy.h"


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
    int playerType; //0=human, 1=moderate, 2=aggresive
    Strategy *strategy;

public:
    Player();
    Player(std::string, int);
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

    int getPlayerType();
    void setPlayerType(int);


    bool ownCard(int);
    void setRank(int);
    int getRank();
    void RollDice();
    void ResolveDice();
    void Move();
    bool BuyCards(int, int, int, int, int);
    int getZone();
    void setZone(int);
    string getName();
    void addEnergy(int);
    void addHealth(int);
    void addVictory(int);
    void hurt(int);

    void setStrategy(Strategy * s);
    Strategy *getStrategy();
};

#endif // PLAYER_H
