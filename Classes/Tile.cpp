#include "Tile.h"

Tile::Tile():
        map_ref(-1),
        path_ref(-1),
        path_node(false),
        leave_cost(5.99),
        enter_cost(5.99),
        type(0),
        box(Box(-1, -1, constants::TILE_WIDTH, constants::TILE_HEIGHT))
{
//    type = 0;
//
//    map_ref = -1;
//    path_ref = -1;
//    path_node = false;
//    leave_cost = 5.99;
//    enter_cost = 5.99;
}

Tile::Tile(int x, int y, int tileType):
        map_ref(-1),
        path_ref(-1),
        path_node(false),
        leave_cost(999.99),
        enter_cost(999.99),
        type(tileType),
        box(Box(x, y, constants::TILE_WIDTH, constants::TILE_HEIGHT))
{
//    box.set_x(x);
//    box.set_y(y);
//    box.set_w(constants::TILE_WIDTH);
//    box.set_h(constants::TILE_HEIGHT);
//
//    //Get the tile type
//    type = tileType;
//
//    map_ref = -1;
//    path_ref = -1;
//    path_node = false;
//    leave_cost = 999.99;
//    enter_cost = 999.99;
}

int Tile::get_type()
{
    return type;
}

Box Tile::get_box()
{
    return box;
}

void Tile::GetGridPosition(int &x, int &y)
{
    x = box.get_x() / box.get_w();
    y = box.get_y() / box.get_h();
}

void Tile::GetCentrePixels(int &x, int &y)
{
    x = box.get_x() + (box.get_w()/2);
    y = box.get_y() + (box.get_h()/2);
}
