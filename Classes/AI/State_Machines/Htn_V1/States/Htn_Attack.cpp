#include "Htn_Attack.h"

Htn_Attack::Htn_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Htn_AttackToChase());
        _transitions.push_back(new Htn_AttackToIdle());
        _transitions.push_back(new Htn_AttackToOrientate());
        _transitions.push_back(new Htn_AttackToClose());
        _transitions.push_back(new Htn_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Attack() bad_alloc memory error" << std::endl;
    }
}

void Htn_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target_V2());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Htn_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
