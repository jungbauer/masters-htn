#ifndef SQD4_CHASE_H
#define SQD4_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_ChaseToAttack.h"
#include "../Transitions/Sqd4_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd4_Chase : public State
{
    public:
        Sqd4_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
