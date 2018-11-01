#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diceroll.h"
#include "map.h"
#include "qlabel.h"
#include "deckOfCards.h"
#include "deckOfTiles.h"
#include "card.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void log(string s);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_buyCards_clicked();


    void on_wipeBoard_clicked();

private:
    Ui::MainWindow *ui;
    DiceRoll dr;
    Map map;
    int rolls [8];
    void setDiceImage(QLabel *, int);
    void setCardImage(QLabel *, int);

};

#endif // MAINWINDOW_H
