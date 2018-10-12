#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"

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

private:
    Game();
    static Game *instance;
    Map *map;
    int numOfPlayers;
    Player *players;

};

#endif // GAME_H
