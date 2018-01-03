#include "Rand4_Idle.h"

Rand4_Idle::Rand4_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    try
    {
        _transitions.push_back(new Rand4_IdleToScan());
        _transitions.push_back(new Rand4_IdleToMove());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Idle() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Rand4_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

