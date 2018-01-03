#ifndef RAND4_ORIENTATE_H
#define RAND4_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Rand4_Orientate : public State
{
    public:
        Rand4_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

