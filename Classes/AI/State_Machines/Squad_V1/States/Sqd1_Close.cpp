#include "Sqd1_Close.h"

Sqd1_Close::Sqd1_Close():State(constants::STATE_CLOSE)
{
    _transitions.push_back(new Sqd1_CloseToAttack); //TODO (imp#1#) Use try-catch for std::bad_alloc
}

void Sqd1_Close::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_Follow_Path()); //TODO (imp#1#) Use try-catch for std::bad_alloc
}
