#ifndef SQD2_ORIENTATETOATTACK_H
#define SQD2_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_OrientateToAttack : public Transition
{
    public:
        Sqd2_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
