#ifndef RAND4_IDLETOSCAN_H
#define RAND4_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Rand4_IdleToScan : public Transition
{
    public:
        Rand4_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
