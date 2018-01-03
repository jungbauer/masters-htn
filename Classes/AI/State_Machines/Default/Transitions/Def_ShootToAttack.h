#ifndef DEF_SHOOTTOATTACK_H
#define DEF_SHOOTTOATTACK_H

#include "Transition.h"

class Def_ShootToAttack : public Transition
{
    public:
        Def_ShootToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

