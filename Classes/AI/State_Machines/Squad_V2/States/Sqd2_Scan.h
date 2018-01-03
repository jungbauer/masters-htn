#ifndef SQD2_SCAN_H
#define SQD2_SCAN_H

#include "../../Default/States/State.h"
#include "../Transitions/Sqd2_ScanToIdle.h"

#include "../../../Actions/Act_Scan.h"

class Sqd2_Scan : public State
{
    public:
        Sqd2_Scan();

        void getAction(vector<Action*> &actions, AI_Info &info);
};

#endif

