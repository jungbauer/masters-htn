#include "Act_Take_Item.h"

Act_Take_Item::Act_Take_Item(Item it, int loc_ID, VecXY_Float loc) : Action(constants::ACT_TAKE_ITEM),
        item(it),
        location(loc),
        location_ID(loc_ID)
{
//   item = it;
//   location_ID = loc_ID;
//   location = loc;
}

