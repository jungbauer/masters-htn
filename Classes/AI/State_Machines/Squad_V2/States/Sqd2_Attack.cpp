#include "Sqd2_Attack.h"

Sqd2_Attack::Sqd2_Attack():State(constants::STATE_ATTACK)
{
    try
    {
        _transitions.push_back(new Sqd2_AttackToChase());
        _transitions.push_back(new Sqd2_AttackToIdle());
        _transitions.push_back(new Sqd2_AttackToOrientate());
        _transitions.push_back(new Sqd2_AttackToClose());
        _transitions.push_back(new Sqd2_AttackToShoot());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Attack() bad_alloc memory error" << std::endl;
    }
}

void Sqd2_Attack::getAction(vector<Action*> &actions, AI_Info &info)
{
    try
    {
        actions.push_back(new Act_Choose_Target_V2());
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Sqd2_Attack::getAction() bad_alloc memory error" << std::endl;
    }
}
