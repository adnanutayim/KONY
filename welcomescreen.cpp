#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <string>
#include <iostream>
#include <game.h>

using namespace std;

welcomeScreen::welcomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcomeScreen)
{
    ui->setupUi(this);

    playerCounter = 0;
    ui->monsterPreview->setScaledContents(true);

}

welcomeScreen::~welcomeScreen()
{
    delete ui;
}

void welcomeScreen::on_loadButton_clicked()
{

    // Lock UI
    ui->spinBox->setEnabled(false);
    ui->createButton->setEnabled(false);

    // Grab name of map file
    string map_file = ui->mapEdit->text().toStdString();

    log("-");
    log("Loading Map " + map_file);

    bool success = Game::getInstance()->getMap()->load("../KONY/res/" + map_file);

    if (!success) {
        log("File corrupted: Check the file exists and has the correct syntax.");
        return;
    }

    // Verification
    log("Map Verification");
    string verificationText;

    // 1
    bool test1 = Game::getInstance()->getMap()->verifyConnectedGraph();
    verificationText = test1 ? "Passed" : "Failed";
    log("Connected Graph: " + verificationText);

    // 2
    bool test2 = Game::getInstance()->getMap()->verifyConnectedSubgraph();
    verificationText = test2 ? "Passed" : "Failed";
    log("Connected Subgraph: " + verificationText);

    // 3
    bool test3 = Game::getInstance()->getMap()->verifyEachRegionIsNode();
    verificationText = test3 ? "Passed" : "Failed";
    log("Each Region is a Node: " + verificationText);


    // Load regions names
    // Initialize Regions
    int numOfRegions = Game::getInstance()->getMap()->getGraph()->getNumOfNodes();
    for (int i = 0; i < numOfRegions; i++) {

        if (Game::getInstance()->getMap()->getGraph()->nodes[i]->hasSubRegions()) {
            continue;
        }
        string regionName =Game::getInstance()->getMap()->getGraph()->nodes[i]->getName();
        ui->playerRegionEdit->addItem(regionName.c_str());

    }

    // Update Image
    updateImage(ui->playerCharacterEdit->currentText().toStdString());


    // Unlock Next step
    if (test1 && test2 && test3) {
        ui->spinBox->setEnabled(true);
        ui->createButton->setEnabled(true);
    }
}

void welcomeScreen::log(string str) {
    QString qs;
    string line = "----------------------------------------";

    if (str == "-") {
        qs.append(line.c_str());
    } else {
        qs.append(str.c_str());
    }
    ui->plainTextEdit->appendPlainText(qs);
}

void welcomeScreen::on_createButton_clicked()
{
    log("-");
    log("Creating Players");
    int numOfPlayers = ui->spinBox->value();
    Game::getInstance()->setNumOfPlayers(numOfPlayers);
    Game::getInstance()->createPlayers();

    // Progress the UI
    ui->playerSelection->setEnabled(true);
    ui->playerNameEdit->setEnabled(true);
    ui->playerCharacterEdit->setEnabled(true);
    ui->playerRegionEdit->setEnabled(true);
    ui->gameSettings->setEnabled(false);

}

void welcomeScreen::on_pushButton_clicked()
{
    // Grab input form UI
    ui->playerNumberEdit->clear();
    ui->playerNumberEdit->insert(QString::number(playerCounter + 2));

    string playerName = ui->playerNameEdit->text().toStdString();
    string playerCharacter = ui->playerCharacterEdit->currentText().toStdString();
    string playerRegion = ui->playerRegionEdit->currentText().toStdString();

    // Set the player object
    Game::getInstance()->setPlayer(playerCounter, playerName, playerCharacter, playerRegion);

    // Log to screen
    log("-");
    log("Player Number " + to_string(playerCounter + 1));
    log("Name: " + playerName);
    log("Monster: " + playerCharacter);
    log("Region: " + playerRegion);


    // clean input for next player + remove monster chosen
    ui->playerNameEdit->clear();
    ui->playerCharacterEdit->removeItem(ui->playerCharacterEdit->currentIndex());
    playerCounter++;


    // If last player, lock UI
    if (playerCounter == Game::getInstance()->getNumOfPlayers()) {
        ui->playerSelection->setEnabled(false);
        ui->launchGame->setEnabled(true);
        ui->playerNumberEdit->clear();
    }

}



void welcomeScreen::on_playerCharacterEdit_currentTextChanged(const QString &arg1)
{
    // Change Monster Picture Preview
    string name = arg1.toStdString();
    updateImage(name);

}

void welcomeScreen::updateImage(string name) {
    string path = "../KONY/res/Images/" + name + ".jpg";
    QPixmap pixmap = QPixmap (path.c_str());
    ui->monsterPreview->setPixmap(pixmap);
}

void welcomeScreen::on_launchGame_clicked()
{

   mw = new MainWindow(this);
   mw->show();
   hide();

}
