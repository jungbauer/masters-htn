#ifndef SQD1_ORIENTATE_H
#define SQD1_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd1_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Sqd1_Orientate : public State
{
    public:
        Sqd1_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

