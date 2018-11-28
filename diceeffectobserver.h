#ifndef DICEEFFECTOBSERVER_H
#define DICEEFFECTOBSERVER_H
#include "observer.h"
#include "mainwindow.h"


class DiceEffectObserver : public Observer
{
public:
    DiceEffectObserver(MainWindow *mw);
    void Update();

private:
    MainWindow *mw;
};

#endif // DICEEFFECTOBSERVER_H
