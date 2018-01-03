#include "Rand3_AttackToChase.h"

Rand3_AttackToChase::Rand3_AttackToChase():Transition(constants::STATE_CHASE)
{}

bool Rand3_AttackToChase::isTriggered(AI_Info &info)
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

void Rand3_AttackToChase::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Pathfind(info.attack_target.current_position));
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_AttackToChase::getAction() bad_alloc memory error" << std::endl;
    }
}

