#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int num = 6;
    bool* diceToRoll = new bool [num];
    diceToRoll[0] = ui->diceCheckBox_1->isChecked();
    diceToRoll[1] = ui->diceCheckBox_2->isChecked();
    diceToRoll[2] = ui->diceCheckBox_3->isChecked();
    diceToRoll[3] = ui->diceCheckBox_4->isChecked();
    diceToRoll[4] = ui->diceCheckBox_5->isChecked();
    diceToRoll[5] = ui->diceCheckBox_6->isChecked();

    diceRoll dr;
    int* rolls = dr.dummyRoll(diceToRoll, 6);

    QString qs;
    qs.append("Rolls: ");

    for (int i = 0; i < num; i++) {
        qs.append(QString::number(rolls[i]));
        qs.append(" ");
    }

    ui->plainTextEdit->appendPlainText(qs);


}
