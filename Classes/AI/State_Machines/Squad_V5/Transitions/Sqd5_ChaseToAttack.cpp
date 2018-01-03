#include "Sqd5_ChaseToAttack.h"

Sqd5_ChaseToAttack::Sqd5_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd5_ChaseToAttack::isTriggered(AI_Info &info)
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

void Sqd5_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd5_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
