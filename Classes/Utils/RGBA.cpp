#include "RGBA.h"

RGBA::RGBA(int red, int green, int blue, int alpha) : Quad(red, green, blue, alpha)
{}

RGBA::RGBA() : Quad()
{}

int RGBA::getRed()
{
    return getW();
}

void RGBA::setRed(int red)
{
    setW(red);
}

int RGBA::getGreen()
{
    return getX();
}

void RGBA::setGreen(int green)
{
    setX(green);
}

int RGBA::getBlue()
{
    return getY();
}

void RGBA::setBlue(int blue)
{
    setY(blue);
}

int RGBA::getAlpha()
{
    return getZ();
}

void RGBA::setAlpha(int alpha)
{
    setZ(alpha);
}
