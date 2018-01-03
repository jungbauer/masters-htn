#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

#include "../Item.h"

#include "../Utils/Constants.h"
#include "../Utils/Utils.h"
#include "../Utils/Box.h"
#include "../Utils/VecXY_Float.h"

#include "../AI/Actions/Action.h"
#include "../AI/Actions/Act_None.h"

#include "../AI/AI_Info.h"

class Location
{
    public:
        Location();
        Location(int x, int y, int w, int h, constants::Locations tileType, std::string nm, int ID);
        virtual ~Location(){};

        virtual void getAction(vector<Action*> &actions, AI_Info &info)
        { actions.push_back(new Act_None()); }

        virtual void tick_Logic(bool day, unsigned int delta_ticks){}

        constants::Locations get_type();
        Box get_box();
        void GetCentrePixels(int &x, int &y);
        VecXY_Float GetCentrePixels_Vec();
        std::string get_Name();
        void set_Name(std::string nm);
        int get_ID();

        std::string get_Text(constants::Locations tileType);

        std::vector<Item> items;


    private:
        constants::Locations type;   // The tile type
        std::string name;
        int loc_ID;
        Box box;   //The attributes of the tile {x,y,w,h} & collision box
};

#endif
