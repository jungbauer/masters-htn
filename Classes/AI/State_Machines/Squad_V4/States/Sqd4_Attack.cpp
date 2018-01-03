#include "Sqd4_Attack.h"

Sqd4_Attack::Sqd4_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Sqd4_AttackToIdle());
        _transitions.push_back(new Sqd4_AttackToOrientate());
        _transitions.push_back(new Sqd4_AttackToClose());
        _transitions.push_back(new Sqd4_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Attack() bad_alloc memory error" << std::endl;
    }
}

void Sqd4_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd4_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
