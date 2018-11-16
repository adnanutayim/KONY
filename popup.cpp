#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    fillMoveLocations();
}

Popup::~Popup()
{
    delete ui;
}

void Popup::fillMoveLocations() {
    // Fill locations with less that two players
    // Count players in each location
    ui->locationCombo->clear();
    int numOfRegions = Game::getInstance()->getMap()->getGraph()->getNumOfNodes();
    for (int i = 0; i < numOfRegions; i++) {

        if (Game::getInstance()->getMap()->getGraph()->nodes[i]->hasSubRegions()) {
            continue;
        }


        if (Game::getInstance()->playersInRegion(i) == 2) {
            continue;
        }

        string regionName = Game::getInstance()->getMap()->getGraph()->nodes[i]->getName();
        ui->locationCombo->addItem(regionName.c_str());

    }
}

void Popup::on_stayButton_clicked()
{
    hide();
}

void Popup::on_moveButton_clicked()
{
    Game *game = Game::getInstance();
    int location = ui->locationCombo->currentIndex();
    int playerToMove = game->playersInRegion(0);
    game->getPlayers()[playerToMove].setZone(location);
    hide();
}
