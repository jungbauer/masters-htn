#ifndef RAND3_SCAN_H
#define RAND3_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand3_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Rand3_Scan : public State
{
    public:
        Rand3_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

