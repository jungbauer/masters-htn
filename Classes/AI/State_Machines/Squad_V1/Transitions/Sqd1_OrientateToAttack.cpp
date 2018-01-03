#include "Sqd1_OrientateToAttack.h"

Sqd1_OrientateToAttack::Sqd1_OrientateToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd1_OrientateToAttack::isTriggered(AI_Info &info)
{
    if((info.orientationCheck(info.attack_target.current_position, 1) == true) || (info.validateTarget(info.attack_target) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd1_OrientateToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_None());
}
