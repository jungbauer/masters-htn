#ifndef IDLE_H
#define IDLE_H

#include "State.h"

class Idle : public State
{
    public:
        Idle();
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
