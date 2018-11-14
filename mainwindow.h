#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diceroll.h"
#include "map.h"
#include "qlabel.h"
#include "deckOfCards.h"
#include "deckOfTiles.h"
#include "card.h"
#include "clickablelabel.h"
#include "qpainter.h"

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

    void on_buyCards_clicked();


    void on_wipeBoard_clicked();

    void on_rollButton_clicked();

    void on_moveButton_clicked();

    void on_showCards_clicked();

    void on_resolveButton_clicked();

    void on_finishedCardsButton_clicked();

    void on_finishTurnButton_clicked();




private:
    Ui::MainWindow *ui;
    DiceRoll dr;
    Map map;
    int rolls [8];
    void setDiceImage(QLabel *, int);

    void setCardImage(QLabel *, int);

    void set8DiceEnabled(bool flag);
    void set6DiceEnabled(bool flag);
    void check6Dice(bool flag);
    void updateHeader();
    void lockUnlockUI();
    void fillMoveLocations();
    void updatePlayerCard();
    void fillResolveDice();
    int numberOfRolls;
    void updateMap();



};

#endif // MAINWINDOW_H
