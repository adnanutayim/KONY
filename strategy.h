#ifndef STRATEGY_H
#define STRATEGY_H
#include "state.h"
#include <iostream>
#include <string>
using namespace std;

class Strategy {
public:
    virtual void execute(State currentState) = 0;


protected:
    int rolls[8];
};

#endif // STRATEGY_H
