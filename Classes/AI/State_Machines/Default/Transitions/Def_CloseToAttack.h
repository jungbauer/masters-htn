#ifndef DEF_CLOSETOATTACK_H
#define DEF_CLOSETOATTACK_H

#include "Transition.h"

class Def_CloseToAttack : public Transition
{
    public:
        Def_CloseToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
