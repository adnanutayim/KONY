#include "diceroll.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

DiceRoll::DiceRoll(){
    srand(time(0));
}
void DiceRoll::rollDice(bool states[], int values[]){
    int size = sizeof(states)/sizeof(states[0]);
    for(int i = 0; i<size; i++){
        if(states[i] == true){
            int newVal = roll();
            values[i] = newVal;
        }
    }
}

int DiceRoll::roll(){
    int x;
    x = (rand() % 6 +1);
    return x;
}

