#ifndef HTN_IDLE_H
#define HTN_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_IdleToScan.h"
#include "../../../Actions/Act_Query_Squad.h"

class Htn_Idle : public State
{
    public:
    Htn_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
