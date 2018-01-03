#include "Rand4_MoveToScan.h"

Rand4_MoveToScan::Rand4_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand4_MoveToScan::isTriggered(AI_Info &info)
{
    if(info.engaged == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand4_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
