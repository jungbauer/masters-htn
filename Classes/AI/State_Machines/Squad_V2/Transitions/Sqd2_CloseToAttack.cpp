#include "Sqd2_CloseToAttack.h"

Sqd2_CloseToAttack::Sqd2_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd2_CloseToAttack::isTriggered(AI_Info &info)
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

void Sqd2_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Target_Flagged());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_CloseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
