#ifndef SQD1_SHOOTTOATTACK_H
#define SQD1_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_ShootToAttack : public Transition
{
    public:
        Sqd1_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

