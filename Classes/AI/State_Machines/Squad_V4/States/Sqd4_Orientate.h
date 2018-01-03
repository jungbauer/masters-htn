#ifndef SQD4_ORIENTATE_H
#define SQD4_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd4_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Sqd4_Orientate : public State
{
    public:
        Sqd4_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

