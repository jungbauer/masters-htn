#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "VecXY_Float.h"
#include "Constants.h"
#include "Box.h"

namespace utils
{
    bool check_collision(Box A, Box B);
    bool check_collision(Box A, float radius, VecXY_Float circle_pos);

    bool sphere_Sphere_SweepTest(float ra, VecXY_Float A0, VecXY_Float A1, float rb, VecXY_Float B0, VecXY_Float B1);
    bool QuadraticFormula(float a, float b, float c, float& r1, float& r2);

    std::string intToString(int in);
    std::string boolToString(bool in);
    std::string floatToString(float in);

    int getRandomInt(int lowest, int highest);

    void trimAngle(float& angle);
    float calculateAngle(VecXY_Float current, VecXY_Float target);

    bool check_Point_Within_Box(Box A, VecXY_Float point);
}

#endif
