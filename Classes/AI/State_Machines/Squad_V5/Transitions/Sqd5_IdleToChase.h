#ifndef SQD5_IDLETOCHASE_H
#define SQD5_IDLETOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Set_Support_Location.h"

class Sqd5_IdleToChase : public Transition
{
    public:
        Sqd5_IdleToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
