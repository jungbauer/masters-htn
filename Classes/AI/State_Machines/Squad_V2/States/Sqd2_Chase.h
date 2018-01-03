#ifndef SQD2_CHASE_H
#define SQD2_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_ChaseToAttack.h"
#include "../Transitions/Sqd2_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd2_Chase : public State
{
    public:
        Sqd2_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
