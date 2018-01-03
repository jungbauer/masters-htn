#ifndef SQD1_MOVING_H
#define SQD1_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd1_MoveToIdle.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd1_Moving : public State
{
    public:
        Sqd1_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
