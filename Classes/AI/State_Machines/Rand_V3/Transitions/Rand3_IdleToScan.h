#ifndef RAND3_IDLETOSCAN_H
#define RAND3_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand3_IdleToScan : public Transition
{
    public:
        Rand3_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
