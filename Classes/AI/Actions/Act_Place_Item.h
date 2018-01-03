#ifndef ACT_PLACE_ITEM_H
#define ACT_PLACE_ITEM_H

#include "Action.h"
#include "../../Item.h"
#include "../../Utils/Constants.h"
#include "../../Utils/VecXY_Float.h"

class Act_Place_Item : public Action
{
    public:
        Act_Place_Item(Item it, int loc_ID, VecXY_Float loc);

        Item item;
        VecXY_Float location;
        int location_ID;

    private:
};

#endif

