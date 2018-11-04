#ifndef MONSTERS_H
#define MONSTERS_H

#include <string>
using namespace std;

enum Monsters {
    CaptainFish,
    Drakonis,
    Kong,
    Mantis,
    Rob,
    Sheriff
};

Monsters getMonsterFromString(string name);
string getNameFromMonster(Monsters monster);

#endif // MONSTERS_H
