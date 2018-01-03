#ifndef HTN_SCAN_H
#define HTN_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Htn_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Htn_Scan : public State
{
    public:
        Htn_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

