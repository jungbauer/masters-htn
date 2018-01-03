#include "Rand3_Attack.h"

Rand3_Attack::Rand3_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Rand3_AttackToChase());
        _transitions.push_back(new Rand3_AttackToIdle());
        _transitions.push_back(new Rand3_AttackToOrientate());
        _transitions.push_back(new Rand3_AttackToClose());
        _transitions.push_back(new Rand3_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Attack() bad_alloc memory error" << std::endl;
    }
}

void Rand3_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand3_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
