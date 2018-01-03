#include "Camera.h"

Camera::Camera():
        box(Box(0,0,constants::CAMERA_WIDTH,constants::CAMERA_HEIGHT)),
        xVel(0),
        yVel(0)
{
    //Initialize the offsets
//    box.set_x(0);
//    box.set_y(0);
//    box.set_w(constants::CAMERA_WIDTH);
//    box.set_h(constants::CAMERA_HEIGHT);
//
//    //Initialize the velocity
//    xVel = 0;
//    yVel = 0;
}

void Camera::handle_input(SDL_Event &event)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= constants::CAMERA_VELOCITY; break;
            case SDLK_DOWN: yVel += constants::CAMERA_VELOCITY; break;
            case SDLK_LEFT: xVel -= constants::CAMERA_VELOCITY; break;
            case SDLK_RIGHT: xVel += constants::CAMERA_VELOCITY; break;
            default: break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += constants::CAMERA_VELOCITY; break;
            case SDLK_DOWN: yVel -= constants::CAMERA_VELOCITY; break;
            case SDLK_LEFT: xVel += constants::CAMERA_VELOCITY; break;
            case SDLK_RIGHT: xVel -= constants::CAMERA_VELOCITY; break;
            default: break;
        }
    }
}

void Camera::move(Uint32 deltaTicks, int level_width, int level_height)
{
    Box oldPos = box;

    //Move the camera left or right
    //box.x += xVel*(deltaTicks / 1000.f);
    box.set_x(box.get_x() + xVel*(deltaTicks / 1000.f));

    //If the camera went too far to the left or right or touched a wall
    //if( ( box.x < 0 ) || ( box.x + box.w > level_width))
    if( ( box.get_x() < 0 ) || ( box.get_x() + box.get_w() > level_width))
    {
        //move back
        //box.x = oldPos.x;
        box.set_x(oldPos.get_x());
    }

    //Move the camera up or down
    //box.y += yVel*(deltaTicks / 1000.f);
     box.set_y(box.get_y() + yVel*(deltaTicks / 1000.f));

    //If the camera went too far up or down or touched a wall
    //if( ( box.y < 0 ) || ( box.y + box.h > level_height))
    if( ( box.get_y() < 0 ) || ( box.get_y() + box.get_h() > level_height))
    {
        //move back
        //box.y = oldPos.y;
        box.set_y(oldPos.get_y());
    }
}

