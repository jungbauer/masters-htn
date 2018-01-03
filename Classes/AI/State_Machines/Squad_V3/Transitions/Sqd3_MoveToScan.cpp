#include "Sqd3_MoveToScan.h"

Sqd3_MoveToScan::Sqd3_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Sqd3_MoveToScan::isTriggered(AI_Info &info)
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

void Sqd3_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
