#ifndef SQD5_MOVING_H
#define SQD5_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_MoveToIdle.h"
#include "../Transitions/Sqd5_MoveToChase.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd5_Moving : public State
{
    public:
        Sqd5_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
