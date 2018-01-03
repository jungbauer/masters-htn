#ifndef PATH_H
#define PATH_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
//#include <set>

#include "Connection.h"
#include "../Utils/Coord.h"
#include "../Utils/VecXY_Float.h"
#include "../Utils/log.h"
#include "Graph.h"

struct NodeRecord
        {
            // node references are wrt the graph
            int node;
            int parentNode;
            float costSoFar;// g(n)
            float heuristic; // h(n)
            float estimatedTotalCost; // f(n)
        };

class NodeRecordCompare
{
    public:
        bool operator()(NodeRecord n1, NodeRecord n2)
        {
            if(n1.estimatedTotalCost < n2.estimatedTotalCost)
                return true;
            else
                return false;
        }
};

/// Path Class
class Path {
	public:
        Path();
//        Path(multiset<NodeRecord, NodeRecordCompare> oList, multiset<NodeRecord, NodeRecordCompare> cList);

        bool addConnection(Connection conn);
        void cullPath(Graph &graph, Level &level);

        // Path following
        bool progressPosition(Coord &nextC);
        Coord getCurrentCheckPoint();
        int getPathSize();

        // Accessing and setting methods
        void setStart(int start);
        int getStart();
        void setEnd(int end);
        int getEnd();
        void getPath(std::vector<Connection> &outPath);
        void setStartCoord(int x, int y);
        void setEndCoord(int x, int y);

//        multiset<NodeRecord, NodeRecordCompare> openList;
//        multiset<NodeRecord, NodeRecordCompare> closedList;

        std::vector<Connection> _path;
        std::vector<Coord> _culled_path;

        Coord get_End_Coord();
        VecXY_Float get_End_Vec();
        bool complete_Check();

    private:
        int _startNode;
        int _endNode;
        unsigned int _position;
        bool path_complete;
        Coord start_coord;
        Coord end_coord;
};

#endif
