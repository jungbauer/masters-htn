#include "Rand3_ChaseToAttack.h"

Rand3_ChaseToAttack::Rand3_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand3_ChaseToAttack::isTriggered(AI_Info &info)
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

void Rand3_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
