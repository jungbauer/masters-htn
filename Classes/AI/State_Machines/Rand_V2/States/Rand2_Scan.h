#ifndef RAND2_SCAN_H
#define RAND2_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand2_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Rand2_Scan : public State
{
    public:
        Rand2_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

