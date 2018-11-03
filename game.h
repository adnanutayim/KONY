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
    void registerStartupRoll(int playerNum, int attacks);
    void advanceGame();
    int playersInRegion(int regionNumber);
    int getRegionNumberFromStr(string s);
    void movePlayer(int playerNumber, int regionNumber);

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
