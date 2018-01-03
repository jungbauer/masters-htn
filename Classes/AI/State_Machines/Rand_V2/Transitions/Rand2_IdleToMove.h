#ifndef RAND2_IDLETOMOVE_H
#define RAND2_IDLETOMOVE_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Rand_Pathfind.h"

class Rand2_IdleToMove : public Transition
{
    public:
        Rand2_IdleToMove();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
