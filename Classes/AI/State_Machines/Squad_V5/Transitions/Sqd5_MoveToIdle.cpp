#include "Sqd5_MoveToIdle.h"

Sqd5_MoveToIdle::Sqd5_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd5_MoveToIdle::isTriggered(AI_Info &info)
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

void Sqd5_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
