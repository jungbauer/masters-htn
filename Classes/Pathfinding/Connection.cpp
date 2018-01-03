#include "Connection.h"

/// Class Constructor
Connection::Connection (int from ,int to, float cost):
        _fromNode(from),
        _toNode(to),
        _cost(cost),
        _valid(true)
{
//    _valid = true;
}

/// Class Constructor, so that is can be in an array
Connection::Connection ():
        _fromNode(-1),
        _toNode(-1),
        _cost(999999),
        _valid(false)
{
//    _valid = false;
}

/// returns connection cost
float Connection::getCost()
{
    return _cost;
}

/// returns connection start node
int Connection::getFromNode()
{
    return _fromNode;
}

/// returns connection end node
int Connection::getToNode()
{
    return _toNode;
}

/// sets whether the connection is a valid one
void Connection::setValid(bool val)
{
    _valid = val;
}

/// returns the validity of a connection
bool Connection::getValid()
{
    return _valid;
}

std::string Connection::get_Str()
{
    std::string con = utils::intToString(_fromNode) + " " + utils::intToString(_toNode) + " " + utils::floatToString(_cost)  + " " + utils::boolToString(_valid);
    return con;
}
