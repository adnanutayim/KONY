#include "mainwindow.h"
#include "ui_mainwindow.h"



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


    diceRoll dr;
    dr.rollDice(diceToRoll, rolls);


    QString qs;
    qs.append("Rolls: ");

    for (int i = 0; i < 8; i++) {
        qs.append(QString::number(rolls[i]));
        qs.append(" ");
    }

    ui->plainTextEdit->appendPlainText(qs);


}
