#include "Rand2_AttackToOrientate.h"

Rand2_AttackToOrientate::Rand2_AttackToOrientate():Transition(constants::STATE_ORIENTATE)
{

}

bool Rand2_AttackToOrientate::isTriggered(AI_Info &info)
{
    if((info.validateTarget(info.attack_target) == true) && (info.orientationCheck(info.attack_target.current_position, 1) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand2_AttackToOrientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_AttackToOrientate::getAction() bad_alloc memory error" << std::endl;
    }
}
