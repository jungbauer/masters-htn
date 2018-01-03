#ifndef PM_M_BC_0_H
#define PM_M_BC_0_H

#include "Method.h"
#include "../Tasks/Task_UseThree.h"

class M_BC_0 : public Method {
    public:
        M_BC_0();

        bool checkConditions(WorldState worldState);

};

#endif
