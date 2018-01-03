#ifndef PM_M_UTHREE_2_H
#define PM_M_UTHREE_2_H

#include "Method.h"
#include "../Tasks/Task_FirstIdleToEngaged.h"
#include "../Tasks/Task_SecondIdleToEngaged.h"

class M_UTHREE_2 : public Method {
    public:
        M_UTHREE_2();

        bool checkConditions(WorldState worldState);
};


#endif
