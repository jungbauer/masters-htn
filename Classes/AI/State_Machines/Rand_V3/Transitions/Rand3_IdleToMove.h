#ifndef RAND3_IDLETOMOVE_H
#define RAND3_IDLETOMOVE_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Rand_Pathfind.h"

class Rand3_IdleToMove : public Transition
{
    public:
        Rand3_IdleToMove();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
