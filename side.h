#ifndef SIDE_H
#define SIDE_H
#include <iostream>
using namespace std;


class Side
{
public:
    Side();
    void setName(string);
    void setCost(int);
    void setEnergy(int);
    void setHealth(int);
    void setVictory(int);

private:
    string name;
    int cost;
    int energy;
    int health;
    int victory;
};

#endif // SIDE_H
