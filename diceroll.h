#ifndef DICEROLL_H
#define DICEROLL_H


class diceRoll
{
public:
    diceRoll();

    int* dummyRoll(bool* diceToRoll, int num) {
        int* dice = new int [num];
        for (int i = 0; i < num; i++) {
            if (diceToRoll[i]) {
                dice[i] = 3;
            } else {
                dice[i] = 0;
            }
        }
        return dice;
    }
};

#endif // DICEROLL_H
