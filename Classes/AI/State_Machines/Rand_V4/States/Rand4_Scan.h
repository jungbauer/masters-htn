#ifndef RAND4_SCAN_H
#define RAND4_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Rand4_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Rand4_Scan : public State
{
    public:
        Rand4_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

