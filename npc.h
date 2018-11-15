#ifndef NPC_H
#define NPC_H
#include "strategy.h"
#include "state.h"

class NPC {
private:
    Strategy *strategy;
public:
    NPC(){}
    NPC(Strategy *initStrategy){
        this->strategy = initStrategy;
    }
    void setStrategy(Strategy *newStrategy){
        this->strategy = newStrategy;
    }

    void execute(int p, State s){
        return this->strategy->execute(p, s);
    }

};

#endif // NPC_H
