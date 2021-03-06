#include "Htn_IdleToScan.h"

Htn_IdleToScan::Htn_IdleToScan():Transition(constants::STATE_SCAN)
{

}

bool Htn_IdleToScan::isTriggered(AI_Info &info)
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

void Htn_IdleToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_IdleToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
