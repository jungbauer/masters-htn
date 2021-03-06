#include "Rand3_AttackToIdle.h"

Rand3_AttackToIdle::Rand3_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand3_AttackToIdle::isTriggered(AI_Info &info)
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

void Rand3_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand3_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
