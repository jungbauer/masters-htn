#ifndef BOX_H
#define BOX_H

#include "Quad.h"

class Box : private Quad {
	public:
        Box(int x, int y, int w, int h);
        Box();

        int get_x();
        void set_x(int x);
        int get_y();
        void set_y(int y);
        int get_w();
        void set_w(int w);
        int get_h();
        void set_h(int h);

    private:

};

#endif


