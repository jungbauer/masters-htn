#include "Rand3_IdleToScan.h"

Rand3_IdleToScan::Rand3_IdleToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand3_IdleToScan::isTriggered(AI_Info &info)
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

void Rand3_IdleToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_IdleToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
