#include "Rand4_Attack.h"

Rand4_Attack::Rand4_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Rand4_AttackToChase());
        _transitions.push_back(new Rand4_AttackToIdle());
        _transitions.push_back(new Rand4_AttackToOrientate());
        _transitions.push_back(new Rand4_AttackToClose());
        _transitions.push_back(new Rand4_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Attack() bad_alloc memory error" << std::endl;
    }
}

void Rand4_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target_V2());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Rand4_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
