#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class card
{
private:
    std::string cost;
    std::string howToPlay;
    std::string effect;

public:
    card();
    card(std::string, std::string, std::string);
    std::string printCard() const;
};

#endif // CARD_H
