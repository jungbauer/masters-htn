#include "Rand3_AttackToShoot.h"

Rand3_AttackToShoot::Rand3_AttackToShoot():Transition(constants::STATE_SHOOT)
{

}

bool Rand3_AttackToShoot::isTriggered(AI_Info &info)
{
    // IF: valid target AND within range AND correct orientation
    if((info.validateTarget(info.attack_target) == true) && (info.rangeCheck(info.attack_target, 0) == true) &&(info.orientationCheck(info.attack_target.current_position, 1) == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand3_AttackToShoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_AttackToShoot::getAction() bad_alloc memory error" << std::endl;
    }
}
