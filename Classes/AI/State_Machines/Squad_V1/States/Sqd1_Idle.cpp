#include "Sqd1_Idle.h"

Sqd1_Idle::Sqd1_Idle():State(constants::STATE_IDLE)
{}

void Sqd1_Idle::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_Query_Squad());//TODO (imp#1#) Use try-catch for std::bad_alloc
}

