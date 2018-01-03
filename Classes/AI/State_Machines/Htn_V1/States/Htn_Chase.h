#ifndef HTN_CHASE_H
#define HTN_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_ChaseToAttack.h"
#include "../Transitions/Htn_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Htn_Chase : public State
{
    public:
    Htn_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
