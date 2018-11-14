#ifndef PLAYERCARD_H
#define PLAYERCARD_H
#include "observer.h"
#include "player.h"
#include "game.h"
#include "mainwindow.h"

class PlayerCard : public Observer
{
public:
    PlayerCard();
    PlayerCard(Player*, Ui::MainWindow*&);
    ~PlayerCard();
    void Update();
    void display();
    void observe(Player *p);
private:
    Player *_subject;
    Ui::MainWindow *ui;

};

#endif // PLAYERCARD_H
