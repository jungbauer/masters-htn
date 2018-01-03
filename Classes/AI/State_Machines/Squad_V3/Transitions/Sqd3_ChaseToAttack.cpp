#include "Sqd3_ChaseToAttack.h"

Sqd3_ChaseToAttack::Sqd3_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd3_ChaseToAttack::isTriggered(AI_Info &info)
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

void Sqd3_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
