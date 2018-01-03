#ifndef SQD3_CLOSE_H
#define SQD3_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Sqd3_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd3_Close : public State
{
    public:
        Sqd3_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

