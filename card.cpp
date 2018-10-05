#include "card.h"

card::card(){
    int cost = 0;
    std::string howToPlay = "";
    std::string effect = "";
}

card::card(int c, std::string h, std::string e){
    int cost = c;
    std::string howToPlay = h;
    std::string effect = e;
}
