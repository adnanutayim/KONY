#include "playercard.h"
#include "ui_mainwindow.h"
#include <iostream>

// Default Constructor
PlayerCard::PlayerCard(){

}

// Attaches ui
PlayerCard::PlayerCard(Player* p, Ui::MainWindow *&u){
    ui = u;
//    _subject = p;
//    _subject->Attach(this);
}

// To observe a subject
void PlayerCard::observe(Player *p) {
    _subject = p;
    _subject->Attach(this);
}

// construcotr
PlayerCard::~PlayerCard(){
    _subject->Detach(this);
}

// updates
void PlayerCard::Update(){
    display();
}

// displays stuff
void PlayerCard::display(){
    // Update Player Turn UI
    int playerNumber = Game::getInstance()->getTurn();
    string playerName = Game::getInstance()->getPlayerName(playerNumber);
    string message = "Player " + to_string(playerNumber+1) + ": " + playerName;
    ui->playerNameLabel->setText(QString(message.c_str()));

    string vp = Game::getInstance()->getPlayerVP(playerNumber);
    string health = Game::getInstance()->getPlayerHealth(playerNumber);
    string energy = Game::getInstance()->getPlayerEnergy(playerNumber);

    ui->victoryPointsDisplay->setText(QString(vp.c_str()));
    ui->energyPointsDisplay->setText(QString(energy.c_str()));
    ui->healthPointsDisplay->setText(QString(health.c_str()));

    // Add image
    ui->playerCardLabel->setScaledContents(true);
    Game *game = Game::getInstance();
    int turn = game->getTurn();
    Monsters monster = game->getPlayers()[turn].getMonster();
    string monsterName = getNameFromMonster(monster);
    string path = "../KONY/res/Images/Monster" + monsterName + ".jpg";
    QPixmap pixmap = QPixmap(path.c_str());
    ui->playerCardLabel->setPixmap(pixmap);

    //Bar Graph
    int size = Game::getInstance()->getMap()->getGraph()->getNumOfNodes();
    string regionNames;
    string playersInRegion;
    for(int i = 0; i < size; i++) {
        regionNames += Game::getInstance()->getMap()->getGraph()->getNodes()[i]->getName() + " " + to_string(Game::getInstance()->playersInRegion(i)) + "\n";
    }
    ui->barGraphLabel->setText(QString(regionNames.c_str()));

}

