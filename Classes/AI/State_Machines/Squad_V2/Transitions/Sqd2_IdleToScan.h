#ifndef SQD2_IDLETOSCAN_H
#define SQD2_IDLETOSCAN_H

#include "../../Default/Transitions/Transition.h"

class Sqd2_IdleToScan : public Transition
{
    public:
        Sqd2_IdleToScan();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
