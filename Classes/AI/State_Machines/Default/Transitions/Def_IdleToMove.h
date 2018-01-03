#ifndef DEF_IDLETOMOVE_H
#define DEF_IDLETOMOVE_H

#include "Transition.h"

#include "../../../Actions/Act_Rand_Pathfind.h"

class Def_IdleToMove : public Transition
{
    public:
        Def_IdleToMove();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
