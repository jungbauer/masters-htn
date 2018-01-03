#ifndef TILE_H
#define TILE_H

#include "Utils/Constants.h"
#include "Utils/Box.h"

//The tile
class Tile
{
    public:
        Tile();
        Tile( int x, int y, int tileType );

        int get_type();
        Box get_box();
        void GetGridPosition(int &x, int &y);
        void GetCentrePixels(int &x, int &y);

        //TODO (engineering#1#) These vars should be behind accessor methods
        int map_ref; // Position in the Tile array for easy reference
        int path_ref;    // Position in path array
        bool path_node;  // Whether tile is traversable
        float leave_cost;    // Pathfinding data
        float enter_cost;    // Pathfinding data

    private:
        int type;   // The tile type
        Box box;   //The attributes of the tile {x,y,w,h} & collision box
};

#endif
