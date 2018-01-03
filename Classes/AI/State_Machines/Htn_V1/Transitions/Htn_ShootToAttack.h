#ifndef HTN_SHOOTTOATTACK_H
#define HTN_SHOOTTOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Htn_ShootToAttack : public Transition
{
    public:
    Htn_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

