#ifndef PM_M_BC_1_H
#define PM_M_BC_1_H

#include "Method.h"
#include "../Tasks/Task_UseTwo.h"

class M_BC_1 : public Method {
    public:
        M_BC_1();

        bool checkConditions(WorldState worldState);

};


#endif
