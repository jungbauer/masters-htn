#include "Quad.h"

/// Class Constructor
Quad::Quad (int w, int x ,int y, int z):
        _w(w),
        _x(x),
        _y(y),
        _z(z)
{}

/// Class Constructor
Quad::Quad ():
        _w(-1),
        _x(-1),
        _y(-1),
        _z(-1)
{}

/// Get function for W.
int Quad::getW()
{
	return _w;
}

/// Set function for W.
void Quad::setW(int w)
{
	_w = w;
}

/// Get function for X.
int Quad::getX()
{
	return _x;
}

/// Set function for X.
void Quad::setX(int x)
{
	_x = x;
}

/// Get function for Y.
int Quad::getY()
{
	return _y;
}

/// Set function for Y.
void Quad::setY(int y)
{
	_y = y;
}

/// Get function for Z.
int Quad::getZ()
{
	return _z;
}

/// Set function for Y.
void Quad::setZ(int z)
{
	_z = z;
}

/// equality operator
bool Quad::operator==(const Quad &other) const
{
    bool equal = false;

    if((this->_w == other._w) && (this->_x == other._x) && (this->_y == other._y) && (this->_z == other._z))
    {
        equal = true;
    }

    return equal;
}

bool Quad::operator!=(const Quad &other) const
{
    return !(*this == other);
}
