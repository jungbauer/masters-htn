#ifndef PM_M_UTHREE_1_H
#define PM_M_UTHREE_1_H

#include "Method.h"
#include "../Tasks/Task_SquadOneToVulA.h"
#include "../Tasks/Task_SquadTwoToVulA.h"
#include "../Tasks/Task_SquadThreeToVulA.h"

class M_UTHREE_1 : public Method {
    public:
        M_UTHREE_1();

        bool checkConditions(WorldState worldState);
};


#endif
