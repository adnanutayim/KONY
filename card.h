#ifndef CARD_H
#define CARD_H
#include "string.h"
#include <iostream>

class card
{
private:
    int cost;
    std::string howToPlay;
    std::string effect;
public:
    card();
    card(int, std::string, std::string);
    void setCost(int);
    void setEffect(std::string);
    void setHowToPlay(std::string);
    int getCost();
    std::string getHowToPlay();
    std::string getEffect();
};

#endif // CARD_H
