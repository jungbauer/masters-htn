#ifndef RAND3_IDLE_H
#define RAND3_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_IdleToMove.h"
#include "../Transitions/Rand3_IdleToScan.h"

class Rand3_Idle : public State
{
    public:
        Rand3_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
