#include "Sqd5_AttackToOrientate.h"

Sqd5_AttackToOrientate::Sqd5_AttackToOrientate():Transition(constants::STATE_ORIENTATE)
{

}

bool Sqd5_AttackToOrientate::isTriggered(AI_Info &info)
{
    if((info.validateTarget(info.attack_target) == true) && (info.orientationCheck(info.attack_target.current_position, 1) == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sqd5_AttackToOrientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_AttackToOrientate::getAction() bad_alloc memory error" << std::endl;
    }
}
