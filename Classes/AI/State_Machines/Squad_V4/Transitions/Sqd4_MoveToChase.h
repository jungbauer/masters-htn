#ifndef SQD4_MOVETOCHASE_H
#define SQD4_MOVETOCHASE_H

#include "../../Default/Transitions/Transition.h"
#include "../../../Actions/Act_Set_Support_Location.h"

class Sqd4_MoveToChase : public Transition
{
    public:
        Sqd4_MoveToChase();
        bool isTriggered(AI_Info &info);
        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif
