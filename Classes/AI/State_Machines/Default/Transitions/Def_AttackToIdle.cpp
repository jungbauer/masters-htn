#include "Def_AttackToIdle.h"

Def_AttackToIdle::Def_AttackToIdle():Transition(constants::STATE_IDLE)
{

}

bool Def_AttackToIdle::isTriggered(AI_Info &info)
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

void Def_AttackToIdle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Def_AttackToIdle::getAction() bad_alloc memory error" << std::endl;
    }
}
