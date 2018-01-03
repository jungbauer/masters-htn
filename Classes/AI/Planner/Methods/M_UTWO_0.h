#ifndef PM_M_UTWO_0_H
#define PM_M_UTWO_0_H

#include "Method.h"
#include "../Tasks/Task_FirstIdleToVulA.h"
#include "../Tasks/Task_SecondIdleToVulA.h"

class M_UTWO_0 : public Method {
    public:
        M_UTWO_0();

        bool checkConditions(WorldState worldState);
};


#endif
