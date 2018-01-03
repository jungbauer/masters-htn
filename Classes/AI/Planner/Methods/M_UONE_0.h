#ifndef PM_M_UONE_0_H
#define PM_M_UONE_0_H

#include "Method.h"
#include "../Tasks/Task_FirstIdleToVulA.h"

class M_UONE_0 : public Method {
    public:
        M_UONE_0();

        bool checkConditions(WorldState worldState);
};


#endif
