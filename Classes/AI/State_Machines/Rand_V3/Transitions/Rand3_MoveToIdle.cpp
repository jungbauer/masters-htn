#include "Rand3_MoveToIdle.h"

Rand3_MoveToIdle::Rand3_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand3_MoveToIdle::isTriggered(AI_Info &info)
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

void Rand3_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
