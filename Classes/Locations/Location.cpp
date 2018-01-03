#include "Location.h"

Location::Location():
        type(constants::LOC_DEFAULT),
        name("Default Location"),
        loc_ID(-1),
        box(Box(1,1,1,1))
{
//    box.set_x(1);
//    box.set_y(1);
//    box.set_w(1);
//    box.set_h(1);
//
//    type = constants::LOC_DEFAULT;
//    loc_ID = -1;
//    name = "Default Location";
}

Location::Location(int x, int y, int w, int h, constants::Locations tileType, std::string nm, int ID):
        type(tileType),
        name(nm),
        loc_ID(ID),
        box(Box(x,y,w,h))
{
//    box.set_x(x);
//    box.set_y(y);
//    box.set_w(w);
//    box.set_h(h);
//
//    type = tileType;
//    name = nm;
//    loc_ID = ID;
}

std::string Location::get_Text(constants::Locations tileType)
{
    switch(tileType)
    {
        case constants::LOC_DEFAULT:
            return "Default";
        break;
    }
    return "turd";
}

constants::Locations Location::get_type()
{
    return type;
}

Box Location::get_box()
{
    return box;
}

void Location::GetCentrePixels(int &x, int &y)
{
    x = box.get_x() + (box.get_w()/2);
    y = box.get_y() + (box.get_h()/2);
}

VecXY_Float Location::GetCentrePixels_Vec()
{
    int x = 0, y = 0;

    GetCentrePixels(x,y);

    return VecXY_Float((float) x, (float) y);
}

std::string Location::get_Name()
{
    return name;
}

void Location::set_Name(std::string nm)
{
    name = nm;
}

int Location::get_ID()
{
    return loc_ID;
}

