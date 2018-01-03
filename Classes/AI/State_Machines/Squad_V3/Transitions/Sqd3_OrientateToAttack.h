#ifndef SQD3_ORIENTATETOATTACK_H
#define SQD3_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_OrientateToAttack : public Transition
{
    public:
        Sqd3_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
