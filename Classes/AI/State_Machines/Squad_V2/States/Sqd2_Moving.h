#ifndef SQD2_MOVING_H
#define SQD2_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_MoveToIdle.h"
#include "../Transitions/Sqd2_MoveToScan.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd2_Moving : public State
{
    public:
        Sqd2_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
