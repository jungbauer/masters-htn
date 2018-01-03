#include "Sqd1_AttackToIdle.h"

Sqd1_AttackToIdle::Sqd1_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd1_AttackToIdle::isTriggered(AI_Info &info)
{
    if(info.visibleEnemiesCheck() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd1_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_None());
}
