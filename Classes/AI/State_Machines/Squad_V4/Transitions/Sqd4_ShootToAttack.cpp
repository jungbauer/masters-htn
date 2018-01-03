#include "Sqd4_ShootToAttack.h"

Sqd4_ShootToAttack::Sqd4_ShootToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd4_ShootToAttack::isTriggered(AI_Info &info)
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

void Sqd4_ShootToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_ShootToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
