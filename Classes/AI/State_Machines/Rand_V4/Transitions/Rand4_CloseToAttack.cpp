#include "Rand4_CloseToAttack.h"

Rand4_CloseToAttack::Rand4_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand4_CloseToAttack::isTriggered(AI_Info &info)
{
    if((info.rangeCheck(info.attack_target,50) == true) || (info.validateTarget(info.attack_target) == false)
       || (info.path.complete_Check() == true) || (info.betterTargetCheck()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand4_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Target_Flagged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_CloseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
