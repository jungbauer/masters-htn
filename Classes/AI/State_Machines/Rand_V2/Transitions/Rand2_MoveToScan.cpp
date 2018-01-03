#include "Rand2_MoveToScan.h"

Rand2_MoveToScan::Rand2_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand2_MoveToScan::isTriggered(AI_Info &info)
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

void Rand2_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
