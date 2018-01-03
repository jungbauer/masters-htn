#include "Sqd1_CloseToAttack.h"

Sqd1_CloseToAttack::Sqd1_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd1_CloseToAttack::isTriggered(AI_Info &info)
{
    if((info.rangeCheck(info.attack_target,50) == true) || (info.validateTarget(info.attack_target) == false) || (info.path.complete_Check() == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd1_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_None());
}
