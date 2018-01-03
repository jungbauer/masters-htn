#include "Htn_SearchToAttack.h"

Htn_SearchToAttack::Htn_SearchToAttack():Transition(constants::STATE_ATTACK)
{

}

bool Htn_SearchToAttack::isTriggered(AI_Info &info)
{
    // IF there are visible enemies OR agent has finished spinning in a circle.
    if((info.visibleEnemiesCheck() == true) || (info.search_rotation >= 360))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Htn_SearchToAttack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_SearchToAttack::getAction() bad_alloc memory error" << std::endl;
    }
}

