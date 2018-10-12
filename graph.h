#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include "node.h"

class Graph
{
public:
    Graph();
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    bool isEmpty();
    bool isEdge(int, int);              // To test if there's an edge btwn 2 nodes
    bool isConnected();             // To verify the graph is connected
    void printGraph();
    Node **nodes;
    int getNumOfNodes();
    int getNodeNumberByName(string s);

private:
    int numOfNodes;
    bool **edges;
};

#endif // GRAPH_H
