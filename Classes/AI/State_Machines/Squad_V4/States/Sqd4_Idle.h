#ifndef SQD4_IDLE_H
#define SQD4_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_IdleToChase.h"
#include "../../../Actions/Act_Query_Squad.h"

class Sqd4_Idle : public State
{
    public:
        Sqd4_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
