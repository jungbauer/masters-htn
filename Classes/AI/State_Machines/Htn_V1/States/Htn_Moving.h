#ifndef HTN_MOVING_H
#define HTN_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_MoveToIdle.h"
#include "../Transitions/Htn_MoveToScan.h"

#include "../../../Actions/Act_Follow_Path_Orient.h"

class Htn_Moving : public State
{
    public:
    Htn_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
