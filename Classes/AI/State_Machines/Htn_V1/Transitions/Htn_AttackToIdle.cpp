#include "Htn_AttackToIdle.h"

Htn_AttackToIdle::Htn_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Htn_AttackToIdle::isTriggered(AI_Info &info)
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

void Htn_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Htn_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
