#ifndef PM_M_UTHREE_3_H
#define PM_M_UTHREE_3_H

#include "Method.h"
#include "../Tasks/Task_FirstIdleToClosestEngaged.h"

class M_UTHREE_3 : public Method {
    public:
        M_UTHREE_3();

        bool checkConditions(WorldState worldState);
};


#endif
