#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "state.h"
#include "subject.h"
#include "deckOfTiles.h"


class Game : public Subject
{
public:
    ~Game();
    static Game *getInstance();
    Map *getMap();
    int getNumOfPlayers();
    void setNumOfPlayers(int n);
    void createPlayers();
    Player *getPlayers();
    void setPlayer(int number, string name, string monster, string region, int type);
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
    string resolveDice(int diceNum,int numOfDice, int tileNumber);
    string attack(int);
    bool buyCard(int, int, int, int, int, int);
    bool getCards(int, int);
    bool isEmptyMainRegion();
    int checkGameOver();
    void createTiles();
    string resolveOuch(int num);
    void ouchOnePlayer(int num);
    DeckOfTiles *getDeckOfTiles();
    //void setUI(Ui::MainWindow *ui);

private:
    Game();
    static Game *instance;


    void increaseTurn();

    Map *map;
    DeckOfTiles *deckOfTiles;
    int numOfPlayers;
    Player *players;
    int *startupRoll;
    State state;
    int turn;
    int firstTurn;
    //Ui::MainWindow *ui;


};

#endif // GAME_H
