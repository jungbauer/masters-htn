#ifndef RAND3_ORIENTATETOATTACK_H
#define RAND3_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand3_OrientateToAttack : public Transition
{
    public:
        Rand3_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
