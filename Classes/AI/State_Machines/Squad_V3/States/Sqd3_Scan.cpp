#include "Sqd3_Scan.h"

Sqd3_Scan::Sqd3_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Sqd3_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Scan() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
