#ifndef SURFACES_H
#define SURFACES_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "Constants.h"

//The surfaces
extern SDL_Surface *screen;
extern SDL_Surface *tileSheet;
extern SDL_Surface *mapView;
extern SDL_Surface *message;
extern SDL_Surface *influenceMini;

//Sprite from the tile sheet
extern SDL_Rect clips[constants::NUM_TILE_SPRITES];

extern TTF_Font *font;

namespace surfaces
{
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );
    void textToSurface(std::string msg, SDL_Color text_color, SDL_Surface* destination, int pos_x, int pos_y);
    SDL_Surface *load_image(std::string filename);
    void clip_tiles();
}

#endif
