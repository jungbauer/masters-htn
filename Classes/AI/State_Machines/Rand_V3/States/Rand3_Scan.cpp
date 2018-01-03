#include "Rand3_Scan.h"

Rand3_Scan::Rand3_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Rand3_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Scan() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
