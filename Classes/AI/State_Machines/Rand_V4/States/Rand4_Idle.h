#ifndef RAND4_IDLE_H
#define RAND4_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_IdleToMove.h"
#include "../Transitions/Rand4_IdleToScan.h"

class Rand4_Idle : public State
{
    public:
        Rand4_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
