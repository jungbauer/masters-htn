#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "../Level.h"
#include "../Utils/log.h"

#include "Connection.h"

using namespace std;

struct Node
{
    int graph_pos;
    int x_pos;  // The grid position of this node.
    int y_pos;
    static const int size = 8;
    Connection connections[size];
};

/// Graph Class
class Graph {
	public:
        Graph ();

        Node getNode(int fromNode);
//        void addNode(Node n);
        void generateGraph(Level &level);
        int getSize();

        vector<Node> nodes_;

    private:

};

#endif
