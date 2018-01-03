#ifndef SQD4_CLOSE_H
#define SQD4_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Sqd4_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd4_Close : public State
{
    public:
        Sqd4_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

