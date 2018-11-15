#include "phaseobserver.h"
#include "ui_mainwindow.h"
#include "state.h"
#include "game.h"


PhaseObserver::PhaseObserver()
{

}

PhaseObserver::PhaseObserver(Ui::MainWindow *&_ui) {
    ui = _ui;

}


void PhaseObserver::Update() {
    // Update Player Turn UI
    int playerNumber = Game::getInstance()->getTurn();
    string playerName = Game::getInstance()->getPlayerName(playerNumber);
    string message = "Player " + to_string(playerNumber+1) + ": " + playerName;
    ui->playerTurnLabel->setText(QString(message.c_str()));

    // Update Game Phase Message UI
    State state = Game::getInstance()->getState();
    string msg = "";
    switch (state) {

    case STARTUP_ROLL:
        msg = "Startup Roll";
    break;

    case STARTUP_LOCATION:
        msg = "Pick Startup Location";
    break;

    case ROLLING_DICE:
        msg = "Roll Dice";
    break;

    case RESOLVING_DICE:
        msg = "Resolving Dice";
    break;

    case MOVING:
        msg = "Pick a moving location";
    break;

    case BUYING_CARDS:
        msg = "Buy Cards";
    break;

    case FINISHING_TURN:
        msg = "Finish Your Turn";
    break;

    }
    ui->messageLabel->setText(QString(msg.c_str()));
}
