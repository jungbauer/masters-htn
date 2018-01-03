#include "Sqd3_ShootToAttack.h"

Sqd3_ShootToAttack::Sqd3_ShootToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd3_ShootToAttack::isTriggered(AI_Info &info)
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

void Sqd3_ShootToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_ShootToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
