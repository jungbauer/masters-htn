#include "Sqd2_MoveToScan.h"

Sqd2_MoveToScan::Sqd2_MoveToScan():Transition(constants::STATE_SCAN)
{

}

bool Sqd2_MoveToScan::isTriggered(AI_Info &info)
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

void Sqd2_MoveToScan::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_MoveToScan::getAction() bad_alloc memory error" << std::endl;
    }
}
