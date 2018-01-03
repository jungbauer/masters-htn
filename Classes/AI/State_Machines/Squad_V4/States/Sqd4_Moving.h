#ifndef SQD4_MOVING_H
#define SQD4_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_MoveToIdle.h"
#include "../Transitions/Sqd4_MoveToChase.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd4_Moving : public State
{
    public:
        Sqd4_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
