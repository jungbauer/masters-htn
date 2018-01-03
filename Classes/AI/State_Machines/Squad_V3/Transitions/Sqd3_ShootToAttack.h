#ifndef SQD3_SHOOTTOATTACK_H
#define SQD3_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_ShootToAttack : public Transition
{
    public:
        Sqd3_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

