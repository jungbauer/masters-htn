#include "Sqd1_AttackToShoot.h"

Sqd1_AttackToShoot::Sqd1_AttackToShoot():Transition(constants::STATE_SHOOT)
{

}

bool Sqd1_AttackToShoot::isTriggered(AI_Info &info)
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

void Sqd1_AttackToShoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd1_AttackToShoot::getAction() bad_alloc memory error" << std::endl;
    }
}
