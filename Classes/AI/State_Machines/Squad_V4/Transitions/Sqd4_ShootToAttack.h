#ifndef SQD4_SHOOTTOATTACK_H
#define SQD4_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_ShootToAttack : public Transition
{
    public:
        Sqd4_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

