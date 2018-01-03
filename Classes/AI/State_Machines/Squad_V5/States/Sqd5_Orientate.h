#ifndef SQD5_ORIENTATE_H
#define SQD5_ORIENTATE_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd5_OrientateToAttack.h"

#include "../../../Actions/Act_Orient.h"

class Sqd5_Orientate : public State
{
    public:
        Sqd5_Orientate();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

