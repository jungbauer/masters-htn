#include "Rand4_Scan.h"

Rand4_Scan::Rand4_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Rand4_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Scan() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
