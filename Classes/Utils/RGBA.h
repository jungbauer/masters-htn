#ifndef RGBA_H
#define RGBA_H

#include "Quad.h"

///

class RGBA : public Quad {
	public:
        RGBA(int red, int green, int blue, int alpha);
        RGBA();

        int getRed();
        void setRed(int red);
        int getGreen();
        void setGreen(int green);
        int getBlue();
        void setBlue(int blue);
        int getAlpha();
        void setAlpha(int alpha);

    private:

};

#endif
