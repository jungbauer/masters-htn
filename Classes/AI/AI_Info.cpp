#include "AI_Info.h"

AI_Info::AI_Info(VecXY_Float startPos, float orient, float spd, float rot, int ID, int tm, bool dumb):
        speed(spd),
        rotation(rot),
        radius(15.0),
        fov(90.0),
        vision_range(400),
        agent_ID(ID),
        team(tm),
        health(100.0),
        max_health(100.0),
        alive(true),
        dummy(dumb),
        squad_ID(-1),
        orientation(orient),
        current_position(startPos),
        previous_position(startPos),
        path(Path()),
        path_goal(VecXY_Float(-1.0,-1.0)),
        next_path_coord(VecXY_Float(-1.0,-1.0)),
        goal_reached(false),
        goal_changed_flag(false),
        attack_target(Enemy_vars()),
        attack_range(200),
        weapon_timer(Timer()),
        rate_of_fire(1000),
        bullet_count(0),
        miss_threshold(2)
{
    // -------------------------------------------------------------------------
    // Base Variables ----------------------------------------------------------
//    speed = spd;
//    rotation = rot;
//    radius = 15.0;
//    fov = 90.0; //TODO (imp#3#) Find what human FOV is, I think it's 140
//    vision_range = 400;
//    agent_ID = ID;
//    team = tm;
//    max_health = 100.0;
//    health = max_health;
//    alive = true;
//    dummy = dumb;
//    squad_ID = -1;

    // -------------------------------------------------------------------------
    // Knowledge Variables -----------------------------------------------------
//    orientation = orient;
//    current_position = startPos;
//    previous_position = startPos;
//
//    path_goal = VecXY_Float(-1.0,-1.0);
//    next_path_coord = VecXY_Float(-1.0,-1.0);
//
//    goal_changed_flag = false;
//    goal_reached = false;

    // -------------------------------------------------------------------------
    // Equipment Variables -----------------------------------------------------
//    attack_range = 200;
//    rate_of_fire = 1000;
    weapon_timer.start();
//    inventory.push_back(Item(constants::ITEM_SHOES, "Shoes", 99, 2));

    seen_enemies.reserve(10);

    engaged = false;
    bullet_pos = VecXY_Float(-1,-1);
    perception_distance = 15.0;

    search_direction = true;
    search_rotation = 0.0;

    better_target_flag = false;
    squad_support_flag = false;
}

bool AI_Info::visibleEnemiesCheck()
{
    if(seen_enemies.size() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AI_Info::orientationCheck(VecXY_Float target, float margin)
{
    bool check = false;
    float angle_to_target = utils::calculateAngle(current_position, target);
    float bound_A = angle_to_target - margin;
    float bound_B = angle_to_target + margin;
    utils::trimAngle(bound_A);
    utils::trimAngle(bound_B);

    /// if: orientation is within either side of the margin
    /// then: orientation checks out ok
    if(((orientation >= bound_A) && (orientation <= bound_A + (margin*2)))
       || ((orientation <= bound_B)&&(orientation >= bound_B-(margin*2))))
    {
        check = true;
    }

    return check;
}

bool AI_Info::validateTarget(Enemy_vars &target)
{
    unsigned int i = 0;
    bool found = false;

    while((i < seen_enemies.size()) && (found == false))
    {
        if(target.agent_ID == seen_enemies[i].agent_ID)
        {
            found = true;
        }
        i++;
    }

    return found;
}

bool AI_Info::rangeCheck(Enemy_vars &target, float margin)
{
    VecXY_Float diff = current_position - target.current_position;
    if(diff.length() <= attack_range - margin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AI_Info::deadEnemiesCheck(int id)
{
    bool found = false;
    unsigned int i = 0;

    while((i < known_dead_enemies.size()) && (found == false))
    {
        if(id == known_dead_enemies[i])
        {
            found = true;
        }
        i++;
    }

    return found;
}

bool AI_Info::searchRangeCheck(Enemy_vars &target, float margin)
{
    VecXY_Float diff = current_position - target.current_position;
    if(diff.length() <= (vision_range * 0.75) - margin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AI_Info::atPosition(VecXY_Float target, float margin)
{
    bool reached = false;
    VecXY_Float diff;
    diff = current_position - target;
    if(diff.length() <= margin)
    {
        reached = true;
    }
    return  reached;
}

Enemy_vars AI_Info::get_Targeting_Info()
{
    return Enemy_vars(current_position, orientation, team, agent_ID, health);
}

bool AI_Info::update_Current_Attack_Target()
{
    unsigned int i = 0;
    bool found = false;

    while((i < seen_enemies.size()) && (found == false))
    {
        if(attack_target.agent_ID == seen_enemies[i].agent_ID)
        {
            found = true;
            attack_target = seen_enemies[i]; // The info update.
        }
        i++;
    }

    return found;
}

void AI_Info::register_Dead_Enemy(int id)
{
    bool found = false;
    unsigned int i = 0;

    while((i < known_dead_enemies.size()) && (found == false))
    {
        if(id == known_dead_enemies[i])
        {
            found = true;
        }
        i++;
    }

    if(found == false)
    {
        known_dead_enemies.push_back(id);
    }
}

bool AI_Info::betterTargetCheck()
{
    bool better_target = false;
    bool close_target = false;
    unsigned int i = 0;
    float test_margin = 5;

    while((i < seen_enemies.size()) && (close_target == false))
    {
        if(rangeCheck(seen_enemies[i], test_margin))
        {
            close_target = true;
        }
        i++;
    }

    // IF [target out of range] AND [there is another target within range]
    if((rangeCheck(attack_target, test_margin) == false) && (close_target == true))
    {
        better_target = true;
        better_target_flag = true;
    }

    return better_target;
}
