#include "Item.h"

Item::Item():
        item_type(constants::ITEM_DEFAULT),
        item_name("Default Item"),
        item_ID(-1),
        item_quantity(0)
{
//    item_type = constants::ITEM_DEFAULT;
//    item_name = "Default Item";
//    item_ID = -1;
//    item_quantity = 0;
}

Item::Item(constants::Items type, std::string name, int ID, float quantity):
        item_type(type),
        item_name(name),
        item_ID(ID),
        item_quantity(quantity)
{
//    item_type = type;
//    item_name = name;
//    item_ID = ID;
//    item_quantity = quantity;
}

std::string Item::get_Text(constants::Items type)
{
    switch(type)
    {
        case constants::ITEM_DEFAULT:
            return "Default";
        break;
    }
    return "turd item";
}
