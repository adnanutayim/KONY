#include "monsters.h"


Monsters getMonsterFromString(string monsterName) {
    if (monsterName == "CaptainFish") {
        return CaptainFish;
    } else if (monsterName == "Drakonis") {
        return Drakonis;
    } else if (monsterName == "Kong") {
        return Kong;
    } else if (monsterName == "Mantis") {
        return Mantis;
    } else if (monsterName == "Rob") {
        return Rob;
    } else {
        return Sheriff;
    }
}
