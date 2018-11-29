#ifndef CARDEFFECTOBSERVER_H
#define CARDEFFECTOBSERVER_H
#include "observer.h"
#include "mainwindow.h"

class CardEffectObserver : public Observer
{
public:
    CardEffectObserver(MainWindow *mw);
    void Update();

private:
    MainWindow *mw;
};

#endif // CARDEFFECTOBSERVER_H
