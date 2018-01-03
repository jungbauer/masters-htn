#include "Rand3_MoveToScan.h"

Rand3_MoveToScan::Rand3_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Rand3_MoveToScan::isTriggered(AI_Info &info)
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

void Rand3_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
