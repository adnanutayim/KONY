#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <diceroll.h>
#include <deck.h>

using namespace std;

int main(int argc, char *argv[])
{
//    bool states[8] = {0, 1, 0, 1, 1, 1, 0, 0};
//    int values[8] = {6, 0, 6, 0, 0, 0, 0, 0};

//    diceRoll dice;

//    dice.rollDice(states, values);

//    for (int i = 0; i<8; i++){
//        cout << values[i] << endl;
//    };

    deck dck;
    dck.createDeck();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
