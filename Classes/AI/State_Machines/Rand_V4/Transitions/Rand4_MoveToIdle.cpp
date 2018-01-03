#include "Rand4_MoveToIdle.h"

Rand4_MoveToIdle::Rand4_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand4_MoveToIdle::isTriggered(AI_Info &info)
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

void Rand4_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
