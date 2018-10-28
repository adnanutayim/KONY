#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card
{
private:
    int id;
    std::string name;
    int cost;
    std::string howToPlay;
    std::string effect;


public:
    Card();
    Card(int id, std::string, int, std::string, std::string);
    ~Card();
    std::string printCard() const;
};

#endif // CARD_H
