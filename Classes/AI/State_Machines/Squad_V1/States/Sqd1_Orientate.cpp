#include "Sqd1_Orientate.h"

Sqd1_Orientate::Sqd1_Orientate():State(constants::STATE_ORIENTATE)
{
    _transitions.push_back(new Sqd1_OrientateToAttack);//TODO (imp#1#) Use try-catch for std::bad_alloc
}

void Sqd1_Orientate::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_Orient());//TODO (imp#1#) Use try-catch for std::bad_alloc
}
