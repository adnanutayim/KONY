#include "player.h"

Player::Player(){
    playerName = "NoName";
    victoryPoints = 0;
    health = 10;
    energy = 0;

    numberOfPlayers++;
    playerNumber = numberOfPlayers;
}

Player::~Player() {

}

Player::Player(std::string name){
    playerName = name;
    victoryPoints = 0;
    health = 10;
    energy = 0;

    numberOfPlayers++;
    playerNumber = numberOfPlayers;
}

int Player::getNumberOfPlayers(){
    return numberOfPlayers;
}
void Player::setNumberOfPlayers(int nop){
    numberOfPlayers = nop;
}

int Player::getPlayerNumber(){
    return playerNumber;
}
void Player::setPlayerNumber(int pn){
    playerNumber = pn;
}

std::string Player::getPlayerName(){
    return playerName;
}
void Player::setPlayerName(std::string pName){
    playerName = pName;
}

int Player::getVictoryPoints(){
    return victoryPoints;
}
void Player::setVictoryPoints(int vp){
    victoryPoints = vp;
}

int Player::getHealth(){
    return health;
}
void Player::setHealth(int h){
    health = h;
}

int Player::getEnergy(){
    return energy;
}
void Player::setEnergy(int e){
    energy = e;
}

Monsters Player::getMonster() {
    return character;
}

void Player::setMonster(Monsters m) {
    character = m;
}

int Player::getZone() {
    return zone;
}

void Player::setZone(int z) {
    zone = z;
}

//RollDice()
//ResolveDice()
//Move()
//BuyCards()
