#ifndef DEF_ORIENTATETOATTACK_H
#define DEF_ORIENTATETOATTACK_H

#include "Transition.h"

class Def_OrientateToAttack : public Transition
{
    public:
        Def_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
