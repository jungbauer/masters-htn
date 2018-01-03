#include "Htn_MoveToScan.h"

Htn_MoveToScan::Htn_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Htn_MoveToScan::isTriggered(AI_Info &info)
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

void Htn_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
