#ifndef RAND3_MOVETOSCAN_H
#define RAND3_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand3_MoveToScan : public Transition
{
    public:
        Rand3_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
