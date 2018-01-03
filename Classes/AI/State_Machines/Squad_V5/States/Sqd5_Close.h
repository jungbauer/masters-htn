#ifndef SQD5_CLOSE_H
#define SQD5_CLOSE_H

#include "../../Default/States/State.h"

#include "../Transitions/Sqd5_CloseToAttack.h"

#include "../../../Actions/Act_Follow_Path.h"

class Sqd5_Close : public State
{
    public:
        Sqd5_Close();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

