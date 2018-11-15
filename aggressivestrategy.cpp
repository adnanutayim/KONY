#include "aggressivestrategy.h"
#include "game.h"

void AggressiveStrategy::execute(int playerNum, State state){
    Game *game = Game::getInstance();

    switch (state) {

    case STARTUP_ROLL:
    break;

    case STARTUP_LOCATION:
    break;


    case ROLLING_DICE:
        state = RESOLVING_DICE;
        break;

    case RESOLVING_DICE:
        state = MOVING;
        break;

    case MOVING:
        state = BUYING_CARDS;
        break;

    case BUYING_CARDS:
        state = FINISHING_TURN;
        break;

    case FINISHING_TURN:
        state = ROLLING_DICE;
        break;

    }
}
