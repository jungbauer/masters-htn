#ifndef COORD_H
#define COORD_H

#include <string>

//#include "Common.h"

/// Coord Class, basic coordonate container with an X and Y component
class Coord {
	public:
        Coord (int x ,int y);
        Coord ();

        int getX();
        void setX(int x);
        int getY();
        void setY(int y);

        bool operator==(const Coord &other)const;
        bool operator!=(const Coord &other)const;
        Coord operator+(const Coord &other)const;
        Coord operator-(const Coord &other)const;
        Coord operator/(const int &other)const;
        Coord operator*(const int &other)const;

        //std::string print();

    private:
        int _x;
        int _y;
};

#endif
