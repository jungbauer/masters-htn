#ifndef SQD3_IDLETOCHASE_H
#define SQD3_IDLETOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Set_Support_Location.h"

class Sqd3_IdleToChase : public Transition
{
    public:
        Sqd3_IdleToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
