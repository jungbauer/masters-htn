#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <cstdlib>
#include <cmath>
#include <set>

#include "Path.h"
#include "Graph.h"
#include "../Utils/log.h"
#include "../Level.h"

using namespace std;

class PathFinding
{
    public:
        PathFinding();

        bool pathFind(Level& level, Graph& graph, int from_x, int from_y, int to_x, int to_y, Path& path);
        bool pathFind(Level& level, Graph& graph, int from_x, int from_y, int goal_node, Path& path);
        Path pathFindAStar(Graph &graph, int start, int end);

        float heuristicEuclidean(int start_x, int start_y, int end_x, int end_y);
        multiset<NodeRecord, NodeRecordCompare>::iterator findNode(multiset<NodeRecord, NodeRecordCompare> &set, int node);
        //void copyList(multiset<NodeRecord, NodeRecordCompare> &inSet, multiset<NodeRecord, NodeRecordCompare> &outSet);
        void printList(multiset<NodeRecord, NodeRecordCompare> list);

    private:

};
#endif
