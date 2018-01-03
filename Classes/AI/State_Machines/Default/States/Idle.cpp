#include "Idle.h"

Idle::Idle():State(constants::STATE_IDLE)
{}

void Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_None());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Idle::getAction() bad_alloc memory error" << std::endl;
    }
}


