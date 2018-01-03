#include "Rand3_Idle.h"

Rand3_Idle::Rand3_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    try
    {
        _transitions.push_back(new Rand3_IdleToScan());
        _transitions.push_back(new Rand3_IdleToMove());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Idle() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand3_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

