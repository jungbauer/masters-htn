#include "Sqd1_ShootToAttack.h"

Sqd1_ShootToAttack::Sqd1_ShootToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd1_ShootToAttack::isTriggered(AI_Info &info)
{
    if((info.validateTarget(info.attack_target) == false) || (info.orientationCheck(info.attack_target.current_position, 1) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd1_ShootToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_None());
}
