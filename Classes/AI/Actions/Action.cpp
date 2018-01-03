#include "Action.h"

Action::Action():action_type(constants::ACT_NONE)
{
//    action_type = constants::ACT_NONE;
}

Action::Action(constants::Actions type):action_type(type)
{
//    action_type = type;
}
