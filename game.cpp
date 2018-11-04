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
string Game::resolveDice(int diceNum, int numOfDice, Player p){
    switch (diceNum) {
    case 1 : p.addEnergy(numOfDice);
        return (p.getName() + " gained " + to_string(numOfDice) + " energy\nTotal energy: " + to_string(p.getEnergy()));
    case 2 : attack(numOfDice, p);
        break;
    case 3 : break;//Destruction
    case 4 : p.addHealth(numOfDice);
        return (p.getName() + " gained " + to_string(numOfDice) + " HP\nTotal health: " + to_string(p.getHealth()));
    case 5 : p.addVictory(numOfDice); //not per the rules
        return (p.getName() + " has " + to_string(p.getVictoryPoints()) + " VP");
    case 6 : p.hurt(numOfDice); //not per the rules, it is the tiles that hurt the player not the amount of dice
        return (p.getName() + " was inflicted " + to_string(numOfDice) + " dammage");
    default: return ("something went wrong");
    }
}

string Game::attack(int numOfDice, Player p){
    //you are in manhattan, so you hurt all the players
    if(p.getZone() == 0){
        for(int i = 0; i < numOfPlayers; i++){
            if(players[i].getZone() != 0){
                players[i].hurt(numOfDice);
            }
        }
        return (p.getName() + " attacked everyone!\nAll players loose " + to_string(numOfDice) + " HP");
     }
    //you hurt the person in manhattan
    else{
        for(int j = 0; j < numOfPlayers; j++){
            if(players[j].getZone() == 0){
                players[j].hurt(numOfDice);
            }
        }
        return (p.getName() + " attacked the player in Manhattan");
    }
}






