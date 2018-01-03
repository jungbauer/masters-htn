#include "Sqd2_Idle.h"

Sqd2_Idle::Sqd2_Idle():State(constants::STATE_IDLE)
{
    // The transition to the attack state is handled by the Agent class.
    // The transition to the move state is handled by squad query.
    try
    {
        _transitions.push_back(new Sqd2_IdleToScan());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Idle() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Query_Squad());
    }
    catch(std::bad_alloc& e)
    {
       std::cerr << "Sqd2_Idle::getAction() bad_alloc memory error" << std::endl;
    }
}

