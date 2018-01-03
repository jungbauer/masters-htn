#ifndef RAND2_IDLE_H
#define RAND2_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_IdleToMove.h"
#include "../Transitions/Rand2_IdleToScan.h"

class Rand2_Idle : public State
{
    public:
        Rand2_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
