#include "Sqd3_Idle.h"

Sqd3_Idle::Sqd3_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    // The transition to the move state is handled by squad query.
    try
    {
        _transitions.push_back(new Sqd3_IdleToScan());
        _transitions.push_back(new Sqd3_IdleToChase());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Idle() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Query_Squad());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd3_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

