#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include "game.h"
#include "state.h"
#include "node.h"
#include "qpainter.h"
#include "monsters.h"
#include "QMessageBox"
#include "playercard.h"
#include "player.h"
#include "phaseobserver.h"
#include "subject.h"



const int SIZE_OF_DECK = 8;
const int SIZE_OF_BOARD = 3;
int currentCard = 0;
Card deck[SIZE_OF_DECK];
Card board[SIZE_OF_BOARD];
Card *nextCard = &deck[0];
DeckOfCards doc(deck);

const int SHIFT = 50;
const int IMAGE_SIZE = 250;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Player data observer
    Player *player = new Player;
    PlayerCard *playerCard = new PlayerCard(player, ui);

    Game *game = Game::getInstance();
    for (int i = 0; i < game->getNumOfPlayers(); i++) {
        Player *p = &game->getPlayers()[i];
        playerCard->observe(p);
    }

    // Phase Observer
    PhaseObserver *phaseObserver = new PhaseObserver(ui);
    game->Attach(phaseObserver);



    for (int i = 0; i < 8; i++) {
        rolls[i] = 0;
    }

    // Background Board
    updateMap();

    // Player Card
    ui->victoryPointsLabel->setScaledContents(true);
    string vplPath = "../KONY/res/Images/victoryPoints.png";
    QPixmap vplPixmap = QPixmap (vplPath.c_str());
    ui->victoryPointsLabel->setPixmap(vplPixmap);

    ui->healthPointsLabel->setScaledContents(true);
    string hplPath = "../KONY/res/Images/healthPoints.png";
    QPixmap hplPixmap = QPixmap (hplPath.c_str());
    ui->healthPointsLabel->setPixmap(hplPixmap);

    ui->energyPointsLabel->setScaledContents(true);
    string eplPath = "../KONY/res/Images/energyPoints.png";
    QPixmap eplPixmap = QPixmap (eplPath.c_str());
    ui->energyPointsLabel->setPixmap(eplPixmap);

    // Create Tiles
    Game::getInstance()->createTiles();


    // Dice Labels
    setDiceImage(ui->diceLabel1, 1);
    setDiceImage(ui->diceLabel2, 2);
    setDiceImage(ui->diceLabel3, 3);
    setDiceImage(ui->diceLabel4, 4);
    setDiceImage(ui->diceLabel5, 5);
    setDiceImage(ui->diceLabel6, 6);
    setDiceImage(ui->diceLabel7, 1);
    setDiceImage(ui->diceLabel8, 2);

    // Prepare StartupPhase
    Game::getInstance()->Startup();
    set8DiceEnabled(false);


    doc.shuffleDeck(deck, SIZE_OF_DECK);
    doc.initializeBoard(deck, board, nextCard, SIZE_OF_BOARD);
    //dot.shuffleTiles(tileDeck, NUM_OF_TILES);

    setCardImage(ui->cardLabel_1, board[0].displayId());
    setCardImage(ui->cardLabel_2, board[1].displayId());
    setCardImage(ui->cardLabel_3, board[2].displayId());


}

void MainWindow::setDiceImage(QLabel *label, int dice_roll) {

    label->setScaledContents(true);
    DiceRoll dr;
    string diceName = dr.transform(dice_roll);
    string path = "../KONY/res/Images/" + diceName + ".PNG";
    QPixmap pixmap = QPixmap (path.c_str());
    label->setPixmap(pixmap);


}

void MainWindow::setCardImage(QLabel *label, int id){

    label->setScaledContents(true);
    string cardName = std::to_string(id);
    string cardPath = "../KONY/res/Images/cards/" + cardName + ".jpg";
    QPixmap pixmap = QPixmap (cardPath.c_str());
    label->setPixmap(pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rollButton_clicked()
{

    bool diceToRoll [8];
    diceToRoll[0] = ui->diceCheckBox_1->isChecked();
    diceToRoll[1] = ui->diceCheckBox_2->isChecked();
    diceToRoll[2] = ui->diceCheckBox_3->isChecked();
    diceToRoll[3] = ui->diceCheckBox_4->isChecked();
    diceToRoll[4] = ui->diceCheckBox_5->isChecked();
    diceToRoll[5] = ui->diceCheckBox_6->isChecked();
    diceToRoll[6] = ui->diceCheckBox_7->isChecked();
    diceToRoll[7] = ui->diceCheckBox_8->isChecked();


    DiceRoll dr;
    dr.rollDice(diceToRoll, rolls);

    log("-");
    log("Rolls:");
    string rollsString = "";
    for (int i = 0; i < 8; i++) {
        rollsString += dr.transform(rolls[i]) + " ";
    }
    log(rollsString);

    // Dice Labels
    setDiceImage(ui->diceLabel1, rolls[0]);
    setDiceImage(ui->diceLabel2, rolls[1]);
    setDiceImage(ui->diceLabel3, rolls[2]);
    setDiceImage(ui->diceLabel4, rolls[3]);
    setDiceImage(ui->diceLabel5, rolls[4]);
    setDiceImage(ui->diceLabel6, rolls[5]);
    setDiceImage(ui->diceLabel7, rolls[6]);
    setDiceImage(ui->diceLabel8, rolls[7]);


    int size = 8;
    Game *game = Game::getInstance();

    if (game->getState() == STARTUP_ROLL) {         // Startup roll
        // Count Attacks
        // Save rolls in array
        int attacks = 0;
        for (int i = 0; i < size; i++) {
            if (dr.transform(rolls[i]) == "Attack") {
                attacks++;
            }
        }
        log("Player " + to_string(game->getTurn()+1) + " rolled " + to_string(attacks) + " Attacks.");
        game->registerStartupRoll(game->getTurn(), attacks);
        game->advanceGame();


        // Check if finished startup roll
        if (game->getState()== STARTUP_LOCATION) {
            log("-");
            log("Player " + to_string(game->getTurn()+1) + " Has the most Attacks. They play First.");
            lockUnlockUI();
            fillMoveLocations();
        }

    } else if (game->getState() == ROLLING_DICE) {    // Roll Dice
        set6DiceEnabled(true);
        numberOfRolls++;
        if (numberOfRolls == 3) {
            // finish phase
            game->advanceGame();

            lockUnlockUI();
            fillResolveDice();
        }
    }
}


void MainWindow::log(string str) {
    QString qs;
    string line = "----------------------------------------";

    if (str == "-") {
        qs.append(line.c_str());
    } else {
        qs.append(str.c_str());
    }
    ui->plainTextEdit->appendPlainText(qs);
}

void MainWindow::on_buyCards_clicked()
{
    bool cardToBuy[3];
    cardToBuy[0] = ui->cardCheckBox_1->isChecked();
    cardToBuy[1] = ui->cardCheckBox_2->isChecked();
    cardToBuy[2] = ui->cardCheckBox_3->isChecked();

    int playerNumber = Game::getInstance()->getTurn();

    for(int i = 0; i < SIZE_OF_BOARD; i++){
        if(cardToBuy[i] == 1){
            if(currentCard >= (SIZE_OF_DECK - SIZE_OF_BOARD)){
                board[i].setId(0);
            }
            else{
                if(Game::getInstance()->buyCard(playerNumber, board[i].getId(), board[i].getCost())){
                    doc.fillCard(board, i, nextCard);
                    currentCard++;
                }
                else{
                    log("not enough energy to buy cards");
                }
            }
        }
    }

    setCardImage(ui->cardLabel_1, board[0].displayId());
    setCardImage(ui->cardLabel_2, board[1].displayId());
    setCardImage(ui->cardLabel_3, board[2].displayId());


}


void MainWindow::on_wipeBoard_clicked()
{
    int playerNumber = Game::getInstance()->getTurn();
    if(stoi(Game::getInstance()->getPlayerEnergy(playerNumber)) >= 2){
        for(int i = 0; i < SIZE_OF_BOARD; i++){
            if(currentCard >= (SIZE_OF_DECK - SIZE_OF_BOARD)){
                board[i].setId(0);
            }
            else {
                doc.fillCard(board, i, nextCard);
                currentCard++;
            }
        }
        Game::getInstance()->decreasePlayerEnergy(playerNumber);
    }

    setCardImage(ui->cardLabel_1, board[0].displayId());
    setCardImage(ui->cardLabel_2, board[1].displayId());
    setCardImage(ui->cardLabel_3, board[2].displayId());


}

void MainWindow::set6DiceEnabled(bool flag) {
    ui->diceCheckBox_1->setEnabled(flag);
    ui->diceCheckBox_2->setEnabled(flag);
    ui->diceCheckBox_3->setEnabled(flag);
    ui->diceCheckBox_4->setEnabled(flag);
    ui->diceCheckBox_5->setEnabled(flag);
    ui->diceCheckBox_6->setEnabled(flag);
}

void MainWindow::set8DiceEnabled(bool flag) {
    set6DiceEnabled(flag);
    ui->diceCheckBox_7->setEnabled(flag);
    ui->diceCheckBox_8->setEnabled(flag);
}


void MainWindow::lockUnlockUI() {

    State state = Game::getInstance()->getState();
    int winner = -1;
    switch (state) {

    case STARTUP_LOCATION:
        ui->rollButton->setEnabled(false);
        ui->moveGroup->setEnabled(true);
        break;


    case ROLLING_DICE:
        ui->finishTurnButton->setEnabled(false);
        // Check if there's a winner
        winner = Game::getInstance()->checkGameOver();
        if (winner != -1) {
            // show message
            QMessageBox Msgbox;
            string msg = "Game won by Player " + to_string(winner);
            Msgbox.setText(QString(msg.c_str()));
            Msgbox.exec();
            return;
        }

        ui->moveGroup->setEnabled(false);
        ui->rollButton->setEnabled(true);
        set8DiceEnabled(false);
        ui->diceCheckBox_7->setChecked(false);
        ui->diceCheckBox_8->setChecked(false);
        ui->diceLabel7->setEnabled(false);
        ui->diceLabel8->setEnabled(false);
        numberOfRolls = 0;
        break;


    case RESOLVING_DICE:
        set6DiceEnabled(false);
        check6Dice(true);
        ui->rollButton->setEnabled(false);
        ui->resolveGroup->setEnabled(true);
        break;

     case MOVING:
        ui->resolveGroup->setEnabled(false);
        ui->moveGroup->setEnabled(true);
        fillMoveLocations();
        break;


     case BUYING_CARDS:
        ui->cardsGroup->setEnabled(true);
        ui->moveGroup->setEnabled(false);
        break;

     case FINISHING_TURN:
        ui->cardsGroup->setEnabled(false);
        ui->finishTurnButton->setEnabled(true);
        break;

    }
}

void MainWindow::fillMoveLocations() {

    State state = Game::getInstance()->getState();
    switch (state) {
        case STARTUP_LOCATION: {
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
            break;
    }

    case MOVING: {

        // Differentiate 4 cases
        // 1. Must move to lower manhattan
        // 2. Move anywhere (restrictions apply)
        // 3. Advance in manhattan
        // 4. No valid move(upper manhattan)

        ui->locationCombo->clear();
        Game *game = Game::getInstance();
        int turn = game->getTurn();
        int zone = game->getPlayers()[turn].getZone();
        int rank = game->getPlayers()[turn].getRank();
        int numOfRanks = game->getMap()->getSubgraph()->getNumOfNodes();

        if (zone != 0 && game->isEmptyMainRegion()) {               // Case 1

            string mainRegion = game->getMap()->getGraph()->getNodes()[0]->getName();
            string firstSubRegion = game->getMap()->getSubgraph()->getNodes()[0]->getName();
            string location = mainRegion + " - " + firstSubRegion;
            ui->locationCombo->addItem(QString(location.c_str()));

        } else if (zone != 0 && !game->isEmptyMainRegion()) {       // Case 2

            Graph *graph = game->getMap()->getGraph();
            Node **nodes = graph->getNodes();
            for (int i = 1; i < graph->getNumOfNodes(); i++) {
                string location = nodes[i]->getName();
                ui->locationCombo->addItem(QString(location.c_str()));
            }

        } else if (zone == 0 && rank != numOfRanks - 1) {           // Case 3

            string mainRegion = game->getMap()->getGraph()->getNodes()[0]->getName();
            string nextSubRegion = game->getMap()->getSubgraph()->getNodes()[rank+1]->getName();
            string location = mainRegion + " - " + nextSubRegion;
            ui->locationCombo->addItem(QString(location.c_str()));

        } else {                                                    // Case 4
            string mainRegion = game->getMap()->getGraph()->getNodes()[0]->getName();
            string lastSubRegion = game->getMap()->getSubgraph()->getNodes()[numOfRanks-1]->getName();
            string location = mainRegion + " - " + lastSubRegion;
            ui->locationCombo->addItem(QString(location.c_str()));
        }



        break;
    }

    }

}





void MainWindow::on_moveButton_clicked()
{

    State state = Game::getInstance()->getState();
    if (state == STARTUP_LOCATION) {                        // Startup Location
        Game* game = Game::getInstance();
        int turn = game->getTurn();
        string regionString = ui->locationCombo->currentText().toStdString();
        int regionInt = game->getRegionNumberFromStr(regionString);
        game->movePlayer(turn, regionInt);
        log("-");
        log("Player " + to_string(turn+1) + " Has moved to " + regionString);
        game->advanceGame();

        fillMoveLocations();
        lockUnlockUI();
        updateMap();

    } else if (state == MOVING) {                           // Main game moving

        string input = ui->locationCombo->currentText().toStdString();
        // Differentiate 4 cases
        // 1. Must move to lower manhattan
        // 2. Move anywhere (restrictions apply)
        // 3. Advance in manhattan
        // 4. No valid move(upper manhattan)

        Game *game = Game::getInstance();
        int turn = game->getTurn();
        Player player = game->getPlayers()[turn];
        string playerName = game->getPlayerName(turn);
        int zone = player.getZone();
        int rank = player.getRank();
        int numOfRanks = game->getMap()->getSubgraph()->getNumOfNodes();

        if (zone != 0 && game->isEmptyMainRegion()) {               // Case 1

            game->getPlayers()[turn].setZone(0);
            game->getPlayers()[turn].setRank(0);

        } else if (zone != 0 && !game->isEmptyMainRegion()) {       // Case 2


            Graph *graph = game->getMap()->getGraph();
            int zoneId = graph->getNodeNumberByName(input);
            game->getPlayers()[turn].setZone(zoneId);


        } else if (zone == 0 && rank != numOfRanks - 1) {           // Case 3

           game->getPlayers()[turn].setRank(rank+1);

        } else {                                                    // Case 4

            // Player stays in place
        }

        log ("Player " + playerName + " has moved to " + input + ".");
        game->advanceGame();

        lockUnlockUI();
        updateMap();

    }

}

void MainWindow::check6Dice(bool flag) {
    ui->diceCheckBox_1->setChecked(flag);
    ui->diceCheckBox_2->setChecked(flag);
    ui->diceCheckBox_3->setChecked(flag);
    ui->diceCheckBox_4->setChecked(flag);
    ui->diceCheckBox_5->setChecked(flag);
    ui->diceCheckBox_6->setChecked(flag);

}

void MainWindow::fillResolveDice() {


    ui->resolveCombo->clear();

    // Get dice type in a boolean
    bool diceTally [6];
    for (int i = 0; i < 6; i++) {
        diceTally[i] = false;
    }

    for (int i = 0; i < 6; i++) {
        if (rolls[i] == -1) continue;
        int tallyIndex = rolls[i] - 1;
        diceTally[tallyIndex] = true;

    }


    for (int i = 0; i < 6; i++) {
        if (diceTally[i] == true) {
            ui->resolveCombo->addItem(dr.transform(i+1).c_str());
        }
    }
}


void MainWindow::on_resolveButton_clicked()
{
    // Get diceNumber
    string diceToResolve = ui->resolveCombo->currentText().toStdString();
    int diceId = 0;
    for (int i = 1; i < 7; i++) {
        if (dr.transform(i) == diceToResolve) {
            diceId = i;
            break;
        }
    }

    // Get Number of Dice
    int numOfDice = 0;
    for (int i = 0; i < 6; i++) {
        if (rolls[i] == diceId) {
            numOfDice++;
            rolls[i] = -1;
        }
    }

    fillResolveDice();
    log("-");
    log("Resolving " + to_string(numOfDice) + " " + diceToResolve);



    // Resolve Dice
    Game *game = Game::getInstance();

    // Special Case for tiles
    if (dr.transform(diceId) == "Destruction") {
        // Unlock Destruction
        remainingDestruction = numOfDice;
        fillTilesCombo();

        if (ui->tileCombo->count() > 0) {
            ui->tilesGroup->setEnabled(true);
            ui->resolveGroup->setEnabled(false);
        }



    } else {
        string resolveMessage = game->resolveDice(diceId, numOfDice, 0);
        log(resolveMessage);

        //updatePlayerCard();

        // Check if finished resolving
        if (ui->resolveCombo->count() == 0) {       // Finished resolving
            Game::getInstance()->advanceGame();
            lockUnlockUI();
        }
    }


    // Check if finished resolving
    if (ui->resolveCombo->count() == 0) {       // Finished resolving
        Game::getInstance()->advanceGame();

        lockUnlockUI();

    }


}

void MainWindow::fillTilesCombo() {




    // Fill only tiles in borough that player can afford
    ui->tileCombo->clear();
    Game *game = Game::getInstance();
    int turn = game->getTurn();
    int zone = game->getPlayers()[turn].getZone();
    DeckOfTiles *deckOfTiles = game->getDeckOfTiles();
    int numOfTiles = deckOfTiles->getNumOfTiles();
    Tile *tiles = deckOfTiles->getTiles();

    // Add buildings tiles
    for (int stack = 0; stack < 3; stack++) {
        for (int i = 0; i < numOfTiles; i++) {
            if (tiles[i].isDestoryed()) continue;
            int activeSide = tiles[i].getActiveSide();

            if (activeSide == 0) {
                if (tiles[i].getStackNumber() == stack) {
                    if (remainingDestruction >= tiles[i].getSide(activeSide).getCost()) {
                        ui->tileCombo->addItem(tiles[i].getSide(activeSide).getDescription().c_str(), QVariant(i));
                        break;
                    }
                }
            }
        }
    }

    // Add units tiles
    for (int i = 0; i < numOfTiles; i++) {
        if (tiles[i].isDestoryed()) continue;
        int activeSide = tiles[i].getActiveSide();
        if (activeSide == 1) {
            if (remainingDestruction >= tiles[i].getSide(activeSide).getCost()) {
                ui->tileCombo->addItem(tiles[i].getSide(activeSide).getDescription().c_str(), QVariant(i));
            }
        }
    }
}

void MainWindow::updateMap() {

    ui->backgroundLabel->setScaledContents(true);
    string path = "../KONY/res/Images/Board.png";
    QPixmap pixmap = QPixmap(path.c_str());
    QPainter *paint = new QPainter(&pixmap);



    Game *game = Game::getInstance();
    Player *players = game->getPlayers();
    int numberOfPlayers = game->getNumOfPlayers();
    Node **graphNodes = game->getMap()->getGraph()->getNodes();
    Node **subGraphNodes = game->getMap()->getSubgraph()->getNodes();

    int graphSize = game->getMap()->getGraph()->getNumOfNodes();
    int subGraphSize = game->getMap()->getSubgraph()->getNumOfNodes();

    int *graphCounter = new int [graphSize];
    int *subGraphCounter = new int [subGraphSize];
    for (int i = 0; i < graphSize; i++) {
        graphCounter[i] = 0;
    }
    for (int i = 0; i < subGraphSize; i++) {
        subGraphCounter[i] = 0;
    }

    for (int i = 0; i < numberOfPlayers; i++) {
        // getPhotoPath
        // getCoordinates
        Monsters monster = players[i].getMonster();
        string monsterName = getNameFromMonster(monster);
        string path = "../KONY/res/Images/Monster" + monsterName + ".jpg";

        int zone = players[i].getZone();
        if (zone == -1) continue;
        int rank = players[i].getRank();
        cout << "Player: " << i << " Zone: " << zone << " Rank: " << rank << endl;
        int locX = graphNodes[zone]->loc_x;
        int locY = graphNodes[zone]->loc_y;

        if (zone == 0) {
            locX = subGraphNodes[rank]->loc_x;
            locY = subGraphNodes[rank]->loc_y;
        }

        if (locX == 0) continue;

        // If there is another player: shift
        if (zone != 0) {
            if (graphCounter[zone] == 1) {
                locX += 50;
                locY += 50;
            }
        } else {
            if (subGraphCounter[rank] == 1) {
                locX += 50;
                locY += 50;
            }
        }

        paint->drawImage(QRect(locX, locY, IMAGE_SIZE, IMAGE_SIZE), QImage(path.c_str()));

        // Update Counters
        if (zone != 0) {
            graphCounter[zone]++;
        } else {
            subGraphCounter[rank]++;
        }

    }

    ui->backgroundLabel->setPixmap(pixmap);
}




void MainWindow::on_finishedCardsButton_clicked()
{
    Game::getInstance()->advanceGame();

    lockUnlockUI();
}

void MainWindow::on_finishTurnButton_clicked()
{
    Game::getInstance()->advanceGame();

    fillMoveLocations();
    lockUnlockUI();

}

void MainWindow::on_showCards_clicked()
{
    int playerNumber = Game::getInstance()->getTurn();

    for(int i = 1; i <= SIZE_OF_DECK; i++){
        if(Game::getInstance()->getCards(playerNumber, i)){
            log(doc.showCard(deck, i, SIZE_OF_DECK));
        }
    }
}

void MainWindow::on_showTilesButton_clicked()
{
    Game *game = Game::getInstance();
    int numOfZones = game->getMap()->getGraph()->getNumOfNodes();
    DeckOfTiles *deckOfTiles = game->getDeckOfTiles();
    int numOfTiles = deckOfTiles->getNumOfTiles();
    Tile *tiles = deckOfTiles->getTiles();

    log("-");
    log("Tiles");
    for (int i = 0; i < numOfTiles; i++) {
        int activeSide = tiles[i].getActiveSide();
        string prefix = "";
        if (activeSide == 1) {
            prefix = "*";
        }
        if (tiles[activeSide].isDestoryed()) continue;
        int zoneNumber = tiles[i].getZone();
        string zoneName = game->getMap()->getGraph()->getNodes()[zoneNumber]->getName();
        log(prefix + "Zone " + zoneName + " " + tiles[i].getSide(activeSide).getDescription());
    }
    log("-");
}

void MainWindow::on_destroyBuildingButton_clicked()
{
    // Get Tile
    Game *game = Game::getInstance();
    int tileNumber = ui->tileCombo->currentData().toInt();
    Tile t = game->getDeckOfTiles()->getTiles()[tileNumber];
    int activeSide = t.getActiveSide();
    Side side = t.getSide(activeSide);

    // Apply effect to player
    remainingDestruction -= side.getCost();
    int trun = game->getTurn();
    Player *p = &game->getPlayers()[trun];
    p->setEnergy(p->getEnergy() + side.getEnergy());
    p->setHealth(p->getHealth() + side.getHealth());
    p->setVictoryPoints(p->getVictoryPoints() + side.getVictory());


    // Flip/Destory tile
    game->getDeckOfTiles()->getTiles()[tileNumber].flip();
    log ("Player " + to_string(trun+1) + " Destroyed " + side.getDescription());
    //updatePlayerCard();


    // Advance Game
    fillTilesCombo();
    if (ui->tileCombo->count() == 0) {
        ui->resolveGroup->setEnabled(true);
        ui->tilesGroup->setEnabled(false);


        // Check if finished resolving dice
        if (ui->resolveCombo->count() == 0) {       // Finished resolving
            Game::getInstance()->advanceGame();
            lockUnlockUI();
        }
    }



}

















