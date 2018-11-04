#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "state.h"

class Game
{
public:
    ~Game();
    static Game *getInstance();
    Map *getMap();
    int getNumOfPlayers();
    void setNumOfPlayers(int n);
    void createPlayers();
    Player *getPlayers();
    void setPlayer(int number, string name, string monster, string region);
    State getState();
    void setState(State);
    void Startup();
    int getTurn();
    string getPlayerName(int);
    string getPlayerVP(int);
    string getPlayerHealth(int);
    string getPlayerEnergy(int);
    void decreasePlayerEnergy(int);
    void registerStartupRoll(int playerNum, int attacks);
    void advanceGame();
    int playersInRegion(int regionNumber);
    int getRegionNumberFromStr(string s);
    void movePlayer(int playerNumber, int regionNumber);
    string resolveDice(int,int, Player);
    string attack(int, Player);
    bool buyCard(int, int, int);
    bool getCards(int, int);
    bool isEmptyMainRegion();
    int checkGameOver();

private:
    Game();
    static Game *instance;

    void increaseTurn();

    Map *map;
    int numOfPlayers;
    Player *players;
    int *startupRoll;
    State state;
    int turn;
    int firstTurn;


};

#endif // GAME_H
