#ifndef STRATEGY_H
#define STRATEGY_H
#include "state.h"

class Strategy {
public:
    virtual void execute(int, State) = 0;
};

#endif // STRATEGY_H
