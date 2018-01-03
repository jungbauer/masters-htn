#include "Sqd4_AttackToShoot.h"

Sqd4_AttackToShoot::Sqd4_AttackToShoot():Transition(constants::STATE_SHOOT)
{

}

bool Sqd4_AttackToShoot::isTriggered(AI_Info &info)
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

void Sqd4_AttackToShoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_AttackToShoot::getAction() bad_alloc memory error" << std::endl;
    }
}
