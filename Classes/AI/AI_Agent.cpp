#include "AI_Agent.h"

AI_Agent::AI_Agent(constants::StateMachines fsm, VecXY_Float startPos, float orient, float spd, float rot, int tm, int ID, bool dumb) :
    info(startPos, orient, spd, rot, ID, tm, dumb),
    stuck_count(0)
{
    miss_count = 0;
    last_missed_bullet = -1;
    action_list.reserve(4);
//    stuck_count = 0;

    switch(fsm)
    {
        case constants::FSM_DEFAULT:
        {
            try
            {
                state_machine_ = new FSM_Default();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }

        }
        break;

        case constants::FSM_SQUAD_V1:
        {
            try
            {
                state_machine_ = new FSM_Squad_V1();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_RAND_V2:
        {
            try
            {
                state_machine_ = new FSM_Rand_V2();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_RAND_V3:
        {
            try
            {
                state_machine_ = new FSM_Rand_V3();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_RAND_V4:
        {
            try
            {
                state_machine_ = new FSM_Rand_V4();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_SQUAD_V2:
        {
            try
            {
                state_machine_ = new FSM_Squad_V2();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_SQUAD_V3:
        {
            try
            {
                state_machine_ = new FSM_Squad_V3();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_SQUAD_V4:
        {
            try
            {
                state_machine_ = new FSM_Squad_V4();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_SQUAD_V5:
        {
            try
            {
                state_machine_ = new FSM_Squad_V5();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

        case constants::FSM_CMD_HTN:
        {
            try
            {
                state_machine_ = new FSM_Htn();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
            break;

        case constants::FSM_IDLE:
        {
            try
            {
                state_machine_ = new StateMachine();
            }
            catch(std::bad_alloc& e)
            {
                std::cerr << "AI_Agent() bad_alloc memory error" << std::endl;
            }
        }
        break;

    }
}

AI_Agent::~AI_Agent()
{
    clear_Action_List();
    delete state_machine_;
}

void AI_Agent::clear_Action_List()
{
    for(unsigned int i = 0; i < action_list.size(); i++)
    {
        delete action_list[i];
    }
    action_list.clear();
}

void AI_Agent::erase_First_Action()
{
    delete action_list[0];

    vector<Action*>::iterator iter;
    iter = action_list.begin();
    action_list.erase(iter);
}

void AI_Agent::set_Moving_State()
{
    state_machine_->set_State(constants::STATE_MOVING);
}


void AI_Agent::update(Action* &act)
{
    // IF enemies are visible AND not already in the attack states
    if((info.visibleEnemiesCheck()) && (state_machine_->attackStatesCheck() == false))
    {
        // Set the engaged flag to TRUE
        info.engaged = true;

        //std::cerr << "0" << endl;
        //clear action list
        clear_Action_List();

        //set AI state to ATTACK
        state_machine_->set_State(constants::STATE_ATTACK);

        //consulte FSM
        state_machine_->update(action_list, info);
        act = action_list[0];
    }
    else
    {
        //std::cerr << "1" << endl;
        if(action_list.size() > 0)
        {
            //std::cerr << "2" << endl;
            act = action_list[0];
        }
        else
        {
            //std::cerr << "3" << endl;
            state_machine_->update(action_list, info);
            act = action_list[0];
        }
    }
}

void AI_Agent::pop_action()
{
    switch(action_list[0]->action_type)
    {
//        case constants::ACT_FOLLOW_PATH:
//        {
//            // The STATE_CLOSE condition forces the State to check its transitions. It does NOT trigger multiple pathfinds.
//            if((info.atPosition(info.path.get_End_Vec(), 5)) || (state_machine_->getState() == constants::STATE_CLOSE))
//            {
//                erase_First_Action();
//            }
//        }
//        break;

        default:
        {
            erase_First_Action();
        }
    }

//    if(info.action_list[0]->action_type == constants::ACT_FOLLOW_PATH)
//    {
//        Coord end = info.path.get_End_Coord();
//        if(reachedPosition(VecXY_Float((float)end.getX(),(float)end.getY()), 5))
//        {
//            info.erase_First_Action();
//        }
//    }
//    else
//    {
//        info.erase_First_Action();
//    }

}

constants::StateType AI_Agent::getState()
{
    return state_machine_->getState();
}

VecXY_Float AI_Agent::getNextPosition(unsigned int& deltaTicks)
{
    float x_shift = info.speed * cos(info.orientation*constants::PIE/180) * ((float)deltaTicks / 1000.f);
    float y_shift = info.speed * sin(info.orientation*constants::PIE/180) * ((float)deltaTicks / 1000.f);

    VecXY_Float nextPos = VecXY_Float(info.current_position.getX() + x_shift, info.current_position.getY() + y_shift);

    return nextPos;
}

void AI_Agent::move(unsigned int deltaTicks, Level& level)
{
    /// have I reached the next pos on the path?
    /// if so increment path pos
    /// else check orientation
    ///         if ok move
    ///         else modify orientation
    if(info.atPosition(info.next_path_coord, 5) == true)
    {
        Coord target;
        if(info.path.progressPosition(target) == true)
        {
            info.next_path_coord = VecXY_Float((float)target.getX(),(float)target.getY());
        }
    }
    else if(info.orientationCheck(info.next_path_coord, 1) == true)
    {
        VecXY_Float next_pos = getNextPosition(deltaTicks);
        VecXY_Float object;

        // Level collision check
        if(level.levelCollisionCheck_Circle(next_pos, info.radius, object) == false)
        {
            info.previous_position = info.current_position;
            info.current_position = next_pos;
        }
        else
        {
            stuck_count++;
            if(stuck_count >= 5)
            {
                // Sidestep Tile
                info.previous_position = info.current_position;
                info.current_position = side_Step(object);

                stuck_count = 0;
            }
        }
    }
    else
    {
        orientateTowardsTarget(info.next_path_coord, deltaTicks);
    }
}

void AI_Agent::moveOrientate(unsigned int deltaTicks, Level& level) {
    /// Is the path complete and incorrectly orientated -- orientate
    /// have I reached the next pos on the path?
    /// if so increment path pos
    /// else check orientation
    ///         if ok move
    ///         else modify orientation
    if(info.path.complete_Check() && !info.orientationCheck(info.observePoint, 1)){
        orientateTowardsTarget(info.observePoint, deltaTicks);
    }
    else if(info.atPosition(info.next_path_coord, 5) == true)
    {
        Coord target;
        if(info.path.progressPosition(target) == true)
        {
            info.next_path_coord = VecXY_Float((float)target.getX(),(float)target.getY());
        }
    }
    else if(info.orientationCheck(info.next_path_coord, 1) == true)
    {
        VecXY_Float next_pos = getNextPosition(deltaTicks);
        VecXY_Float object;

        // Level collision check
        if(level.levelCollisionCheck_Circle(next_pos, info.radius, object) == false)
        {
            info.previous_position = info.current_position;
            info.current_position = next_pos;
        }
        else
        {
            stuck_count++;
            if(stuck_count >= 5)
            {
                // Sidestep Tile
                info.previous_position = info.current_position;
                info.current_position = side_Step(object);

                stuck_count = 0;
            }
        }
    }
    else
    {
        orientateTowardsTarget(info.next_path_coord, deltaTicks);
    }
}

VecXY_Float AI_Agent::side_Step(VecXY_Float object)
{
    VecXY_Float diff = info.current_position - object;
    VecXY_Float shift = diff.normalize();
    shift = shift * 2;

    return info.current_position + shift;
}

void AI_Agent::orientateTowardsTarget(VecXY_Float target, unsigned int& deltaTicks)
{
    float angle_to_target = utils::calculateAngle(info.current_position, target);
    float orientation_shift = info.rotation * ((float)deltaTicks / 1000.f);

    // rotate world
    float new_orientation = info.orientation - angle_to_target;
    utils::trimAngle(new_orientation);

    // The positive shift angle is the difference between the new orientation and 360 degrees.
    // The negative shift is the new orientation.
    // We shift in the direction of the smallest one. ie the direction with the smallest diff from the target
    if(new_orientation > 360 - new_orientation)
    {
        // positive shift
        info.orientation += orientation_shift;
    }
    else
    {
        // negative shift
        info.orientation -= orientation_shift;
    }

    utils::trimAngle(info.orientation);

}

float AI_Agent::rotateAgent(bool direction, unsigned int& deltaTicks)
{
    float orientation_shift = info.rotation * ((float)deltaTicks / 1000.f);
    if(direction)
    {
        info.orientation += orientation_shift;
    }
    else
    {
        info.orientation -= orientation_shift;
    }
    utils::trimAngle(info.orientation);

    return orientation_shift;
}

void AI_Agent::setGoal(VecXY_Float goal)
{
    info.path_goal = goal;
    info.goal_changed_flag = true;
    info.goal_reached = false;
}

void AI_Agent::setAIPath(Path path)
{
    info.path = path;
    Coord target = info.path.getCurrentCheckPoint();
    info.next_path_coord= VecXY_Float((float)target.getX(),(float)target.getY());
}

void AI_Agent::registerDamage(float base, VecXY_Float bull_pos)
{
    info.health -= base;

    // Done like this to stop the flag and pos being changed many times in a fight with multiple foes.
    if(info.engaged == false)
    {
        info.engaged = true;
        info.bullet_pos = bull_pos;
    }

    if(info.health <= 0)
    {
        info.alive = false;
    }
}

void AI_Agent::register_Bullet_Miss(int bullet_ID, VecXY_Float obj_pos)
{
    // IF consecutive misses
    // THEN increment miss_count
    //      last_missed == bullet_ID
    //      IF miss_count > threshold
    //      THEN    side step away from blocking object
    //              reset count
    // ELSE reset

    if(last_missed_bullet+1 == bullet_ID)
    {
        last_missed_bullet = bullet_ID;
        miss_count++;
        if(miss_count > info.miss_threshold)
        {
            info.current_position = side_Step(obj_pos);
            miss_count = 0;
        }
    }
    else
    {
        miss_count = 0;
    }
}
