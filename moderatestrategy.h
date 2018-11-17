#ifndef MODERATESTRATEGY_H
#define MODERATESTRATEGY_H
#include "strategy.h"


class ModerateStrategy : public Strategy         // inherits strategy
{
public:
    ModerateStrategy();                          // Default constructor
    void execute(State currentState);            // Executes

};

#endif // MODERATESTRATEGY_H
