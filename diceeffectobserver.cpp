#include "diceeffectobserver.h"
#include "game.h"

DiceEffectObserver::DiceEffectObserver(MainWindow *_mw)
{
    mw = _mw;
}

void DiceEffectObserver::Update() {
    DiceRoll dr;
    int turn = Game::getInstance()->getTurn();
    mw->log("-");
    mw->log("Dice Effect: For player " + to_string(turn+1) + ":");
    mw->log("");

    // Tally the dices to avoid repetition
    bool tally[6];

    // Initialize to False
    for (int i = 0; i < 6; i++) {
        tally[i] = false;
    }

    // Tally
    for (int i = 0; i < 6; i++) {
        tally[mw->rolls[i]-1] = true;
    }

    // Print messages for dice we have
    for (int i = 0; i < 6; i++) {
        if (tally[i]) {
            int roll = i+1;
            if (dr.transform(roll) == "Attack") {
                mw->log("Attack: If you are in Manhattan, Players outside Manhattan will lose 1 HP per attack");
            } else if (dr.transform(roll) == "Energy") {
                mw->log("Energy: Gain 1 energy point per energy dice");
            } else if (dr.transform(roll) == "Destruction") {
                mw->log("Destruction: Allows you to destroy buildings/units if you have enough number of destruction points");
            } else if (dr.transform(roll) == "Heal") {
                mw->log("Heal: for every heal dice, you gain one HP");
            } else if (dr.transform(roll) == "Celebrity") {
                mw->log("Celebrity: Allows you to gain victory points, Once you have 20VP you win the game");
            } else if (dr.transform(roll) == "Ouch!") {
                mw->log("Ouch!: 1 Ouch causes units in your zone to attack you. 2 causes units in your zone to attack every player in the same zone, 3 will get all players attacked by units in their zone");
            }
            mw->log("");
        }
    }
}
