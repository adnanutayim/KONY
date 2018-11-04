#include "graph.h"
#include "iostream"
#include "queue"
using namespace std;

Graph::Graph()
{
    Graph(0);
}

Graph::Graph(int num) {
    numOfNodes = num;
    if (num !=0) {
        edges = new bool* [numOfNodes];
        for (int i = 0; i < numOfNodes; i++) {
            edges[i] = new bool [numOfNodes];
            for (int j = 0; j < numOfNodes; j++) {
                edges[i][j] = false;
            }
        }
    }
}
Graph::~Graph() {
    // Delete adjacency matrix
    if (!isEmpty()) {
        for (int i = 0; i < numOfNodes; i++) {
            delete [] edges[i];
            edges[i] = NULL;
        }
        delete [] edges;
        edges = NULL;
    }

    // Delete array of nodes
    if (!isEmpty()) {
        for (int i = 0; i < numOfNodes; i++) {
            delete nodes[i];
            nodes[i] = NULL;
        }
        delete [] nodes;
        nodes = NULL;
    }
}
void Graph::addEdge(int a, int b) {
    edges[a][b] = true;
}

bool Graph::isEmpty() {
    return numOfNodes == 0;
}

bool Graph::isEdge(int a, int b) {
    return edges[a][b];
}

bool Graph::isConnected() {

    if (isEmpty()) {
        return false;
    }

    // BFS
    bool *visited = new bool [numOfNodes];
    queue<int> q;

    for (int i = 0; i < numOfNodes; i++) {
        visited[i] = false;
    }

    q.push(0);
    visited[0] = true;
    while (!q.size() == 0) {
        int nodeId = q.front();
        q.pop();
        for (int i = 0; i < numOfNodes; i++) {
            if (i == nodeId) {
                continue;
            }
            if (isEdge(nodeId, i)) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // Check if all are visited
    bool connected = true;
    for (int i = 0; i < numOfNodes; i++) {
        if (!visited[i]) {
            return false;
        }
    }


    delete [] visited;
    visited = NULL;
    return connected;
}


void Graph::printGraph() {
    cout << "Number of Nodes: " << numOfNodes << endl;
    for (int i = 0; i < numOfNodes; i++) {
        for (int j = 0; j < numOfNodes; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::getNumOfNodes() {
    return numOfNodes;
}

int Graph::getNodeNumberByName(string s) {
    for (int i = 0; i < numOfNodes; i++) {
        if (s == nodes[i]->getName()) {
            return i;
        }
    }
    // If not found
    return -1;
}



