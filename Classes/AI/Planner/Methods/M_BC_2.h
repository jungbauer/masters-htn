#ifndef PM_M_BC_2_H
#define PM_M_BC_2_H

#include "Method.h"
#include "../Tasks/Task_UseOne.h"

class M_BC_2 : public Method {
    public:
        M_BC_2();

        bool checkConditions(WorldState worldState);
};


#endif
