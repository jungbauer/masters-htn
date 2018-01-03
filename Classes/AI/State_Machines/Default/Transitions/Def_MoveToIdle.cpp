#include "Def_MoveToIdle.h"

Def_MoveToIdle::Def_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Def_MoveToIdle::isTriggered(AI_Info &info)
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

void Def_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
