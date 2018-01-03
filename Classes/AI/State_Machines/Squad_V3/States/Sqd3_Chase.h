#ifndef SQD3_CHASE_H
#define SQD3_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_ChaseToAttack.h"
#include "../Transitions/Sqd3_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd3_Chase : public State
{
    public:
        Sqd3_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
