#include "Coord.h"

/// Class Constructor
Coord::Coord (int x ,int y):
        _x(x),
        _y(y)
{}

/// Class Constructor
Coord::Coord ():
    _x(0),
    _y(0)
{}

/// Get function for X.
int Coord::getX()
{
	return _x;
}

/// Set function for X.
void Coord::setX(int x)
{
	_x = x;
}

/// Get function for Y.
int Coord::getY()
{
	return _y;
}

/// Set function for Y.
void Coord::setY(int y)
{
	_y = y;
}

/// equality operator
bool Coord::operator==(const Coord &other) const
{
    bool equal = false;

    if((this->_x == other._x) && (this->_y == other._y))
    {
        equal = true;
    }

    return equal;
}

bool Coord::operator!=(const Coord &other) const
{
    return !(*this == other);
}

Coord Coord::operator+(const Coord &other)const
{
    Coord ans = Coord(this->_x + other._x, this->_y + other._y);
    return ans;
}

Coord Coord::operator-(const Coord &other)const
{
    Coord ans = Coord(this->_x - other._x, this->_y - other._y);
    return ans;
}

Coord Coord::operator/(const int &other)const
{
    Coord ans = Coord(this->_x / other, this->_y / other);
    return ans;
}

Coord Coord::operator*(const int &other)const
{
    Coord ans = Coord(this->_x * other, this->_y * other);
    return ans;
}

/*std::string Coord::print()
{
    Common common;
    std::string out = "[";
    out.append(common.intToString(_x));
    out.append(",");
    out.append(common.intToString(_y));
    out.append("]");
    return out;
}*/
