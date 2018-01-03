#ifndef HTN_ORIENTATETOATTACK_H
#define HTN_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Htn_OrientateToAttack : public Transition
{
    public:
    Htn_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
