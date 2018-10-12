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

std::string DiceRoll::transform(int r){
    switch (r) {
        case 1 : return "Energy";
        case 2 : return "Attack";
        case 3 : return "Destruction";
        case 4 : return "Heal";
        case 5 : return "Celebrity";
        case 6 : return "Ouch!";
    default: return "";
    }
}

