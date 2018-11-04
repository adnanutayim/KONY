#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "string.h"
using namespace std;

class Node
{
public:
    Node();
    Node(int, string, bool, int, int, int);
    bool hasSubRegions();
    string getName();
    int loc_x, loc_y;

private:
    int id;
    string name;
    bool subregions;    // Whether it has subregions
    int rank;           // If a subregion, rank within that region


};

#endif // NODE_H
