#ifndef RAND4_IDLETOMOVE_H
#define RAND4_IDLETOMOVE_H

#include "../../Default/Transitions/Transition.h"

#include "../../../Actions/Act_Rand_Pathfind.h"

class Rand4_IdleToMove : public Transition
{
    public:
        Rand4_IdleToMove();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
