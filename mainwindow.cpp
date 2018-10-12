#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deckOfCards.h"
#include "deckOfTiles.h"
#include <string>
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 8; i++) {
        rolls[i] = 0;
    }

    // Background Board
    ui->backgroundLabel->setScaledContents(true);
    string path = "../KONY/res/Images/Board.png";
    QPixmap pixmap = QPixmap (path.c_str());
    ui->backgroundLabel->setPixmap(pixmap);

    // Dice Labels
    setDiceImage(ui->diceLabel1, 1);
    setDiceImage(ui->diceLabel2, 2);
    setDiceImage(ui->diceLabel3, 3);
    setDiceImage(ui->diceLabel4, 4);
    setDiceImage(ui->diceLabel5, 5);
    setDiceImage(ui->diceLabel6, 6);


}

void MainWindow::setDiceImage(QLabel *label, int dice_roll) {

    label->setScaledContents(true);
    DiceRoll dr;
    string diceName = dr.transform(dice_roll);
    string path = "../KONY/res/Images/" + diceName + ".PNG";
    QPixmap pixmap = QPixmap (path.c_str());
    label->setPixmap(pixmap);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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

DeckOfCards deck;
Card currentCard;
void MainWindow::on_pushButton_2_clicked()
{
    deck.shuffleDeck();
    log("Shuffling...\n");
    log(deck.printDeck());
}

void MainWindow::on_pushButton_3_clicked()
{
    log("Dealing...\n--------------------");
    currentCard = deck.dealCard();
    log(currentCard.printCard());
    log("--------------------\n");
}
DeckOfTiles tileDeck;
Tile currentTile;
void MainWindow::on_pushButton_4_clicked()
{
    tileDeck.shuffleTiles();
    log("Shuffling Tiles...\n");
    log(tileDeck.printDeckTiles());
}

void MainWindow::on_pushButton_5_clicked()
{
    log("Dealing Tile...\n--------------------");
    currentTile = tileDeck.dealTile();
    log(currentTile.printTile());
    log("--------------------\n");
}

void MainWindow::on_pushButton_6_clicked()
{
    log("Flipping Tile...\n--------------------");
    currentTile = tileDeck.flipTile(0);
    log(currentTile.printTile());
    log("--------------------\n");
}

void MainWindow::on_pushButton_7_clicked()
{
    log("Destroying Tile...\n--------------------");
    currentTile = tileDeck.destroyTile(0);
    log(currentTile.printTile());
    log("--------------------\n");
}
