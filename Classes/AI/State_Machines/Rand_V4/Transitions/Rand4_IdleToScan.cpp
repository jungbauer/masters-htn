#include "Rand4_IdleToScan.h"

Rand4_IdleToScan::Rand4_IdleToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand4_IdleToScan::isTriggered(AI_Info &info)
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

void Rand4_IdleToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_IdleToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
