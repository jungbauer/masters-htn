#include "Def_Attack.h"

Def_Attack::Def_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Def_AttackToIdle());
        _transitions.push_back(new Def_AttackToOrientate());
        _transitions.push_back(new Def_AttackToClose());
        _transitions.push_back(new Def_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Attack() bad_alloc memory error" << std::endl;
    }
}

void Def_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Def_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
