#include "Rand4_AttackToIdle.h"

Rand4_AttackToIdle::Rand4_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Rand4_AttackToIdle::isTriggered(AI_Info &info)
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

void Rand4_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Reset_Engaged());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand4_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
