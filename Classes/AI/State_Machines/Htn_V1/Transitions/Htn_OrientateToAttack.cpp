#include "Htn_OrientateToAttack.h"

Htn_OrientateToAttack::Htn_OrientateToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Htn_OrientateToAttack::isTriggered(AI_Info &info)
{
    if((info.orientationCheck(info.attack_target.current_position, 1) == true) || (info.validateTarget(info.attack_target) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Htn_OrientateToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_OrientateToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
