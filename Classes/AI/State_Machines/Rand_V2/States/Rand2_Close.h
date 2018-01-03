#ifndef RAND2_CLOSE_H
#define RAND2_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Rand2_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand2_Close : public State
{
    public:
        Rand2_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

