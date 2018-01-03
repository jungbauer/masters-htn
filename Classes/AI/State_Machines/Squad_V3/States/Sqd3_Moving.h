#ifndef SQD3_MOVING_H
#define SQD3_MOVING_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_MoveToIdle.h"
#include "../Transitions/Sqd3_MoveToScan.h"
#include "../Transitions/Sqd3_MoveToChase.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd3_Moving : public State
{
    public:
        Sqd3_Moving();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
