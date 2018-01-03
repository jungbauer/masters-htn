#include "Sqd3_AttackToIdle.h"

Sqd3_AttackToIdle::Sqd3_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd3_AttackToIdle::isTriggered(AI_Info &info)
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

void Sqd3_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd3_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
