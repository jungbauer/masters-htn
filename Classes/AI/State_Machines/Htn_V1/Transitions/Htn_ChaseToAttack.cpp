#include "Htn_ChaseToAttack.h"

Htn_ChaseToAttack::Htn_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Htn_ChaseToAttack::isTriggered(AI_Info &info)
{
    if(info.visibleEnemiesCheck() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Htn_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
