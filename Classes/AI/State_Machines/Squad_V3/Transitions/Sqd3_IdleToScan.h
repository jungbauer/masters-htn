#ifndef SQD3_IDLETOSCAN_H
#define SQD3_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Sqd3_IdleToScan : public Transition
{
    public:
        Sqd3_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
