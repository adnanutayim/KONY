#include "game.h"
#include <iostream>


// Static Initialization
Game *Game::instance = NULL;


Game::Game() {
    map = new Map();
    players = NULL;
    startupRoll = NULL;
}

Game::~Game() {
    if (map != NULL) {
        delete map;
        map = NULL;
    }

    if (players != NULL) {
        delete [] players;
        players = NULL;
    }

    if (startupRoll != NULL) {
        delete [] startupRoll;
        startupRoll = 0;
    }
}

Game *Game::getInstance() {
    if (instance == NULL) {
        instance = new Game();
    }
    return instance;
}

Map *Game::getMap() {
    return map;
}

int Game::getNumOfPlayers() {
    return numOfPlayers;
}

void Game::setNumOfPlayers(int n) {
    numOfPlayers = n;
}

void Game::createPlayers() {
    players = new Player [numOfPlayers];
    startupRoll = new int [numOfPlayers];
}

Player *Game::getPlayers() {
    return players;
}

void Game::setPlayer(int number, string name, string monster, string region) {

    // Get Monster
    Monsters playerMonster = getMonsterFromString(monster);
    // Get region number
    int playerRegion = map->getGraph()->getNodeNumberByName(region);
    if (region == "") {
        playerRegion = -1;
    }


    players[number].setPlayerNumber(number + 1);
    players[number].setPlayerName(name);
    players[number].setMonster(playerMonster);
    players[number].setZone(playerRegion);

}

State Game::getState() {
    return state;
}

void Game::setState(State s) {
    state = s;
}

void Game::Startup() {
    state = State::STARTUP_ROLL;
    turn = 0;
}

int Game::getTurn() {
    return turn;
}

string Game::getPlayerName(int p) {
    return players[p].getName();
}

void Game::registerStartupRoll(int playerNum, int attacks) {
    startupRoll[playerNum] = attacks;
}

void Game::advanceGame() {
    switch (state) {

    case STARTUP_ROLL:
        if (turn == numOfPlayers - 1) {
            // Finished Startup roll
            // Get player with most attacks
            int maxArg = 0;
            for (int i = 0; i < numOfPlayers; i++) {
                if (startupRoll[i] > startupRoll[maxArg]) {
                    maxArg = i;
                }
            }
            turn = maxArg;
            firstTurn = maxArg;
            state = STARTUP_LOCATION;
        } else {
            increaseTurn();
        }
    break;

    case STARTUP_LOCATION:
        increaseTurn();
        if (turn == firstTurn) {    // Finished startup phase
            state = ROLLING_DICE;
        }
    break;


    case ROLLING_DICE:
        state = RESOLVING_DICE;
        break;

    case RESOLVING_DICE:
        state = MOVING;
        break;

    case MOVING:
        state = BUYING_CARDS;
        break;

    }
}

int Game::playersInRegion(int regionNumber) {
    int population = 0;
    for (int i = 0; i < numOfPlayers; i++) {
        if (players[i].getZone() == regionNumber) {
            population++;
        }
    }
    return population;
}

int Game::getRegionNumberFromStr(string s) {
    return map->getGraph()->getNodeNumberByName(s);
}

void Game::movePlayer(int playerNumber, int regionNumber) {
    players[playerNumber].setZone(regionNumber);
}

void Game::increaseTurn() {
    turn++;
    if (turn == numOfPlayers) {
        turn = 0;
    }
}

//diceNum is the num rolled the player rolled, numOfDice is how many of that dice the player rolled, enemy is the player p is attacking
void Game::resolveDice(int diceNum, int numOfDice, Player p){
    switch (diceNum) {
    case 1 : p.addEnergy(numOfDice); break;
    case 2 : attack(numOfDice, p); break;
    case 3 : break;//Destruction
    case 4 : p.addHealth(numOfDice); break;
    case 5 : p.addVictory(numOfDice); break; //not per the rules
    case 6 : p.hurt(numOfDice); break; //not per the rules, it is the tiles that hurt the player not the amount of dice
    }
}

void Game::attack(int numOfDice, Player p){
    //you are in manhattan, so you hurt all the players
    if(p.getZone() == 0){
        for(int i = 0; i < numOfPlayers; i++){
            if(players[i].getZone() != 0){
                players[i].hurt(numOfDice);
            }
        }
     }
    //you hurt the person in manhattan
    else{
        for(int j = 0; j < numOfPlayers; j++){
            if(players[j].getZone() == 0){
                players[j].hurt(numOfDice);
            }
        }
    }
}

bool Game::isEmptyMainRegion() {
    for (int i = 0; i < numOfPlayers; i++) {
        if (players[i].getZone() == 0) {
            return false;
        }
    }
    return true;

}







