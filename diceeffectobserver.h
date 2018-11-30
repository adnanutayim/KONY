#ifndef DICEEFFECTOBSERVER_H
#define DICEEFFECTOBSERVER_H
#include "observer.h"
#include "mainwindow.h"


class DiceEffectObserver : public Observer
{
public:
    DiceEffectObserver(){}              // Default Constructor
    DiceEffectObserver(MainWindow *mw); // Non-default Constructor
    void Update();                      // Overriden Function

private:
    MainWindow *mw;
};

#endif // DICEEFFECTOBSERVER_H
