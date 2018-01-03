#include "Box.h"

Box::Box(int x, int y, int w, int h) : Quad(x,y,w,h)
{}

Box::Box() : Quad()
{}

int Box::get_x()
{
    return getW();
}

void Box::set_x(int x)
{
    setW(x);
}

int Box::get_y()
{
    return getX();
}

void Box::set_y(int y)
{
    setX(y);
}

int Box::get_w()
{
    return getY();
}

void Box::set_w(int w)
{
    setY(w);
}

int Box::get_h()
{
    return getZ();
}

void Box::set_h(int h)
{
    setZ(h);
}
