#ifndef SQD1_IDLE_H
#define SQD1_IDLE_H

#include "../../Default/States/State.h"

#include "../../../Actions/Act_Query_Squad.h"

class Sqd1_Idle : public State
{
    public:
        Sqd1_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
