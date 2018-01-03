#include "Sqd2_Scan.h"

Sqd2_Scan::Sqd2_Scan():State(constants::STATE_SCAN)
{
    try
    {
        _transitions.push_back(new Sqd2_ScanToIdle());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Scan() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Scan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Scan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Scan::getAction() bad_alloc memory error" << std::endl;
    }
}
