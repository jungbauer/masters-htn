#include "Rand2_Scan.h"

Rand2_Scan::Rand2_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Rand2_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Scan() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
