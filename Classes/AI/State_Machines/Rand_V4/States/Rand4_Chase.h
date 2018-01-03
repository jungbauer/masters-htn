#ifndef RAND4_CHASE_H
#define RAND4_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_ChaseToAttack.h"
#include "../Transitions/Rand4_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Rand4_Chase : public State
{
    public:
        Rand4_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
