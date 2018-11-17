#ifndef PLAYERCARD_H
#define PLAYERCARD_H
#include "observer.h"
#include "player.h"
#include "game.h"
#include "mainwindow.h"

class PlayerCard : public Observer          // Inherets observor
{
public:
    PlayerCard();                           // Default Constructor
    PlayerCard(Player*, Ui::MainWindow*&);  // Non default constructor
    ~PlayerCard();                          // Destructor
    void Update();                          // Update
    void display();                         // Display
    void observe(Player *p);                // To attach



private:
    Player *_subject;                       // pointer to subject
        Ui::MainWindow *ui;                 // pointer to UI

};                                          // End of class

#endif // PLAYERCARD_H
