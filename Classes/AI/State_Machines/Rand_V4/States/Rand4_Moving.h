#ifndef RAND4_MOVING_H
#define RAND4_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_MoveToIdle.h"
#include "../Transitions/Rand4_MoveToScan.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand4_Moving : public State
{
    public:
        Rand4_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
