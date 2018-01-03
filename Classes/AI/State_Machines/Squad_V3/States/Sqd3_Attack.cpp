#include "Sqd3_Attack.h"

Sqd3_Attack::Sqd3_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Sqd3_AttackToChase());
        _transitions.push_back(new Sqd3_AttackToIdle());
        _transitions.push_back(new Sqd3_AttackToOrientate());
        _transitions.push_back(new Sqd3_AttackToClose());
        _transitions.push_back(new Sqd3_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Attack() bad_alloc memory error" << std::endl;
    }
}

void Sqd3_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target_V2());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd3_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
