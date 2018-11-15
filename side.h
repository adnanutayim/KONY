#ifndef SIDE_H
#define SIDE_H
#include <iostream>
#include<string>
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
    string getDescription();

    string getName();
    int getCost();
    int getEnergy();
    int getHealth();
    int getVictory();

private:
    string name;
    int cost;
    int energy;
    int health;
    int victory;

};

#endif // SIDE_H
