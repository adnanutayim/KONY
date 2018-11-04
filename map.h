#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "string.h"
#include "graph.h"
#include "node.h"
#include <fstream>
#include <string>
using namespace std;

class Map
{
public:
    Map();
    ~Map();
    bool load(string filename);
    bool verifyConnectedGraph();
    bool verifyConnectedSubgraph();
    bool verifyEachRegionIsNode();
    Graph *getGraph();
    Graph *getSubgraph();


private:
    Graph *graph;
    Graph *subGraph;
    string backGroundImage;

    // Keywords
    const string keyword_regions = "Regions";
    const string keyword_subregions = "Sub-regions";
    const string keyword_image = "Image";
};

#endif // MAP_H
