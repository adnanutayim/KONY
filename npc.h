#ifndef NPC_H
#define NPC_H
#include "strategy.h"

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

    void execute(){
        return this->strategy->execute();
    }

};

#endif // NPC_H
