#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Utils/Constants.h"
#include "Utils/Utils.h"

class Item
{
    public:
        Item();
        Item(constants::Items type, std::string name, int ID, float quantity);

        std::string get_Text(constants::Items type);

        constants::Items item_type;
        std::string item_name;
        int item_ID;
        float item_quantity;

    private:

};

#endif

