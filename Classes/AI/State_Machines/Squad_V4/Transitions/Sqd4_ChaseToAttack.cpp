#include "Sqd4_ChaseToAttack.h"

Sqd4_ChaseToAttack::Sqd4_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd4_ChaseToAttack::isTriggered(AI_Info &info)
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

void Sqd4_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
