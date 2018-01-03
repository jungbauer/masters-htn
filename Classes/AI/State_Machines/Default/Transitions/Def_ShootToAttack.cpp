#include "Def_ShootToAttack.h"

Def_ShootToAttack::Def_ShootToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Def_ShootToAttack::isTriggered(AI_Info &info)
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

void Def_ShootToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_ShootToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
