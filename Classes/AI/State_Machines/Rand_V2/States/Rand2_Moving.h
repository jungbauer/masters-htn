#ifndef RAND2_MOVING_H
#define RAND2_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_MoveToIdle.h"
#include "../Transitions/Rand2_MoveToScan.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand2_Moving : public State
{
    public:
        Rand2_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
