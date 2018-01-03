#ifndef RAND3_ORIENTATE_H
#define RAND3_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Rand3_Orientate : public State
{
    public:
        Rand3_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

