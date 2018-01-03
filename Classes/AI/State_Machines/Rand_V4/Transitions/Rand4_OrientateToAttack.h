#ifndef RAND4_ORIENTATETOATTACK_H
#define RAND4_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Rand4_OrientateToAttack : public Transition
{
    public:
        Rand4_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
