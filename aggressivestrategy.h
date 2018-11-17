#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H
#include "strategy.h"

class AggressiveStrategy : public Strategy          // Inherets strategy class
{
public:
    AggressiveStrategy();                           // Default consturctor
    void execute(State currentState);               // Executes
};

#endif // AGGRESSIVESTRATEGY_H
