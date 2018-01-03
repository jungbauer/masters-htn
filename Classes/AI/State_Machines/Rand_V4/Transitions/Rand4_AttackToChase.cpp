#include "Rand4_AttackToChase.h"

Rand4_AttackToChase::Rand4_AttackToChase():Transition(constants::STATE_CHASE)
{}

bool Rand4_AttackToChase::isTriggered(AI_Info &info)
{
    // IF no seen enemies && current target is not dead && target pos is within search range
    if((info.visibleEnemiesCheck() == false) && (info.deadEnemiesCheck(info.attack_target.agent_ID) == false) && (info.searchRangeCheck(info.attack_target, 1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Rand4_AttackToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Pathfind(info.attack_target.current_position));
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_AttackToChase::getAction() bad_alloc memory error" << std::endl;
    }
}

