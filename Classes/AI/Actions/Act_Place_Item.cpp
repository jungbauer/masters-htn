#include "Act_Place_Item.h"

Act_Place_Item::Act_Place_Item(Item it, int loc_ID, VecXY_Float loc) : Action(constants::ACT_PLACE_ITEM),
        item(it),
        location(loc),
        location_ID(loc_ID)
{
//   item = it;
//   location_ID = loc_ID;
//   location = loc;
}


