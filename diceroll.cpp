#include "diceroll.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

diceRoll::diceRoll(){
    srand(time(0));
}
void diceRoll::rollDice(bool states[], int values[]){
    int size = sizeof(states)/sizeof(states[0]);
    for(int i = 0; i<size; i++){
        if(states[i] == true){
            int newVal = roll();
            values[i] = newVal;
        }
    }
}

int diceRoll::roll(){
    int x;
    x = (rand() % 6 +1);
    return x;
}

