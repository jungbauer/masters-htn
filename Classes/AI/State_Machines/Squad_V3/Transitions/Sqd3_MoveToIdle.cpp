#include "Sqd3_MoveToIdle.h"

Sqd3_MoveToIdle::Sqd3_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd3_MoveToIdle::isTriggered(AI_Info &info)
{
    if(info.path.complete_Check() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd3_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
