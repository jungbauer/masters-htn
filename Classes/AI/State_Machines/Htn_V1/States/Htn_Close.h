#ifndef HTN_CLOSE_H
#define HTN_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Htn_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Htn_Close : public State
{
    public:
    Htn_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

