#include "Sqd4_MoveToIdle.h"

Sqd4_MoveToIdle::Sqd4_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd4_MoveToIdle::isTriggered(AI_Info &info)
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

void Sqd4_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
