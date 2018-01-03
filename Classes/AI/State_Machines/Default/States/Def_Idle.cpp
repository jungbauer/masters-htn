#include "Def_Idle.h"

Def_Idle::Def_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    try
    {
        _transitions.push_back(new Def_IdleToMove());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Idle() bad_alloc memory error" << std::endl;
    }
}

void Def_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Def_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

