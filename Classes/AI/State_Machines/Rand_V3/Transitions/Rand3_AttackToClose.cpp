#include "Rand3_AttackToClose.h"

Rand3_AttackToClose::Rand3_AttackToClose():Transition(constants::STATE_CLOSE)
{}

bool Rand3_AttackToClose::isTriggered(AI_Info &info)
{
    if((info.validateTarget(info.attack_target) == true) && (info.rangeCheck(info.attack_target, 0) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand3_AttackToClose::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Pathfind(info.attack_target.current_position));
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_AttackToClose::getAction() bad_alloc memory error" << std::endl;
    }
}
