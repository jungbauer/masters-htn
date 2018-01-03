#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Utils/Constants.h"
#include "Utils/VecXY_Float.h"
#include "Utils/Utils.h"
#include "Utils/log.h"

#include "Tile.h"
#include "Utils/Coord.h"

struct CorridorNodes{
    int id;
    Coord pos; // pixel pos
    std::vector<int> connectedNodes;
};

class Level
{
    public:
        Level();
        Level(std::string map_name);
        //~Level();

        int get_width_in_tiles_();
        int get_height_in_tiles_();
        int get_width_in_pixels_();
        int get_height_in_pixels_();

        int get_total_tiles();
        bool get_tile(int pos, Tile& tile);
        bool get_tile(int x_pos, int y_pos, Tile& tile);
        bool CheckPathAtGrid(int x_grid, int y_grid);
        bool CheckPathAtGridAndGet(int x_grid, int y_grid, Tile& tile);

        bool getPositionFromGrid(int x_pos, int y_pos, int& tile_pos);
        bool getPixelPositionFromGrid(int grid_x, int grid_y, int& pixel_x, int& pixel_y);
        bool getGridPositionFromPixels(int pixel_x, int pixel_y, int& grid_x, int& grid_y);
        bool getPathRefFromPixels(int pixel_x, int pixel_y, int& path_ref);

        std::vector<int> collidables_;  // Index to colliable tiles.

        bool levelCollisionCheck_Circle(VecXY_Float& pos, float radius);
        bool levelCollisionCheck_Circle(VecXY_Float pos, float radius, VecXY_Float &object);
        bool walkable(VecXY_Float check_point, VecXY_Float current_point);

        std::vector<Tile> tiles_;   // The tiles of the level.

        VecXY_Float team1_spawn;
        float team1_orientation;
        VecXY_Float team2_spawn;
        float team2_orientation;
        std::vector<CorridorNodes> corridors;

    private:
        bool load_map(std::string map_name);    // Load map from file.
        void set_pathfinding_values(Tile &tile, int &path_ref);
        void makeCorridors(std::string map);

        int width_in_tiles_;
        int height_in_tiles_;

        int width_in_pixels_;
        int height_in_pixels_;
};

#endif

