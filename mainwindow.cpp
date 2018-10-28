#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>

const int SIZE_OF_DECK = 5;
const int SIZE_OF_BOARD = 3;
Card deck[SIZE_OF_DECK];
Card board[SIZE_OF_BOARD];
Card *nextCard = &deck[0];
DeckOfCards doc;


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

    deck[0] = Card(1, "Violent Star", 3, "Keep", "Deal 2 dammage to the monster...");
    deck[1] = Card(2, "Sharp Shooter", 4, "Keep", "You destroy Jets that are not in...");
    deck[2] = Card(3, "Of Another World", 6, "Keep", "You can use hearts as energy and energy as hearts");
    deck[3] = Card(4, "Extra Head", 7, "Keep", "You get 1 extra die");
    deck[4] = Card(5, "Ego Trip", 3, "Keep", "Gain 1 energy when you take superstar");

    doc.shuffleDeck(deck, SIZE_OF_DECK);
    doc.initializeBoard(deck, board, nextCard);

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

void MainWindow::on_buyCards_clicked()
{
    bool cardsToBuy[3];
    cardsToBuy[0] = ui->cardCheckBox_1->isChecked();
    cardsToBuy[1] = ui->cardCheckBox_2->isChecked();
    cardsToBuy[2] = ui->cardCheckBox_3->isChecked();

    for(int i = 0; i < SIZE_OF_BOARD; i++){
        if(cardsToBuy[i] == 1){
            doc.fillCard(deck, board, i, nextCard);
        }
    }

    setCardImage(ui->cardLabel_1, board[0].displayId());
    setCardImage(ui->cardLabel_2, board[1].displayId());
    setCardImage(ui->cardLabel_3, board[2].displayId());
}

