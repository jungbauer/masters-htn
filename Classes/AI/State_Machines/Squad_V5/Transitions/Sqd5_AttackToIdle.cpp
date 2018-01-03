#include "Sqd5_AttackToIdle.h"

Sqd5_AttackToIdle::Sqd5_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd5_AttackToIdle::isTriggered(AI_Info &info)
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

void Sqd5_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd5_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
