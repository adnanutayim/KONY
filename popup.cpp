#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    popupFillMoveLocations();
}

Popup::~Popup()
{
    delete ui;
}

void Popup::popupFillMoveLocations() {
    // Fill locations with less that two players
    // Count players in each location
    Game *game = Game::getInstance();

    ui->locationCombo->clear();
    int numOfRegions = game->getMap()->getGraph()->getNumOfNodes();
    for (int i = 0; i < numOfRegions; i++) {

        if (game->getMap()->getGraph()->nodes[i]->hasSubRegions()) {
            continue;
        }


        if (game->playersInRegion(i) == 2) {
            continue;
        }

        string regionName = game->getMap()->getGraph()->nodes[i]->getName();
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
