#include "Def_CloseToAttack.h"

Def_CloseToAttack::Def_CloseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Def_CloseToAttack::isTriggered(AI_Info &info)
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

void Def_CloseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_CloseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
