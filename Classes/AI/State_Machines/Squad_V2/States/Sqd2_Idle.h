#ifndef SQD2_IDLE_H
#define SQD2_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_IdleToScan.h"
#include "../../../Actions/Act_Query_Squad.h"

class Sqd2_Idle : public State
{
    public:
        Sqd2_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
