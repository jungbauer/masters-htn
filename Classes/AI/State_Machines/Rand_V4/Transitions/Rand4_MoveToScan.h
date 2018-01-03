#ifndef RAND4_MOVETOSCAN_H
#define RAND4_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand4_MoveToScan : public Transition
{
    public:
        Rand4_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
