#include "Surfaces.h"

//The surfaces
SDL_Surface *screen = NULL;
SDL_Surface *tileSheet = NULL;
SDL_Surface *mapView = NULL;
SDL_Surface *message = NULL;
SDL_Surface *influenceMini = NULL;

//Sprite from the tile sheet
SDL_Rect clips[constants::NUM_TILE_SPRITES];

TTF_Font *font = NULL;

namespace surfaces
{
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
    {
        //Holds offsets
        SDL_Rect offset;

        //Get offsets
        offset.x = x;
        offset.y = y;

        //Blit
        SDL_BlitSurface( source, clip, destination, &offset );
    }

    void textToSurface(std::string msg, SDL_Color text_color, SDL_Surface* destination, int pos_x, int pos_y)
    {
        SDL_FreeSurface(message); //http://stackoverflow.com/questions/11232926/sdl-c-ttf-randomly-disappears-after-a-while-and-doesnt-come-back
        message = TTF_RenderText_Solid(font, msg.c_str(), text_color);
        apply_surface(pos_x, pos_y, message, destination);
    }

    SDL_Surface *load_image(std::string filename)
    {
        //The image that's loaded
        SDL_Surface* loadedImage = NULL;

        //The optimized surface that will be used
        SDL_Surface* optimizedImage = NULL;

        //Load the image
        loadedImage = IMG_Load( filename.c_str() );

        //If the image loaded
        if( loadedImage != NULL )
        {
            //Create an optimized surface
            optimizedImage = SDL_DisplayFormat( loadedImage );

            //Free the old surface
            SDL_FreeSurface( loadedImage );

            //If the surface was optimized
            if( optimizedImage != NULL )
            {
                //Color key surface
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
            }
        }

        //Return the optimized surface
        return optimizedImage;
    }

    void clip_tiles()
    {
        //Clip the sprite sheet
        clips[constants::ENUM_BLANK ].x = 0;
        clips[constants::ENUM_BLANK].y = 0;
        clips[constants::ENUM_BLANK].w = constants::TILE_WIDTH;
        clips[constants::ENUM_BLANK].h = constants::TILE_HEIGHT;

        clips[constants::ENUM_GRASS].x = 0;
        clips[constants::ENUM_GRASS].y = 40;
        clips[constants::ENUM_GRASS].w = constants::TILE_WIDTH;
        clips[constants::ENUM_GRASS].h = constants::TILE_HEIGHT;

        clips[constants::ENUM_PATH].x = 0;
        clips[constants::ENUM_PATH].y = 80;
        clips[constants::ENUM_PATH].w = constants::TILE_WIDTH;
        clips[constants::ENUM_PATH].h = constants::TILE_HEIGHT;

        clips[constants::ENUM_HIGH_WALL].x = 0;
        clips[constants::ENUM_HIGH_WALL].y = 120;
        clips[constants::ENUM_HIGH_WALL].w = constants::TILE_WIDTH;
        clips[constants::ENUM_HIGH_WALL].h = constants::TILE_HEIGHT;

        clips[constants::ENUM_LOW_WALL].x = 0;
        clips[constants::ENUM_LOW_WALL].y = 160;
        clips[constants::ENUM_LOW_WALL].w = constants::TILE_WIDTH;
        clips[constants::ENUM_LOW_WALL].h = constants::TILE_HEIGHT;
    }
}
