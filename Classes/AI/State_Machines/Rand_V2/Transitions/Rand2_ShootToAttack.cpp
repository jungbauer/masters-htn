#include "Rand2_ShootToAttack.h"

Rand2_ShootToAttack::Rand2_ShootToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand2_ShootToAttack::isTriggered(AI_Info &info)
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

void Rand2_ShootToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_ShootToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
