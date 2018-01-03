#include "Sqd2_ChaseToAttack.h"

Sqd2_ChaseToAttack::Sqd2_ChaseToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Sqd2_ChaseToAttack::isTriggered(AI_Info &info)
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

void Sqd2_ChaseToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_ChaseToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}
