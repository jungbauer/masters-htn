#ifndef VECXY_FLOAT_H
#define VECXY_FLOAT_H

#include <cmath>

class VecXY_Float {
	public:
        VecXY_Float (float x ,float y);
        VecXY_Float ();

        float getX();
        void setX(float x);
        float getY();
        void setY(float y);

        VecXY_Float normalize();
        float length();

        bool operator==(const VecXY_Float &other)const;
        bool operator!=(const VecXY_Float &other)const;
        VecXY_Float operator+(const VecXY_Float &other)const;
        VecXY_Float operator-(const VecXY_Float &other)const;
        VecXY_Float operator/(const float &other)const;
        VecXY_Float operator*(const float &other)const;

    private:
        float _x;
        float _y;
};

#endif

