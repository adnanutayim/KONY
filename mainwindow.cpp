#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deckOfCards.h"
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


//    deck.printDeck();
//    deck.shuffleDeck();
//    cout << "\nSHUFFLE\n" << endl;
//    deck.printDeck();
//    cout << "\nDEAL\n" << endl;
//    currentCard = deck.dealCard();
//    cout << currentCard.printCard() << endl;
DeckOfCards deck;
Card currentCard;
void MainWindow::on_pushButton_2_clicked()
{
    log("Shuffling...\n");
    log(deck.printDeck());
}

void MainWindow::on_pushButton_3_clicked()
{
    log("Dealing...\n--------------------\n");
    currentCard = deck.dealCard();
    log(currentCard.printCard());
    log("\n--------------------\n");
}
