#include "Sqd1_Shoot.h"

Sqd1_Shoot::Sqd1_Shoot():State(constants::STATE_SHOOT)
{
    _transitions.push_back(new Sqd1_ShootToAttack);//TODO (imp#1#) Use try-catch for std::bad_alloc
}

void Sqd1_Shoot::getAction(vector<Action*> &actions, AI_Info &info)
{
    actions.push_back(new Act_Fire());//TODO (imp#1#) Use try-catch for std::bad_alloc
}
