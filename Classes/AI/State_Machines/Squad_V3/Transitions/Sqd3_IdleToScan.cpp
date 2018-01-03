#include "Sqd3_IdleToScan.h"

Sqd3_IdleToScan::Sqd3_IdleToScan():Transition(constants::STATE_SCAN)
{

}

bool Sqd3_IdleToScan::isTriggered(AI_Info &info)
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

void Sqd3_IdleToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_IdleToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
