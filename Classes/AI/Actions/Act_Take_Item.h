#ifndef ACT_TAKE_ITEM_H
#define ACT_TAKE_ITEM_H

#include "Action.h"
#include "../../Item.h"
#include "../../Utils/Constants.h"
#include "../../Utils/VecXY_Float.h"

class Act_Take_Item : public Action
{
    public:
        Act_Take_Item(Item it, int loc_ID, VecXY_Float loc);

        Item item;
        VecXY_Float location;
        int location_ID;

    private:
};

#endif
