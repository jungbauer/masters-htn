#ifndef CAMERA_H
#define CAMERA_H

#include <SDL/SDL.h>

#include "Utils/Constants.h"
#include "Utils/Box.h"

class Camera
{
    public:
        Camera();
        Box box;

        //Takes key presses and adjusts the dot's velocity
        void handle_input(SDL_Event &event);
        void move(Uint32 deltaTicks, int level_width, int level_height);

    private:
        //The velocity of the dot
        float xVel, yVel;
};

#endif

