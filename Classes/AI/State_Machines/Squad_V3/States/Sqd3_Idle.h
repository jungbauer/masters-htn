#ifndef SQD3_IDLE_H
#define SQD3_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_IdleToScan.h"
#include "../Transitions/Sqd3_IdleToChase.h"
#include "../../../Actions/Act_Query_Squad.h"

class Sqd3_Idle : public State
{
    public:
        Sqd3_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
