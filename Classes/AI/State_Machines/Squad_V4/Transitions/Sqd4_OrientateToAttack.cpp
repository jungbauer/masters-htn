#include "Sqd4_OrientateToAttack.h"

Sqd4_OrientateToAttack::Sqd4_OrientateToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd4_OrientateToAttack::isTriggered(AI_Info &info)
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

void Sqd4_OrientateToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_OrientateToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
