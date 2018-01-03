#ifndef PM_M_UTHREE_0_H
#define PM_M_UTHREE_0_H

#include "Method.h"
#include "../Tasks/Task_SquadOneToVulA.h"
#include "../Tasks/Task_SquadTwoToVulA.h"
#include "../Tasks/Task_SquadThreeToVulB.h"

class M_UTHREE_0 : public Method {
    public:
        M_UTHREE_0();

        bool checkConditions(WorldState worldState);

};


#endif
