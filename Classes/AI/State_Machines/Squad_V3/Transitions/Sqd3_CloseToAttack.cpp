#include "Sqd3_CloseToAttack.h"

Sqd3_CloseToAttack::Sqd3_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd3_CloseToAttack::isTriggered(AI_Info &info)
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

void Sqd3_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Target_Flagged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_CloseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
