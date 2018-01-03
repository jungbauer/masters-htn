#ifndef SQD5_IDLE_H
#define SQD5_IDLE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_IdleToChase.h"
#include "../../../Actions/Act_Query_Squad.h"

class Sqd5_Idle : public State
{
    public:
        Sqd5_Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
