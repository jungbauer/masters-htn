#include "VecXY_Float.h"

/// Class Constructor
VecXY_Float::VecXY_Float (float x ,float y):
        _x(x),
        _y(y)
{}

/// Class Constructor
VecXY_Float::VecXY_Float ():
        _x(0.0),
        _y(0.0)
{}

/// Get function for X.
float VecXY_Float::getX()
{
	return _x;
}

/// Set function for X.
void VecXY_Float::setX(float x)
{
	_x = x;
}

/// Get function for Y.
float VecXY_Float::getY()
{
	return _y;
}

/// Set function for Y.
void VecXY_Float::setY(float y)
{
	_y = y;
}

/// equality operator
bool VecXY_Float::operator==(const VecXY_Float &other) const
{
    bool equal = false;

    if((this->_x == other._x) && (this->_y == other._y))
    {
        equal = true;
    }

    return equal;
}

bool VecXY_Float::operator!=(const VecXY_Float &other) const
{
    return !(*this == other);
}

VecXY_Float VecXY_Float::operator+(const VecXY_Float &other)const
{
    VecXY_Float ans = VecXY_Float(this->_x + other._x, this->_y + other._y);
    return ans;
}

VecXY_Float VecXY_Float::operator-(const VecXY_Float &other)const
{
    VecXY_Float ans = VecXY_Float(this->_x - other._x, this->_y - other._y);
    return ans;
}

VecXY_Float VecXY_Float::operator/(const float &other)const
{
    VecXY_Float ans = VecXY_Float(this->_x / other, this->_y / other);
    return ans;
}

VecXY_Float VecXY_Float::operator*(const float &other)const
{
    VecXY_Float ans = VecXY_Float(this->_x * other, this->_y * other);
    return ans;
}

VecXY_Float VecXY_Float::normalize()
{
    float mag = std::abs(sqrt((_x*_x)+(_y*_y)));

    return ((*this)/mag);
}

float VecXY_Float::length()
{
    float mag = std::abs(sqrt((_x*_x)+(_y*_y)));
    return mag;
}

