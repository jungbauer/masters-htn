#include "Htn_MoveToIdle.h"

Htn_MoveToIdle::Htn_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Htn_MoveToIdle::isTriggered(AI_Info &info)
{
    return (info.path.complete_Check() && info.orientationCheck(info.observePoint, 1));
}

void Htn_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_MoveToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
