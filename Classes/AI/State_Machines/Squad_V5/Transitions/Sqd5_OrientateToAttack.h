#ifndef SQD5_ORIENTATETOATTACK_H
#define SQD5_ORIENTATETOATTACK_H

#include "../../Default/Transitions/Transition.h"

class Sqd5_OrientateToAttack : public Transition
{
    public:
        Sqd5_OrientateToAttack();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
