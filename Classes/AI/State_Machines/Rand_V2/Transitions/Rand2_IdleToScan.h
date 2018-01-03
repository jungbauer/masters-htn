#ifndef RAND2_IDLETOSCAN_H
#define RAND2_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand2_IdleToScan : public Transition
{
    public:
        Rand2_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
