#include "playercard.h"
#include "ui_mainwindow.h"

PlayerCard::PlayerCard(){

}
PlayerCard::PlayerCard(Player* p, Ui::MainWindow *&u){
    ui = u;
    _subject = p;
    _subject->Attach(this);
}

PlayerCard::~PlayerCard(){
    _subject->Detach(this);
}

void PlayerCard::Update(){
    display();
}

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
}
