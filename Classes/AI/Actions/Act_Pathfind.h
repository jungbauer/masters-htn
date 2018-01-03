#ifndef ACT_PATHFIND_H
#define ACT_PATHFIND_H

#include "Action.h"
#include "../../Utils/Constants.h"
#include "../../Utils/VecXY_Float.h"

class Act_Pathfind : public Action
{
    public:
        Act_Pathfind(VecXY_Float tar);

        VecXY_Float target;

    private:
};

#endif
