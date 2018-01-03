#ifndef SQD2_MOVETOSCAN_H
#define SQD2_MOVETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_MoveToScan : public Transition
{
    public:
        Sqd2_MoveToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
