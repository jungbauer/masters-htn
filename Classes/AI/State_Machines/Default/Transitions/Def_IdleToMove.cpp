#include "Def_IdleToMove.h"

Def_IdleToMove::Def_IdleToMove():Transition(constants::STATE_MOVING)
{

}

bool Def_IdleToMove::isTriggered(AI_Info &info)
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

void Def_IdleToMove::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Rand_Pathfind());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_IdleToMove::getAction() bad_alloc memory error" << std::endl;
    }
}
