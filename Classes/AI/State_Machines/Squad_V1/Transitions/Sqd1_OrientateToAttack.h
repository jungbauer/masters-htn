#ifndef SQD1_ORIENTATETOATTACK_H
#define SQD1_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd1_OrientateToAttack : public Transition
{
    public:
        Sqd1_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
