#include "Graph.h"

/// Class Constructor
Graph::Graph ()
{}

//void Graph::addNode(Node n)
//{
//    nodes_.push_back(n);
//}

Node Graph::getNode(int fromNode)
{
    if((fromNode >= (int)nodes_.size()) || (fromNode < 0)) //TODO (fix#3#) Figure out a way of handling this better.
    {
        LOG(FILE_LOG(logERROR) << "Graph::getNode() invalid node: " << fromNode;);
        return nodes_[0];
    }
    else
    {
        return nodes_[fromNode];
    }
}

int Graph::getSize()
{
    return nodes_.size();
}

/// generates a graph from the Map_Data array
void Graph::generateGraph(Level &level)
{
    int node_count = 0;

    for(int t = 0; t < level.get_total_tiles(); t++)
    {
        // get level tile
        Tile curr_tile;
        if(level.get_tile(t,curr_tile) == true)
        {
            // if tile is a valid path node
            if(curr_tile.path_node == true)
            {
                // create graph node
                Node curr_node;

                curr_node.graph_pos = node_count;
                // checks in this function use grid position references not pixel positions.
                curr_tile.GetGridPosition(curr_node.x_pos,curr_node.y_pos);

                /// setup connections---------------------------------------------
                Tile next_tile;
                //check if north connection exists 0
                // ie if there is a block and is it a path node
                if(level.CheckPathAtGridAndGet(curr_node.x_pos, curr_node.y_pos - 1, next_tile))
                {
                    Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.0);
                    curr_node.connections[0] = conn;
                }
                //check if north east connection exists 1
                // we don't want the AI cutting corners
                if(level.CheckPathAtGridAndGet(curr_node.x_pos + 1, curr_node.y_pos - 1, next_tile))
                {
                    // check north connection for valid diagonal
                    if(level.CheckPathAtGrid(curr_node.x_pos, curr_node.y_pos - 1))
                    {
                        // check east connection for valid diagonal
                        if(level.CheckPathAtGrid(curr_node.x_pos + 1, curr_node.y_pos))
                        {
                            Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.4);
                            curr_node.connections[1] = conn;
                        }
                    }
                }

                //check if east connection exists 2
                if(level.CheckPathAtGridAndGet(curr_node.x_pos + 1, curr_node.y_pos, next_tile))
                {
                    Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.0);
                    curr_node.connections[2] = conn;
                }

                //check if south east connection exists 3
                if(level.CheckPathAtGridAndGet(curr_node.x_pos + 1, curr_node.y_pos + 1, next_tile))
                {
                     // check south connection for valid diagonal
                    if(level.CheckPathAtGrid(curr_node.x_pos, curr_node.y_pos + 1))
                    {
                        // check east connection for valid diagonal
                        if(level.CheckPathAtGrid(curr_node.x_pos + 1, curr_node.y_pos))
                        {
                            Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.4);
                            curr_node.connections[3] = conn;
                        }
                    }
                }

                // check if south connection exists 4
                if(level.CheckPathAtGridAndGet(curr_node.x_pos, curr_node.y_pos + 1, next_tile))
                {
                    Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.0);
                    curr_node.connections[4] = conn;
                }

                //check if south west connection exists 5
                if(level.CheckPathAtGridAndGet(curr_node.x_pos - 1, curr_node.y_pos + 1, next_tile))
                {
                     // check south connection for valid diagonal
                    if(level.CheckPathAtGrid(curr_node.x_pos, curr_node.y_pos + 1))
                    {
                        // check west connection for valid diagonal
                        if(level.CheckPathAtGrid(curr_node.x_pos - 1, curr_node.y_pos))
                        {
                            Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.4);
                            curr_node.connections[5] = conn;
                        }
                    }
                }

                // check if west connection exists 6
                if(level.CheckPathAtGridAndGet(curr_node.x_pos - 1, curr_node.y_pos, next_tile))
                {
                    Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.0);
                    curr_node.connections[6] = conn;
                }

                //check if north west connection exists 7
                if(level.CheckPathAtGridAndGet(curr_node.x_pos - 1, curr_node.y_pos - 1, next_tile))
                {
                    // check north connection for valid diagonal
                    if(level.CheckPathAtGrid(curr_node.x_pos, curr_node.y_pos - 1))
                    {
                        // check west connection for valid diagonal
                        if(level.CheckPathAtGrid(curr_node.x_pos - 1, curr_node.y_pos))
                        {
                            Connection conn = Connection(curr_node.graph_pos, next_tile.path_ref, curr_tile.leave_cost + next_tile.enter_cost + 1.4);
                            curr_node.connections[7] = conn;
                        }
                    }
                }


                // add node to graph
//                addNode(curr_node);
                nodes_.push_back(curr_node);
                node_count++;
            }
        }
    }

    // Shrinking graph size.
     std::vector<Node>(nodes_.begin(),nodes_.end()).swap(nodes_);
}
