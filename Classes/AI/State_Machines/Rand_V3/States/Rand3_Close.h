#ifndef RAND3_CLOSE_H
#define RAND3_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Rand3_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand3_Close : public State
{
    public:
        Rand3_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

