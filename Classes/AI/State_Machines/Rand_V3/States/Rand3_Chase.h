#ifndef RAND3_CHASE_H
#define RAND3_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_ChaseToAttack.h"
#include "../Transitions/Rand3_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand3_Chase : public State
{
    public:
        Rand3_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
