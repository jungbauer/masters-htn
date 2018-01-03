#ifndef SQD5_SHOOTTOATTACK_H
#define SQD5_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_ShootToAttack : public Transition
{
    public:
        Sqd5_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

