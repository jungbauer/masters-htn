#include "Rand3_CloseToAttack.h"

Rand3_CloseToAttack::Rand3_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand3_CloseToAttack::isTriggered(AI_Info &info)
{
    if((info.rangeCheck(info.attack_target,50) == true) || (info.validateTarget(info.attack_target) == false) || (info.path.complete_Check() == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand3_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_CloseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
