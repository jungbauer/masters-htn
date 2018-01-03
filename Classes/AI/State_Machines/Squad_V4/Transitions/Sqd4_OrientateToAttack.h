#ifndef SQD4_ORIENTATETOATTACK_H
#define SQD4_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd4_OrientateToAttack : public Transition
{
    public:
        Sqd4_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
