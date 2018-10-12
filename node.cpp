#include "node.h"

Node::Node() {

}

Node::Node(int id, string name, bool subregions, int rank, int loc_x, int loc_y) {
    this->id = id;
    this->name = name;
    this->subregions = subregions;
    this->rank = rank;
    this->loc_x = loc_x;
    this->loc_y = loc_y;
}
bool Node::hasSubRegions() {
    return subregions;
}

string Node::getName() {
    return name;
}
