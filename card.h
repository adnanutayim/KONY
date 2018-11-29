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
    int vp;
    int energy;
    int health;


public:
    Card();
    Card(int id, std::string, int, std::string, std::string, int, int, int);
    ~Card();
    void setId(int);
    int getId();

    void setCost(int);
    int getCost();

    std::string printCard() const;
    int displayId();

    int getVp();
    void setVp(int);

    int getEnergy();
    void setEnergy(int);

    int getHealth();
    void setHeath(int);

};

#endif // CARD_H
