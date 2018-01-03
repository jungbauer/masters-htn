#ifndef HTN_IDLETOSCAN_H
#define HTN_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Htn_IdleToScan : public Transition
{
    public:
    Htn_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
