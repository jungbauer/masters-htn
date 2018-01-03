#include "Sqd4_AttackToClose.h"

Sqd4_AttackToClose::Sqd4_AttackToClose():Transition(constants::STATE_CLOSE)
{}

bool Sqd4_AttackToClose::isTriggered(AI_Info &info)
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

void Sqd4_AttackToClose::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Pathfind(info.attack_target.current_position));
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_AttackToClose::getAction() bad_alloc memory error" << std::endl;
    }
}
