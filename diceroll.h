#ifndef DICEROLL_H
#define DICEROLL_H

#include <string>
#include "subject.h"

class DiceRoll : public Subject
{
public:
    void rollDice(bool [], int []);
    int roll();
    DiceRoll();
    std::string transform(int);

};

#endif // DICEROLL_H
