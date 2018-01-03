#include "Rand2_IdleToMove.h"

Rand2_IdleToMove::Rand2_IdleToMove():Transition(constants::STATE_MOVING)
{

}

bool Rand2_IdleToMove::isTriggered(AI_Info &info)
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

void Rand2_IdleToMove::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Rand_Pathfind());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_IdleToMove::getAction() bad_alloc memory error" << std::endl;
    }
}
