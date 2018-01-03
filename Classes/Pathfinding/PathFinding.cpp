#include "PathFinding.h"

PathFinding::PathFinding()
{

}

float PathFinding::heuristicEuclidean(int start_x, int start_y, int end_x, int end_y)
{
    float diff_x = (float)end_x - (float)start_x;
    float diff_y = (float)end_y - (float)start_y;

    float ans = sqrt((diff_x*diff_x)+(diff_y*diff_y));

    return ans;
}

bool PathFinding::pathFind(Level& level, Graph& graph, int from_x, int from_y, int to_x, int to_y, Path& path)
{
    bool path_found = false;
    int start_node = -1, goal_node = -1;

    if((level.getPathRefFromPixels(from_x, from_y, start_node) == true) && (level.getPathRefFromPixels(to_x, to_y, goal_node) == true))
    {
        path = pathFindAStar(graph, start_node, goal_node);
        path.setStartCoord(from_x, from_y); // imporant for the path cull process.
        path.setEndCoord(to_x, to_y); // imporant for the path cull process.
        path_found = true;
    }

    return path_found;
}

bool PathFinding::pathFind(Level& level, Graph& graph, int from_x, int from_y, int goal_node, Path& path)
{
    bool path_found = false;
    int start_node = -1;

    if((level.getPathRefFromPixels(from_x, from_y, start_node) == true))
    {
        path = pathFindAStar(graph, start_node, goal_node);
        path.setStartCoord(from_x, from_y); // imporant for the path cull process.

        Node g_node = graph.getNode(goal_node);
        int x, y;
        level.getPixelPositionFromGrid(g_node.x_pos, g_node.y_pos, x, y);
        path.setEndCoord(x, y); // imporant for the path cull process.

        path_found = true;
    }

    return path_found;
}

Path PathFinding::pathFindAStar(Graph &graph, int start, int goal)
{
    //cout << "__ finding path __" << endl;

    // initialise start record
    NodeRecord startRecord;
    startRecord.node = start;
    startRecord.parentNode = start;
    startRecord.costSoFar = 0;

    Node startNode = graph.getNode(start);
    Node goalNode = graph.getNode(goal);

    startRecord.heuristic = heuristicEuclidean(startNode.x_pos,startNode.y_pos,goalNode.x_pos,goalNode.y_pos);
    startRecord.estimatedTotalCost = startRecord.heuristic;

    // initialise open and closed lists
    multiset<NodeRecord, NodeRecordCompare> openList;
    openList.insert(startRecord);

    multiset<NodeRecord, NodeRecordCompare> closedList;

    multiset<NodeRecord, NodeRecordCompare>::iterator current;

    // iterate through processing each node
    //cout << "in while " << endl;
    while (openList.size() > 0)
    {
        // find smallest element in openlist using estimated total cost
        current = openList.begin();

        // if goal node reached terminate
        if ((*current).node == goal)
        {
            //cout << "goal reached - breaking out" << endl;
            break;
        }

        Node currentConnections = graph.getNode((*current).node);

        // expanding the connections from the current node
        // loop through each connection in turn
        for(int i = 0; i < currentConnections.size; i++)
        {
            if(currentConnections.connections[i].getValid())
            {
                // get destination node of the connection
                int endNodeRef = currentConnections.connections[i].getToNode();
                // calculate cost -> costSoFar + cost to traverse connection
                float endNodeCostSoFar = (*current).costSoFar + currentConnections.connections[i].getCost();


                multiset<NodeRecord, NodeRecordCompare>::iterator iterOLEN = findNode(openList, endNodeRef);
                // if node is on the open list
                if(iterOLEN != openList.end())
                {
                    // if shorter route found
                    if((*iterOLEN).costSoFar > endNodeCostSoFar)
                    {
                        // update values
                        // inserting a new record forces the set to update order
                        // (*iterOLEN).parentNode = (*current).node; gives read only structure assignment error
                        NodeRecord newNode;
                        newNode.node = (*iterOLEN).node;
                        newNode.parentNode = (*current).node; // change parent to current node
                        newNode.costSoFar = endNodeCostSoFar; // change CSFar to new, smaller, value
                        newNode.heuristic = (*iterOLEN).heuristic;
                        newNode.estimatedTotalCost = newNode.costSoFar + newNode.heuristic;

                        // remove record from open list
                        openList.erase(iterOLEN);

                        // add new record
                        openList.insert(newNode);
                    }
                }
                else
                {
                    multiset<NodeRecord, NodeRecordCompare>::iterator iterEN = findNode(closedList, endNodeRef);
                    // if node is on the closed list
                    if(iterEN != closedList.end())
                    {
                        // if shorter route found
                        if((*iterEN).costSoFar > endNodeCostSoFar)
                        {
                            // update values
                            NodeRecord newNode;
                            newNode.node = (*iterEN).node;
                            newNode.parentNode = (*current).node; // change parent to current node
                            newNode.costSoFar = endNodeCostSoFar; // change CSFar to new, smaller, value
                            newNode.heuristic = (*iterEN).heuristic;
                            newNode.estimatedTotalCost = newNode.costSoFar + newNode.heuristic;

                            // add record to open list
                            openList.insert(newNode);

                            // remove record from closed list
                            closedList.erase(iterEN);
                        }
                    }
                    else // if node is neither on the OPEN or CLOSED list make record and add to open
                    {
                        //cout << "openlist add code" << endl;
                        Node endNode = graph.getNode(endNodeRef);
                        NodeRecord endNodeRecord;
                        endNodeRecord.node = endNodeRef;
                        endNodeRecord.parentNode = (*current).node;
                        endNodeRecord.costSoFar = endNodeCostSoFar;
                        endNodeRecord.heuristic = heuristicEuclidean(endNode.x_pos,endNode.y_pos,goalNode.x_pos,goalNode.y_pos);
                        endNodeRecord.estimatedTotalCost = endNodeRecord.costSoFar + endNodeRecord.heuristic;

                        openList.insert(endNodeRecord);
                    }
                }
            }
        }

        closedList.insert((*current));
        openList.erase(current);

        /*// debug output
            cout << endl << "current : " << (*current).node << endl;
            cout << "displaying openList" << endl;
            printList(openList);

            cout << "displaying closedList" << endl;
            printList(closedList);
        */

    }

    //cout << "out of while" << endl;

    // building the path
    Path path = Path();
    path.setStart(start);
    path.setEnd(goal);

    vector<Connection> reversePath;
    Connection conn = Connection((*openList.begin()).parentNode, (*openList.begin()).node,0);
    reversePath.push_back(conn);
    //path.addConnection(conn);

    int nextNode = conn.getFromNode();

    while(nextNode != start)
    {
        multiset<NodeRecord, NodeRecordCompare>::iterator iterNode = findNode(closedList, nextNode);
        conn = Connection((*iterNode).parentNode, (*iterNode).node,0);
        reversePath.push_back(conn);
        //path.addConnection(conn);
        nextNode = conn.getFromNode();
    }

    vector<Connection>::reverse_iterator revIter;
    for(revIter = reversePath.rbegin(); revIter != reversePath.rend(); revIter++)
    {
        path.addConnection(*revIter);
    }

    /*cout << "\n printing lists before passing" << endl;
    cout << "\n printing open list" << endl;
    printList(openList);
    cout << "\n printing closed list" << endl;
    printList(closedList);*/

    return path;
}

/*void PathFinding::copyList(multiset<NodeRecord, NodeRecordCompare> &inSet, multiset<NodeRecord, NodeRecordCompare> &outSet)
{
    multiset<NodeRecord, NodeRecordCompare>::iterator iter;
    for(iter = inSet.begin(); iter != inSet.end(); iter++)
    {
        outSet.insert((*iter));
    }
}*/

multiset<NodeRecord, NodeRecordCompare>::iterator PathFinding::findNode(multiset<NodeRecord, NodeRecordCompare> &set, int node)
{
    multiset<NodeRecord, NodeRecordCompare>::iterator iter;

    iter = set.begin();
    while(iter != set.end())
    {
        if((*iter).node == node)
        {
            break;
        }

        iter++;
    }

    return iter;
}

void PathFinding::printList(multiset<NodeRecord, NodeRecordCompare> list)
{
    multiset<NodeRecord, NodeRecordCompare>::iterator iter;

    for(iter = list.begin(); iter != list.end(); iter++)
    {
        cout << (*iter).node << " : P->" << (*iter).parentNode << " : CSF= " << (*iter).costSoFar << " : ETC= " << (*iter).estimatedTotalCost << endl;
    }
}
