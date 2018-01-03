#include "Rand4_ChaseToAttack.h"

Rand4_ChaseToAttack::Rand4_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Rand4_ChaseToAttack::isTriggered(AI_Info &info)
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

void Rand4_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
