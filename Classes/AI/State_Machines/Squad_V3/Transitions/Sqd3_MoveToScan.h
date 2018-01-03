#ifndef SQD3_MOVETOSCAN_H
#define SQD3_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_MoveToScan : public Transition
{
    public:
        Sqd3_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
