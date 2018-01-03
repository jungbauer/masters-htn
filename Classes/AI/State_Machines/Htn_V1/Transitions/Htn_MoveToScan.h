#ifndef HTN_MOVETOSCAN_H
#define HTN_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Htn_MoveToScan : public Transition
{
    public:
    Htn_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
