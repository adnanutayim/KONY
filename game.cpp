#include "game.h"
#include <iostream>


// Static Initialization
Game *Game::instance = NULL;


Game::Game() {
    map = new Map();
    players = NULL;
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
}

Player *Game::getPlayers() {
    return players;
}

void Game::setPlayer(int number, string name, string monster, string region) {

    // Get Monster
    Monsters playerMonster = getMonsterFromString(monster);
    // Get region number
    int playerRegion = map->getGraph()->getNodeNumberByName(region);


    players[number].setPlayerNumber(number + 1);
    players[number].setPlayerName(name);
    players[number].setMonster(playerMonster);
    players[number].setZone(playerRegion);

}

