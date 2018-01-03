#ifndef SQD5_CHASE_H
#define SQD5_CHASE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_ChaseToAttack.h"
#include "../Transitions/Sqd5_ChaseToSearch.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd5_Chase : public State
{
    public:
        Sqd5_Chase();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
