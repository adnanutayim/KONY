#include "player.h"
#include "subject.h"
#include "card.h"

Player::Player(){
    playerName = "NoName";
    victoryPoints = 0;
    health = 10;
    energy = 10;
    playerType = 0;

    numberOfPlayers++;
    playerNumber = numberOfPlayers;
    strategy = NULL;
}

Player::~Player() {
    if (strategy != NULL) {
        delete strategy;
        strategy = NULL;
    }
}

Player::Player(std::string name, int type){
    playerName = name;
    victoryPoints = 0;
    health = 10;
    energy = 10;
    playerType = type;
    numberOfPlayers++;
    playerNumber = numberOfPlayers;
    strategy = NULL;

    Notify();
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
    Notify();
}

int Player::getVictoryPoints(){
    return victoryPoints;
}
void Player::setVictoryPoints(int vp){
    victoryPoints = vp;
    Notify();
}

int Player::getHealth(){
    return health;
}
void Player::setHealth(int h){
    health = h;
    Notify();
}

int Player::getEnergy(){
    return energy;
}
void Player::setEnergy(int e){
    energy = e;
    Notify();
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
    Notify();
}

string Player::getName() {
    return playerName;
}

void Player::addEnergy(int num){
    setEnergy(energy+num);
}

void Player::addHealth(int num){
    setHealth(health+num);
}

void Player::addVictory(int num){
    setVictoryPoints(victoryPoints+num);
}

void Player::hurt(int num){

    setHealth(health-num);
}

//Cards are passed with the cost, vp, energy, heath, we then modify the players data
bool Player::BuyCards(int cardID, int cost, int v, int e, int h){
    if(energy >= cost){
        playerCards.push_back(cardID);
        energy -= cost;
        Card c;
        if(v == -1){
            int temp = victoryPoints;
            victoryPoints = 0;
            energy += temp;
        }
        else{
            victoryPoints += v;
            energy += e;
            health += h;
        }
        Notify();
        return true;
    }
    return false;
}

//Check if a player owns the card or not
bool Player::ownCard(int cardNum){
    for(int i = 0; i < playerCards.size(); i++){
        if(cardNum == playerCards[i]){
            return true;
        }
    }
    return false;
}

void Player::setRank(int r) {
    rank = r;
}
int Player::getRank() {
    return rank;
}

void Player::setTurn(bool t){
    turn = t;
    Notify();
}

int Player::getPlayerType(){
    return playerType;
}
void Player::setPlayerType(int pt) {
    playerType = pt;
    if (pt == 1) {
        strategy = new ModerateStrategy();
    } else if (pt == 2) {
        strategy = new AggressiveStrategy();
    }

}

void Player::setStrategy(Strategy * s) {
    strategy = s;
}

Strategy *Player::getStrategy() {
    return strategy;
}
