#ifndef SQD1_CLOSE_H
#define SQD1_CLOSE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd1_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd1_Close : public State
{
    public:
        Sqd1_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

