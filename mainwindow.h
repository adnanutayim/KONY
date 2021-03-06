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
#include "popup.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void log(string s);
    void upate6DiceLabels();
    ~MainWindow();
    Ui::MainWindow *ui;
    void updateMap();
    DiceRoll dr;
    int rolls [8];


private slots:

    void on_buyCards_clicked();


    void on_wipeBoard_clicked();

    void on_rollButton_clicked();

    void on_moveButton_clicked();

    void on_showCards_clicked();

    void on_resolveButton_clicked();

    void on_finishedCardsButton_clicked();

    void on_finishTurnButton_clicked();

    void on_showTilesButton_clicked();

    void on_destroyBuildingButton_clicked();


private:
//    Ui::MainWindow *ui;
    Popup *pu;
    Map map;

    void setDiceImage(QLabel *, int);

    void setCardImage(QLabel *, int);

    void set8DiceEnabled(bool flag);
    void set6DiceEnabled(bool flag);
    void check6Dice(bool flag);
    void lockUnlockUI();
    void fillMoveLocations();
    void updatePlayerCard();
    void fillResolveDice();
    void fillTilesCombo();
    int numberOfRolls;
    int remainingDestruction;




};

#endif // MAINWINDOW_H
