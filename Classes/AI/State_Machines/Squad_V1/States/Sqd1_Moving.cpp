#include "Sqd1_Moving.h"

Sqd1_Moving::Sqd1_Moving():State(constants::STATE_MOVING)
{
    _transitions.push_back(new Sqd1_MoveToIdle);//TODO (imp#1#) Use try-catch for std::bad_alloc
}

void Sqd1_Moving::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_Follow_Path());//TODO (imp#1#) Use try-catch for std::bad_alloc
}
