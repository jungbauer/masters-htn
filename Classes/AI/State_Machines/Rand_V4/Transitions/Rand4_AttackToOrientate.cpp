#include "Rand4_AttackToOrientate.h"

Rand4_AttackToOrientate::Rand4_AttackToOrientate():Transition(constants::STATE_ORIENTATE)
{

}

bool Rand4_AttackToOrientate::isTriggered(AI_Info &info)
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

void Rand4_AttackToOrientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_AttackToOrientate::getAction() bad_alloc memory error" << std::endl;
    }
}
