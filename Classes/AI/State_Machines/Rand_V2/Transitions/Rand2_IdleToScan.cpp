#include "Rand2_IdleToScan.h"

Rand2_IdleToScan::Rand2_IdleToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand2_IdleToScan::isTriggered(AI_Info &info)
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

void Rand2_IdleToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_IdleToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
