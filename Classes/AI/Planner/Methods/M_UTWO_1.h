#ifndef MASTERS_FSM_M_UTWO_1_H
#define MASTERS_FSM_M_UTWO_1_H


#include "Method.h"
#include "../Tasks/Task_FirstIdleToEngaged.h"

class M_UTWO_1 : public Method {
    public:
            M_UTWO_1();

            bool checkConditions(WorldState worldState);
};


#endif
