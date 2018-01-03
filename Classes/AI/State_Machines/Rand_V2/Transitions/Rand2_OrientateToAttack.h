#ifndef RAND2_ORIENTATETOATTACK_H
#define RAND2_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand2_OrientateToAttack : public Transition
{
    public:
        Rand2_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
