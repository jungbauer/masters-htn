#include "Level.h"

Level::Level():
        width_in_tiles_(1),
        height_in_tiles_(1),
        width_in_pixels_(1),
        height_in_pixels_(1)
{
    //std::cerr << "Level constructor 0" << std::endl;
}

Level::Level(std::string map_name):
        width_in_tiles_(1),
        height_in_tiles_(1),
        width_in_pixels_(1),
        height_in_pixels_(1)
{
    //std::cerr << "Level constructor 1" << std::endl;
    load_map(map_name);

    // Shrinking the collidables vector capacity since this should not change later.
    std::vector<int>(collidables_.begin(),collidables_.end()).swap(collidables_);

    makeCorridors(map_name);
}

//Level::~Level()
//{
//    std::cerr << "Level destrutor!!!!" << std::endl;
//}

bool Level::load_map(std::string map_name)
{
    //The tile offsets
    int x = 0, y = 0, path_nodes = 0;
    float pos_x = 0, pos_y = 0;

    std::ifstream map(map_name.c_str());
//    if( map == NULL )
    if( map.fail() )
    {
        return false;
    }

    map >> width_in_tiles_;
    map >> height_in_tiles_;

    map >> pos_x;
    map >> pos_y;
    team1_spawn = VecXY_Float(pos_x, pos_y);
    map >> team1_orientation;

    map >> pos_x;
    map >> pos_y;
    team2_spawn = VecXY_Float(pos_x, pos_y);
    map >> team2_orientation;

    width_in_pixels_ = width_in_tiles_ * constants::TILE_WIDTH;
    height_in_pixels_ = height_in_tiles_ * constants::TILE_HEIGHT;

    // Minimising the allocations and size changes since already know the needed size.
    tiles_.reserve((width_in_tiles_*height_in_tiles_)+1);

    for( int t = 0; t < get_total_tiles(); t++)
    {
        //Determines what kind of tile will be made
        int tileType = -1;

        //Read tile from map file
        map >> tileType;

        //If the was a problem in reading the map
        if( map.fail() == true )
        {
            //Stop loading map
            map.close();
            return false;
        }

        //If the number is a valid tile number
        if((tileType >= 0) && (tileType < constants::NUM_TILE_SPRITES))
        {
            Tile curr_tile = Tile(x, y, tileType);
            curr_tile.map_ref = t;
            set_pathfinding_values(curr_tile, path_nodes);

            // if tile is a collidable add to collidables vector
            if((curr_tile.get_type() == constants::ENUM_HIGH_WALL) || (curr_tile.get_type() == constants::ENUM_LOW_WALL))
            {
                collidables_.push_back(tiles_.size());
            }

            tiles_.push_back(curr_tile);
        }
        //If we don't recognize the tile type
        else
        {
            //Stop loading map
            map.close();
            return false;
        }

        //Move to next tile spot
        x += constants::TILE_WIDTH;

        //If we've gone too far
        if( x >= width_in_pixels_ )
        {
            //Move back
            x = 0;

            //Move to the next row
            y += constants::TILE_HEIGHT;
        }
    }

    //Close the file
    map.close();

    //If the map was loaded fine
    return true;
}

void Level::set_pathfinding_values(Tile &tile, int &path_ref)
{
    switch(tile.get_type())
    {
        case constants::ENUM_GRASS:
        {
            tile.path_node = true;
            tile.path_ref = path_ref;
            path_ref += 1;
            tile.leave_cost = 1.0;
            tile.enter_cost = 1.0;
        }
        break;

        case constants::ENUM_PATH:
        {
            tile.path_node = true;
            tile.path_ref = path_ref;
            path_ref += 1;
            tile.leave_cost = 0.50; // Cheaper to use the paths.
            tile.enter_cost = 0.50;
        }
        break;

        default:
            tile.path_node = false; // done just for safety's sake
            break;
    }
}

int Level::get_total_tiles()
{
    return width_in_tiles_ * height_in_tiles_;
}

int Level::get_width_in_tiles_()
{
    return width_in_tiles_;
}

int Level::get_height_in_tiles_()
{
    return height_in_tiles_;
}

int Level::get_width_in_pixels_()
{
    return width_in_pixels_;
}

int Level::get_height_in_pixels_()
{
    return height_in_pixels_;
}

bool Level::get_tile(int pos, Tile& tile)
{
    bool found = false;
    if((pos >= 0) && (pos < (int)tiles_.size()))
    {
        found = true;
        tile = tiles_[pos];
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Level::get_Tile() invalid pos: " << pos;);
    }

    return found;
}

bool Level::get_tile(int x_pos, int y_pos, Tile& tile)
{
    bool found = false;
    int tile_pos = -1;

    if(getPositionFromGrid(x_pos, y_pos, tile_pos) == true)
    {
        found = true;
        tile = tiles_[tile_pos];
    }

    return found;
}

bool Level::getPositionFromGrid(int x_pos, int y_pos, int& tile_pos)
{
    bool found = false;

    // check if within grid bounds
    if((x_pos >= 0) && (x_pos < width_in_tiles_) && (y_pos >= 0) && (y_pos < height_in_tiles_))
    {
        tile_pos = x_pos + (y_pos * width_in_tiles_);
        found = true;
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Level::getPositionFromGrid() outside bounds: " << x_pos << " - " << y_pos;);
    }

    return found;
}

bool Level::getPixelPositionFromGrid(int grid_x, int grid_y, int& pixel_x, int& pixel_y)
{
    bool found = false;
    int tile_pos = -1;

    // check if within grid bounds
    if((grid_x >= 0) && (grid_x < width_in_tiles_) && (grid_y >= 0) && (grid_y < height_in_tiles_))
    {
        tile_pos = grid_x + (grid_y * width_in_tiles_);
        tiles_[tile_pos].GetCentrePixels(pixel_x, pixel_y);
        found = true;
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Level::getPixelPositionFromGrid() outside bounds: " << grid_x << " - " << grid_y;);
    }

    return found;
}

bool Level::getGridPositionFromPixels(int pixel_x, int pixel_y, int& grid_x, int& grid_y)
{
    bool found = false;

    // check if within pixel bounds
    if((pixel_x >= 0) && (pixel_x < width_in_pixels_) && (pixel_y >= 0) && (pixel_y < height_in_pixels_))
    {
        grid_x = pixel_x / constants::TILE_WIDTH;
        grid_y = pixel_y / constants::TILE_HEIGHT;
        found = true;
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Level::getGridPositionFromPixels() outside bounds: " << pixel_x << " - " << pixel_y;);
    }

    return found;
}

bool Level::getPathRefFromPixels(int pixel_x, int pixel_y, int& path_ref)
{
    bool found = false;
    int grid_x = -1, grid_y = -1, pos = -1;

    if(getGridPositionFromPixels(pixel_x, pixel_y, grid_x, grid_y))
    {
        if(getPositionFromGrid(grid_x, grid_y, pos))
        {
            if(tiles_[pos].path_node == true)
            {
                found = true;
                path_ref = tiles_[pos].path_ref;
            }
        }
    }

    return found;
}

bool Level::CheckPathAtGridAndGet(int x_grid, int y_grid, Tile& tile)
{
    bool path = false;

    // check if in bounds
    if((x_grid >= 0) && (x_grid < width_in_tiles_) && (y_grid >= 0) && (y_grid < height_in_tiles_))
    {
        unsigned int pos = x_grid + (y_grid * width_in_tiles_);
        if(tiles_[pos].path_node == true)
        {
            path = true;
            tile = tiles_[pos];
        }
    }
    // This function is only ever called by Graph::GenerateGraph.
    // The out of bounds errors that were logged were part of checking for valid graph node connections.
//    else
//    {
//        LOG(FILE_LOG(logERROR) << "Level::CheckPathAtGridAndGet() outside bounds: " << x_grid << " - " << y_grid;);
//    }

    return path;
}

bool Level::CheckPathAtGrid(int x_grid, int y_grid)
{
    bool path = false;

    // check if in bounds
    if((x_grid >= 0) && (x_grid < width_in_tiles_) && (y_grid >= 0) && (y_grid < height_in_tiles_))
    {
        unsigned int pos = x_grid + (y_grid * width_in_tiles_);
        if(tiles_[pos].path_node == true)
        {
            path = true;
        }
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Level::CheckPathAtGrid() outside bounds: " << x_grid << " - " << y_grid;);
    }

    return path;
}

bool Level::levelCollisionCheck_Circle(VecXY_Float& pos, float radius)
{
//    LOG(FILE_LOG(logDEBUG2) << "Level::levelCollisionCheck_Circle() - start";);
    bool collision = false;

    // check level boundaries
    if(((int)pos.getX() < radius)
        || ((int)pos.getX() > (width_in_pixels_ - radius))
        || ((int)pos.getY() < radius)
        || ((int)pos.getY() > (height_in_pixels_ - radius)))
    {
//        LOG(FILE_LOG(logDEBUG3) << "Boundary collision";);
        collision = true;
    }
    else
    {
        // check collidable tiles
        for(unsigned int i = 0; i < collidables_.size(); i++)
        {
            Tile check_tile;
//            LOG(FILE_LOG(logDEBUG3) << "get tile";);
            get_tile(collidables_[i], check_tile);
//            LOG(FILE_LOG(logDEBUG3) << "utils collision check";);
            if(utils::check_collision(check_tile.get_box(), radius, pos) == true)
            {
                collision = true;
                break;
            }
        }
    }
//    LOG(FILE_LOG(logDEBUG2) << "Level::levelCollisionCheck_Circle() - start";);
    return collision;
}

bool Level::levelCollisionCheck_Circle(VecXY_Float pos, float radius, VecXY_Float &object)
{
    bool collision = false;
    int x = 0, y =0;

    // check level boundaries
    if(((int)pos.getX() < radius)
        || ((int)pos.getX() > (width_in_pixels_ - radius))
        || ((int)pos.getY() < radius)
        || ((int)pos.getY() > (height_in_pixels_ - radius)))
    {
        collision = true;
    }
    else
    {
        // check collidable tiles
        for(unsigned int i = 0; i < collidables_.size(); i++)
        {
            Tile check_tile;
            get_tile(collidables_[i], check_tile);
            if(utils::check_collision(check_tile.get_box(), radius, pos) == true)
            {
                check_tile.GetCentrePixels(x,y);
                object = VecXY_Float((float) x, (float) y);
                collision = true;
                break;
            }
        }
    }

    return collision;
}

bool Level::walkable(VecXY_Float check_point, VecXY_Float current_point)
{
//    LOG(FILE_LOG(logDEBUG3) << "Level::walkable() - > start";);
    float char_radius = 18.0; // Chars are 15 but I'm adding leeway.
    float step_dist = (char_radius-3) * 2; // So that step_dist is twice the actual radius of an agent.
    VecXY_Float check = check_point;
    VecXY_Float current = current_point;
    VecXY_Float diff = check - current;
    VecXY_Float step_vec = diff.normalize() * step_dist;

    float distance = diff.length();

    bool walkable_path = true;

//    std::cerr << std::endl << "check: " << check.getX() << "," << check.getY() << std::endl;
//    std::cerr << "current: " << current_point.getX() << "," << current_point.getY() << std::endl;
//    std::cerr << "diff: " << diff.getX() << "," << diff.getY() << "  " << distance << std::endl;
//    std::cerr << "step: " << step.getX() << "," << step.getY() << "  " << step.length() << std::endl;

    while((walkable_path == true) && (distance > step_dist))
    {
        check = check - step_vec;
//        std::cerr << "check: " << check.getX() << "," << check.getY() << std::endl;

//        LOG(FILE_LOG(logDEBUG3) << "level collision check " << "[" << check.getX() << "," << check.getY() << "]";);
        if(levelCollisionCheck_Circle(check, char_radius) == true)
        {
            walkable_path = false;
        }
        else
        {
            walkable_path = true;
        }

        if(distance > step_dist)
        {
            distance = distance - step_dist;
        }
        else
        {
            distance = -step_dist;
        }

//        std::cerr << "distance: " << distance << std::endl;
    }
//    LOG(FILE_LOG(logDEBUG3) << "Level::walkable() - > end";);
    return walkable_path;
}

void Level::makeCorridors(std::string map) {
    if(map.compare("Maps/small1.map") == 0) {
        // construct map1 corridors.
        CorridorNodes p0;
        CorridorNodes p1;
        CorridorNodes p2;
        CorridorNodes p3;
        CorridorNodes p4;
        CorridorNodes p5;
        CorridorNodes p6;
        CorridorNodes p7;
        CorridorNodes p8;
        CorridorNodes p9;
        CorridorNodes p10;
        CorridorNodes p11;
        CorridorNodes p12;
        CorridorNodes p13;
        CorridorNodes p14;
        CorridorNodes p15;
        CorridorNodes p16;
        CorridorNodes p17;
        CorridorNodes p18;
        CorridorNodes p19;

        p0.id = 0;
        p1.id = 1;
        p2.id = 2;
        p3.id = 3;
        p4.id = 4;
        p5.id = 5;
        p6.id = 6;
        p7.id = 7;
        p8.id = 8;
        p9.id = 9;
        p10.id = 10;
        p11.id = 11;
        p12.id = 12;
        p13.id = 13;
        p14.id = 14;
        p15.id = 15;
        p16.id = 16;
        p17.id = 17;
        p18.id = 18;
        p19.id = 19;

        p0.pos = Coord(1,1);
        p1.pos = Coord(1,6);
        p2.pos = Coord(3,10);
        p3.pos = Coord(3,14);
        p4.pos = Coord(5,1);
        p5.pos = Coord(5,5);
        p6.pos = Coord(8,7);
        p7.pos = Coord(8,11);
        p8.pos = Coord(9,1);
        p9.pos = Coord(12,3);
        p10.pos = Coord(12,12);
        p11.pos = Coord(15,14);
        p12.pos = Coord(16,4);
        p13.pos = Coord(16,8);
        p14.pos = Coord(19,10);
        p15.pos = Coord(19,14);
        p16.pos = Coord(21,1);
        p17.pos = Coord(21,5);
        p18.pos = Coord(23,9);
        p19.pos = Coord(23,14);

        p0.connectedNodes.push_back(1);
        p1.connectedNodes.push_back(0);
        p1.connectedNodes.push_back(5);
        p2.connectedNodes.push_back(6);
        p2.connectedNodes.push_back(3);
        p3.connectedNodes.push_back(2);
        p3.connectedNodes.push_back(11);
        p4.connectedNodes.push_back(5);
        p5.connectedNodes.push_back(1);
        p5.connectedNodes.push_back(4);
        p5.connectedNodes.push_back(6);
        p6.connectedNodes.push_back(5);
        p6.connectedNodes.push_back(2);
        p6.connectedNodes.push_back(7);
        p6.connectedNodes.push_back(8);
        p7.connectedNodes.push_back(6);
        p7.connectedNodes.push_back(10);
        p8.connectedNodes.push_back(6);
        p8.connectedNodes.push_back(16);
        p9.connectedNodes.push_back(10);
        p9.connectedNodes.push_back(12);
        p10.connectedNodes.push_back(7);
        p10.connectedNodes.push_back(9);
        p11.connectedNodes.push_back(3);
        p11.connectedNodes.push_back(13);
        p12.connectedNodes.push_back(9);
        p12.connectedNodes.push_back(13);
        p13.connectedNodes.push_back(11);
        p13.connectedNodes.push_back(12);
        p13.connectedNodes.push_back(14);
        p13.connectedNodes.push_back(17);
        p14.connectedNodes.push_back(13);
        p14.connectedNodes.push_back(15);
        p14.connectedNodes.push_back(18);
        p15.connectedNodes.push_back(14);
        p16.connectedNodes.push_back(8);
        p16.connectedNodes.push_back(17);
        p17.connectedNodes.push_back(13);
        p17.connectedNodes.push_back(16);
        p18.connectedNodes.push_back(14);
        p18.connectedNodes.push_back(19);
        p19.connectedNodes.push_back(18);

        corridors.push_back(p0);
        corridors.push_back(p1);
        corridors.push_back(p2);
        corridors.push_back(p3);
        corridors.push_back(p4);
        corridors.push_back(p5);
        corridors.push_back(p6);
        corridors.push_back(p7);
        corridors.push_back(p8);
        corridors.push_back(p9);
        corridors.push_back(p10);
        corridors.push_back(p11);
        corridors.push_back(p12);
        corridors.push_back(p13);
        corridors.push_back(p14);
        corridors.push_back(p15);
        corridors.push_back(p16);
        corridors.push_back(p17);
        corridors.push_back(p18);
        corridors.push_back(p19);

    }

    if(map == "Maps/small2.map") {
        // construct map1 corridors.
        CorridorNodes p0;
        CorridorNodes p1;
        CorridorNodes p2;
        CorridorNodes p3;
        CorridorNodes p4;
        CorridorNodes p5;
        CorridorNodes p6;
        CorridorNodes p7;
        CorridorNodes p8;
        CorridorNodes p9;
        CorridorNodes p10;
        CorridorNodes p11;
        CorridorNodes p12;
        CorridorNodes p13;
        CorridorNodes p14;
        CorridorNodes p15;
        CorridorNodes p16;
        CorridorNodes p17;

        p0.id = 0;
        p1.id = 1;
        p2.id = 2;
        p3.id = 3;
        p4.id = 4;
        p5.id = 5;
        p6.id = 6;
        p7.id = 7;
        p8.id = 8;
        p9.id = 9;
        p10.id = 10;
        p11.id = 11;
        p12.id = 12;
        p13.id = 13;
        p14.id = 14;
        p15.id = 15;
        p16.id = 16;
        p17.id = 17;

        p0.pos = Coord(1,1);
        p1.pos = Coord(1,7);
        p2.pos = Coord(1,14);
        p3.pos = Coord(4,8);
        p4.pos = Coord(8,2);
        p5.pos = Coord(8,13);
        p6.pos = Coord(10,4);
        p7.pos = Coord(10,11);
        p8.pos = Coord(12,7);
        p9.pos = Coord(12,8);
        p10.pos = Coord(14,4);
        p11.pos = Coord(14,11);
        p12.pos = Coord(16,2);
        p13.pos = Coord(16,13);
        p14.pos = Coord(20,7);
        p15.pos = Coord(23,1);
        p16.pos = Coord(23,8);
        p17.pos = Coord(23,14);

        p0.connectedNodes.push_back(1);
        p0.connectedNodes.push_back(4);
        p1.connectedNodes.push_back(0);
        p1.connectedNodes.push_back(2);
        p1.connectedNodes.push_back(3);

        p2.connectedNodes.push_back(1);
        p2.connectedNodes.push_back(5);

        p3.connectedNodes.push_back(1);

        p4.connectedNodes.push_back(0);
        p4.connectedNodes.push_back(5);
        p4.connectedNodes.push_back(6);

        p5.connectedNodes.push_back(2);
        p5.connectedNodes.push_back(4);
        p5.connectedNodes.push_back(7);

        p6.connectedNodes.push_back(4);
        p6.connectedNodes.push_back(8);

        p7.connectedNodes.push_back(5);
        p7.connectedNodes.push_back(9);

        p8.connectedNodes.push_back(6);
        p8.connectedNodes.push_back(9);
        p8.connectedNodes.push_back(10);

        p9.connectedNodes.push_back(7);
        p9.connectedNodes.push_back(8);
        p9.connectedNodes.push_back(11);

        p10.connectedNodes.push_back(8);
        p10.connectedNodes.push_back(12);

        p11.connectedNodes.push_back(9);
        p11.connectedNodes.push_back(13);

        p12.connectedNodes.push_back(10);
        p12.connectedNodes.push_back(13);
        p12.connectedNodes.push_back(15);

        p13.connectedNodes.push_back(11);
        p13.connectedNodes.push_back(12);
        p13.connectedNodes.push_back(17);

        p14.connectedNodes.push_back(16);

        p15.connectedNodes.push_back(12);
        p15.connectedNodes.push_back(16);

        p16.connectedNodes.push_back(14);
        p16.connectedNodes.push_back(15);
        p16.connectedNodes.push_back(17);

        p17.connectedNodes.push_back(13);
        p17.connectedNodes.push_back(16);


        corridors.push_back(p0);
        corridors.push_back(p1);
        corridors.push_back(p2);
        corridors.push_back(p3);
        corridors.push_back(p4);
        corridors.push_back(p5);
        corridors.push_back(p6);
        corridors.push_back(p7);
        corridors.push_back(p8);
        corridors.push_back(p9);
        corridors.push_back(p10);
        corridors.push_back(p11);
        corridors.push_back(p12);
        corridors.push_back(p13);
        corridors.push_back(p14);
        corridors.push_back(p15);
        corridors.push_back(p16);
        corridors.push_back(p17);
    }

    if(map == "Maps/small3.map") {
        // construct map1 corridors.
        CorridorNodes p0;
        CorridorNodes p1;
        CorridorNodes p2;
        CorridorNodes p3;
        CorridorNodes p4;
        CorridorNodes p5;
        CorridorNodes p6;
        CorridorNodes p7;
        CorridorNodes p8;
        CorridorNodes p9;
        CorridorNodes p10;
        CorridorNodes p11;
        CorridorNodes p12;
        CorridorNodes p13;
        CorridorNodes p14;
        CorridorNodes p15;
        CorridorNodes p16;
        CorridorNodes p17;
        CorridorNodes p18;
        CorridorNodes p19;
        CorridorNodes p20;
        CorridorNodes p21;
        CorridorNodes p22;
        CorridorNodes p23;
        CorridorNodes p24;
        CorridorNodes p25;
        CorridorNodes p26;
        CorridorNodes p27;

        p0.id = 0;
        p1.id = 1;
        p2.id = 2;
        p3.id = 3;
        p4.id = 4;
        p5.id = 5;
        p6.id = 6;
        p7.id = 7;
        p8.id = 8;
        p9.id = 9;
        p10.id = 10;
        p11.id = 11;
        p12.id = 12;
        p13.id = 13;
        p14.id = 14;
        p15.id = 15;
        p16.id = 16;
        p17.id = 17;
        p18.id = 18;
        p19.id = 19;
        p20.id = 20;
        p21.id = 21;
        p22.id = 22;
        p23.id = 23;
        p24.id = 24;
        p25.id = 25;
        p26.id = 26;
        p27.id = 27;

        p0.pos = Coord(1,1);
        p1.pos = Coord(1,3);
        p2.pos = Coord(1,7);
        p3.pos = Coord(1,10);
        p4.pos = Coord(1,14);
        p5.pos = Coord(4,3);
        p6.pos = Coord(6,8);
        p7.pos = Coord(6,11);
        p8.pos = Coord(8,1);
        p9.pos = Coord(8,5);
        p10.pos = Coord(10,4);
        p11.pos = Coord(10,8);
        p12.pos = Coord(10,11);
        p13.pos = Coord(12,1);
        p14.pos = Coord(12,14);
        p15.pos = Coord(14,4);
        p16.pos = Coord(14,7);
        p17.pos = Coord(14,11);
        p18.pos = Coord(16,10);
        p19.pos = Coord(16,14);
        p20.pos = Coord(18,4);
        p21.pos = Coord(18,7);
        p22.pos = Coord(20,12);
        p23.pos = Coord(23,1);
        p24.pos = Coord(23,5);
        p25.pos = Coord(23,8);
        p26.pos = Coord(23,12);
        p27.pos = Coord(23,14);

        p0.connectedNodes.push_back(1);
        p0.connectedNodes.push_back(8);

        p1.connectedNodes.push_back(0);
        p1.connectedNodes.push_back(2);
        p1.connectedNodes.push_back(5);

        p2.connectedNodes.push_back(1);

        p3.connectedNodes.push_back(4);
        p3.connectedNodes.push_back(7);

        p4.connectedNodes.push_back(3);
        p4.connectedNodes.push_back(14);

        p5.connectedNodes.push_back(1);
        p5.connectedNodes.push_back(6);

        p6.connectedNodes.push_back(5);
        p6.connectedNodes.push_back(7);
        p6.connectedNodes.push_back(9);
        p6.connectedNodes.push_back(11);

        p7.connectedNodes.push_back(3);
        p7.connectedNodes.push_back(6);

        p8.connectedNodes.push_back(0);

        p9.connectedNodes.push_back(6);
        p9.connectedNodes.push_back(10);

        p10.connectedNodes.push_back(9);
        p10.connectedNodes.push_back(13);

        p11.connectedNodes.push_back(6);

        p12.connectedNodes.push_back(14);

        p13.connectedNodes.push_back(10);
        p13.connectedNodes.push_back(15);

        p14.connectedNodes.push_back(12);
        p14.connectedNodes.push_back(17);

        p15.connectedNodes.push_back(13);

        p16.connectedNodes.push_back(21);

        p17.connectedNodes.push_back(14);
        p17.connectedNodes.push_back(18);

        p18.connectedNodes.push_back(17);
        p18.connectedNodes.push_back(21);

        p19.connectedNodes.push_back(27);

        p20.connectedNodes.push_back(21);
        p20.connectedNodes.push_back(24);

        p21.connectedNodes.push_back(16);
        p21.connectedNodes.push_back(18);
        p21.connectedNodes.push_back(20);
        p21.connectedNodes.push_back(22);

        p22.connectedNodes.push_back(21);
        p22.connectedNodes.push_back(26);

        p23.connectedNodes.push_back(13);
        p23.connectedNodes.push_back(24);

        p24.connectedNodes.push_back(20);
        p24.connectedNodes.push_back(23);

        p25.connectedNodes.push_back(26);

        p26.connectedNodes.push_back(22);
        p26.connectedNodes.push_back(25);
        p26.connectedNodes.push_back(27);

        p27.connectedNodes.push_back(19);
        p27.connectedNodes.push_back(26);

        corridors.push_back(p0);
        corridors.push_back(p1);
        corridors.push_back(p2);
        corridors.push_back(p3);
        corridors.push_back(p4);
        corridors.push_back(p5);
        corridors.push_back(p6);
        corridors.push_back(p7);
        corridors.push_back(p8);
        corridors.push_back(p9);
        corridors.push_back(p10);
        corridors.push_back(p11);
        corridors.push_back(p12);
        corridors.push_back(p13);
        corridors.push_back(p14);
        corridors.push_back(p15);
        corridors.push_back(p16);
        corridors.push_back(p17);
        corridors.push_back(p18);
        corridors.push_back(p19);
        corridors.push_back(p20);
        corridors.push_back(p21);
        corridors.push_back(p22);
        corridors.push_back(p23);
        corridors.push_back(p24);
        corridors.push_back(p25);
        corridors.push_back(p26);
        corridors.push_back(p27);
    }
}

