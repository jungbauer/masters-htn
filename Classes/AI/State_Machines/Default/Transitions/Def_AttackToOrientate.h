#ifndef DEF_ATTACKTOORIENTATE_H
#define DEF_ATTACKTOORIENTATE_H

#include "Transition.h"

class Def_AttackToOrientate : public Transition
{
    public:
        Def_AttackToOrientate();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
