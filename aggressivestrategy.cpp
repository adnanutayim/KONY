#include "aggressivestrategy.h"
#include "game.h"
#include "diceroll.h"

// Default constructor
AggressiveStrategy::AggressiveStrategy() {

}

// Execute
void AggressiveStrategy::execute(State currentState) {

    // Initialization
    Game *game = Game::getInstance();
    int turn = game->getTurn();
    Player *p = &game->getPlayers()[turn];

    // Switch statement
    switch (currentState) {
    case STARTUP_ROLL: {
        // roll 8 dice
        bool diceToRoll [8];
        for (int i = 0; i < 8; i++) {
            diceToRoll[i] = true;
        }
        DiceRoll dr;
        dr.rollDice(diceToRoll, rolls);

        // Count Attacks
        int attacks = 0;
        for (int i = 0; i < 8; i++) {
            if (dr.transform(rolls[i]) == "Attack") {
                attacks++;
            }
        }
        game->registerStartupRoll(turn, attacks);

        cout << "----------------------------------" << endl;
        cout << "Computer Player: Aggresive " << p->getName() << endl;
        cout << "Rolls:\n";
        for (int i = 0; i < 8; i++) {
            cout << dr.transform(rolls[i]) + " ";
        }
        cout << "\n\n";

        break;
    }

    case STARTUP_LOCATION: {

        // Pick last place with no more than 2 players
        Graph *graph = game->getMap()->getGraph();
        for (int i = graph->getNumOfNodes() - 1; i >= 0; i--) {
            if (game->playersInRegion(i) < 2) {
                p->setZone(i);
                cout << "Computer Player moved to " << graph->getNodes()[i]->getName() << "\n\n";

                break;
            }
        }
        break;
    }


    case ROLLING_DICE: {
        // Prepare 6 dice
        bool diceToRoll [8];
        for (int i = 0; i < 6; i++) {
            diceToRoll[i] = true;
        }
        diceToRoll[6] = false;
        diceToRoll[7] = false;

        // Roll 6 dice
        DiceRoll dr;
        dr.rollDice(diceToRoll, rolls);

        // 2 iterations of picking preferance with dice
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                string dice = dr.transform(rolls[j]);
                if (dice == "Destruction" || dice == "Attack" || dice == "Ouch!") {
                    diceToRoll[j] = false;
                }
            }
        }
        cout <<  "----------------------------------" << endl;
        cout << "Computer Player: Moderate " << p->getName() << endl;
        cout << "Rolls:\n";
        for (int i = 0; i < 8; i++) {
            cout << dr.transform(rolls[i]) << " ";
        }
        cout << "\n\n";

        break;
    }

    case RESOLVING_DICE: {

        for (int i = 0; i < 6; i++) {
            cout << game->resolveDice(rolls[i], 1, 0) << endl;
        }
        cout << "\n\n";
        break;
    }


    case MOVING: {

        if (p->getZone() == 0) {    // if in manhattan advance one step
            int rank = p->getRank();
            rank++;
            if (rank > 2) {
                rank = 2;
            }
            p->setRank(rank);
        } else if (game->playersInRegion(0) == 0) { // if Manhattan is empty, move there
            p->setZone(0);
            p->setRank(0);
        }

        // If can't go to manhattan, stay in place (no updates)
        cout << "Computer Player moved to " << game->getMap()->getGraph()->getNodes()[p->getZone()]->getName() << "\n\n";
        break;
    }


    case BUYING_CARDS: {

        bool bought;
        //bought = Game::getInstance()->buyCard(p->getPlayerNumber(), 1, 3);
        if (bought) {
            cout << "Computer Player bought cards number 1\n";
        }
        break;
    }



    case FINISHING_TURN:

        cout << "Computer Player Finished its turn\n";
        cout <<  "----------------------------------" << endl;
        cout << std::flush;
        break;

    }
}
