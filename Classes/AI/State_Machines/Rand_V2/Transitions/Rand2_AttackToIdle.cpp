#include "Rand2_AttackToIdle.h"

Rand2_AttackToIdle::Rand2_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand2_AttackToIdle::isTriggered(AI_Info &info)
{
    if(info.visibleEnemiesCheck() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand2_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand2_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
