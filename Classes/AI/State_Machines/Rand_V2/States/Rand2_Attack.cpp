#include "Rand2_Attack.h"

Rand2_Attack::Rand2_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Rand2_AttackToIdle());
        _transitions.push_back(new Rand2_AttackToOrientate());
        _transitions.push_back(new Rand2_AttackToClose());
        _transitions.push_back(new Rand2_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Attack() bad_alloc memory error" << std::endl;
    }
}

void Rand2_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand2_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
