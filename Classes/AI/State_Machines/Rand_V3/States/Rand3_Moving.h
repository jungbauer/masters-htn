#ifndef RAND3_MOVING_H
#define RAND3_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_MoveToIdle.h"
#include "../Transitions/Rand3_MoveToScan.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand3_Moving : public State
{
    public:
        Rand3_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
