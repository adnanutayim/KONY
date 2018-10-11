#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card
{
private:
    std::string name;
    int cost;
    std::string howToPlay;
    std::string effect;


public:
    Card();
    Card(std::string, int, std::string, std::string);
    ~Card();
    std::string printCard() const;
};

#endif // CARD_H
