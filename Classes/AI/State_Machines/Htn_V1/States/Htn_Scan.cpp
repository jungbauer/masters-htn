#include "Htn_Scan.h"

Htn_Scan::Htn_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Htn_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Scan() bad_alloc memory error" << std::endl;
    }
}

void Htn_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
