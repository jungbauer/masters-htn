#include "Sqd2_AttackToIdle.h"

Sqd2_AttackToIdle::Sqd2_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Sqd2_AttackToIdle::isTriggered(AI_Info &info)
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

void Sqd2_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd2_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
