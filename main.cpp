#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "diceroll.h"
#include "deckOfCards.h"
#include <diceroll.h>
#include "string.h"
#include "deckOfTiles.h"
#include "welcomescreen.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomeScreen ws;
    ws.show();

    return a.exec();
}
