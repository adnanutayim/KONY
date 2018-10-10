#include "map.h"
#include "sstream"

Map::Map()
{
    graph = NULL;
    subGraph = NULL;
}

Map::~Map() {

    if (graph != NULL) {
        delete graph;
    }
}


bool Map::load(string filename) {

    ifstream input;
    input.open(filename);
    cout << "Good File: " << input.good() << endl;
    if (!input.good()) {
        input.close();
        return false;
    }
    string line;

    while (std::getline(input, line)) {
        istringstream iss(line);

        if (line[0] == '#') {                          // Comment
            continue;
        }

        if (line[0] == '[') {                           // Header []
            string keyword;
            char c;
            iss >> c;
            iss >> keyword;
            cout << "Reading " << keyword << endl;
            int num;
            iss >> num;                                  // Num of Lines within Section
            if (keyword == keyword_regions) {            // Regions

                graph = new Graph(num);
                graph->nodes = new Node* [num];
                for (int i = 0; i < num; i++) {

                    // Read a new section line
                    std::getline(input, line);
                    istringstream sectionline(line);

                    // Read properties
                    string name;
                    int id, loc_x, loc_y;
                    bool has_subgraphs;
                    sectionline >> name >> id >> has_subgraphs >> loc_x >> loc_y;

                    // Initialize Node
                    graph->nodes[i] = new Node(id, name, has_subgraphs, -1, loc_x, loc_y);

                    // Read Edges
                    int edgeEnd;
                    while (sectionline >> edgeEnd) {
                        graph->addEdge(id, edgeEnd);
                        graph->addEdge(edgeEnd, id);
                    }
                }
                // For Testing:
                cout << "Graph" << endl;
                graph->printGraph();
                cout << "--------------------------------------------------------" << endl;


            } else if (keyword == keyword_subregions) {  // Subregions

                subGraph = new Graph(num);
                subGraph->nodes = new Node* [num];
                for (int i = 0; i < num; i++) {

                    // Read a new section line
                    std::getline(input, line);
                    istringstream sectionline(line);

                    // Read properties
                    string name;
                    int id, loc_x, loc_y, rank, parent_id;
                    sectionline >> name >> id >> loc_x >> loc_y >> parent_id >> rank;

                    // Initialize Node
                    subGraph->nodes[i] = new Node(id, name, false, rank, loc_x, loc_y);

                    // Read Edges
                    int edgeEnd;
                    while (sectionline >> edgeEnd) {
                        subGraph->addEdge(id, edgeEnd);
                    }
                }
                // For Testing:
                cout << "Sub Graph:" << endl;
                subGraph->printGraph();
                cout << "--------------------------------------------------------" << endl;

            } else if (keyword == keyword_image) {
                // In order to change image later(if needed)
            }
        }
    }

    input.close();
    return true;
}

bool Map::verifyConnectedGraph() {
    return graph->isConnected();
}

bool Map::verifyConnectedSubgraph() {
    return subGraph->isConnected();
}

bool Map::verifyEachRegionIsNode() {
    // This is true by construction
    return true;
}

