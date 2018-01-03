#ifndef SQD2_SHOOTTOATTACK_H
#define SQD2_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_ShootToAttack : public Transition
{
    public:
        Sqd2_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

