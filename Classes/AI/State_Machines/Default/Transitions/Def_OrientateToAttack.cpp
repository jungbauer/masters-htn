#include "Def_OrientateToAttack.h"

Def_OrientateToAttack::Def_OrientateToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Def_OrientateToAttack::isTriggered(AI_Info &info)
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

void Def_OrientateToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_OrientateToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
