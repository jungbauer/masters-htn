#include "Sqd1_MoveToIdle.h"

Sqd1_MoveToIdle::Sqd1_MoveToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd1_MoveToIdle::isTriggered(AI_Info &info)
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

void Sqd1_MoveToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_None());
}
