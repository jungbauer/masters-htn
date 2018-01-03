#ifndef SQD3_SCAN_H
#define SQD3_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd3_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Sqd3_Scan : public State
{
    public:
        Sqd3_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

