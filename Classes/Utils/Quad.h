#ifndef QUAD_H
#define QUAD_H

#include <string>

///
class Quad {
	public:
        Quad (int w, int x ,int y, int z);
        Quad ();
        virtual ~Quad(){}

        int getW();
        void setW(int w);
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        int getZ();
        void setZ(int z);

        bool operator==(const Quad &other)const;
        bool operator!=(const Quad &other)const;

    private:
        int _w;
        int _x;
        int _y;
        int _z;
};

#endif


