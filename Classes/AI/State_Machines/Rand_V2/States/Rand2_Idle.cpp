#include "Rand2_Idle.h"

Rand2_Idle::Rand2_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    try
    {
        _transitions.push_back(new Rand2_IdleToScan());
        _transitions.push_back(new Rand2_IdleToMove());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Idle() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand2_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

