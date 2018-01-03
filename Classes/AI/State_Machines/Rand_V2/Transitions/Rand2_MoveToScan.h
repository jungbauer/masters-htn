#ifndef RAND2_MOVETOSCAN_H
#define RAND2_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand2_MoveToScan : public Transition
{
    public:
        Rand2_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
