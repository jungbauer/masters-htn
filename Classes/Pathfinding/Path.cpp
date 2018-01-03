#include "Path.h"

Path::Path():
        _startNode(-1),
        _endNode(-1),
        _position(0),
        path_complete(false),
        start_coord(),
        end_coord()
{
//    _position = 0;
//    path_complete = false;
}

//Path::Path(multiset<NodeRecord, NodeRecordCompare> oList, multiset<NodeRecord, NodeRecordCompare> cList)
//{
//    _position = 0;
//    path_complete = false;
//    openList = oList;
//    closedList = cList;
//}

void Path::setStart(int start)
{
    _startNode = start;
}

int Path::getStart()
{
    return _startNode;
}

void Path::setEnd(int end)
{
    _endNode = end;
}

int Path::getEnd()
{
    return _endNode;
}

bool Path::addConnection(Connection conn)
{
    _path.push_back(conn);

    return true;
}

void Path::getPath(std::vector<Connection> &outPath)
{
    outPath = _path;
}

bool Path::progressPosition(Coord &nextC)
{
    bool path_progressed = false;
    if(_position < _culled_path.size() - 1)
    {
        _position++;
        nextC = _culled_path[_position];
        path_progressed = true;
    }
    else
    {
        path_complete = true;
    }

    return path_progressed;
}

//bool Path::dummy_progressPosition()
//{
//    bool path_progressed = false;
//    if(_position < _culled_path.size() - 1)
//    {
//        _position++;
//        path_progressed = true;
//    }
//
//    return path_progressed;
//}

Coord Path::get_End_Coord()
{
    return _culled_path[_culled_path.size() - 1];
}

void Path::setStartCoord(int x, int y)
{
    start_coord = Coord(x,y);
}

void Path::setEndCoord(int x, int y)
{
    end_coord = Coord(x, y);
}

VecXY_Float Path::get_End_Vec()
{
    VecXY_Float vec = VecXY_Float((float) _culled_path[_culled_path.size() - 1].getX(), (float)_culled_path[_culled_path.size() - 1].getY());
    return vec;
}

bool Path::complete_Check()
{
    return path_complete;
}

Coord Path::getCurrentCheckPoint()
{
    return _culled_path[_position];
}

int Path::getPathSize()
{
    return _culled_path.size();
}

void Path::cullPath(Graph &graph, Level &level)
{
//    LOG(FILE_LOG(logDEBUG) << "Path::cullPath() - > start";);
//    LOG(FILE_LOG(logDEBUG2) << _path.size() << " -- " << _path.capacity(););
//    for(unsigned int p = 0; p < _path.size(); p++)
//    {
//        LOG(FILE_LOG(logDEBUG) << _path[p].get_Str(););
//    }

    std::vector<Coord> temp_path; //TODO (imp#3#) Set reserves for these vectors.
    std::vector<Coord> temp_path2;
    std::vector<float> angles;
    std::vector<bool> adds;
    int x = 0, y =0;

    // Conversion from Connection vector to Coord vector. ----------------------------------------------
    temp_path.push_back(start_coord);

    for(unsigned int c =0; c < _path.size(); c++)
    {
        Node from_node = graph.getNode(_path[c].getFromNode());
        Tile from_tile;
        if(level.get_tile(from_node.x_pos, from_node.y_pos, from_tile) == true)
        {
            from_tile.GetCentrePixels(x,y);
            temp_path.push_back(Coord(x,y));
        }
    }
    Node last_node = graph.getNode(_path[_path.size()-1].getToNode());
    Tile last_tile;
    if(level.get_tile(last_node.x_pos, last_node.y_pos, last_tile) == true)
    {
        last_tile.GetCentrePixels(x,y);
        temp_path.push_back(Coord(x,y));
    }

    temp_path.push_back(end_coord); // Useful if the end coord is not actually a perfect grid position.

    // Trimming temp path via angles. ------------------------------------------------------------------
    // The angles vector will be 1 smaller than temp coz we make it ignore the last temp position.
    // We dont want that position removed.
    for(unsigned int i = 0; i < temp_path.size()-1; i++)
    {
        float c_x=0,c_y=0,n_x=0,n_y=0, dx=0,dy=0;
        c_x = (float) temp_path[i].getX();
        c_y = (float) temp_path[i].getY();
        n_x = (float) temp_path[i+1].getX();
        n_y = (float) temp_path[i+1].getY();

        dx = c_x - n_x;
        dy = c_y - n_y;

        if(dx == 0)
        {dx = 0.1;}

        if(dy == 0)
        {dy = 0.1;}

        angles.push_back(atan2(dy,dx));
    }


    adds.push_back(true); // Always want the first path pos.
    for(unsigned int i = 1; i < angles.size(); i++)
    {
        if(angles[i] == angles[i-1])
        {
            adds.push_back(false);
        }
        else
        {
            adds.push_back(true);
        }
    }
    adds.push_back(true);  // Always want the last path pos.

    for(unsigned int i = 0; i < adds.size(); i++)
    {
        if(adds[i] == true)
        {
            temp_path2.push_back(temp_path[i]);
        }
    }


    // Use Level.walkable() to further smooth the path. ----------------------------------------------------
    //    LOG(FILE_LOG(logDEBUG2) << "Walkable checks";);
//    LOG(FILE_LOG(logDEBUG3) << "Temp path size: " << temp_path.size(););
    // http://www.gamasutra.com/view/feature/131505/toward_more_realistic_pathfinding.php?page=2 ---- With edits to make it work!
    vector<Coord>::iterator iterCoord;
    iterCoord = temp_path2.begin();

    Coord check_point = (*iterCoord);
//    LOG(FILE_LOG(logDEBUG2) << "initial point placement";);
    _culled_path.push_back(check_point);
    Coord current_point;
    iterCoord++;

    while(iterCoord != temp_path2.end())
    {
//        LOG(FILE_LOG(logDEBUG2) << "set current point";);
        current_point = (*iterCoord);

//        LOG(FILE_LOG(logDEBUG2) << "level.walkabe()";);
        if(level.walkable(VecXY_Float((float)check_point.getX(), (float) check_point.getY()), VecXY_Float((float)current_point.getX(), (float)current_point.getY())))
        {
//            LOG(FILE_LOG(logDEBUG2) << "walkable TRUE";);
            iterCoord++;
        }
        else
        {
//            LOG(FILE_LOG(logDEBUG2) << "walkable FALSE";);
            iterCoord--;
            _culled_path.push_back((*iterCoord));
            check_point = (*iterCoord);
            iterCoord++;
        }
    }
//    LOG(FILE_LOG(logDEBUG2) << "Place last point";);
    _culled_path.push_back(temp_path2[temp_path2.size()-1]);

//    LOG(FILE_LOG(logDEBUG) << "Path::cullPath() - > end";);
}
