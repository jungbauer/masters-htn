#include "Action_Handler.h"

Action_Handler::Action_Handler()
{}

void Action_Handler::doAction(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level, unsigned int deltaTicks, vector<Bullet> &bullets, vector<Location*> &locations, vector<Squad> &squads)
{
    switch(action->action_type)
    {
        case constants::ACT_NONE:
        {
            actNone();
        }
        break;

        case constants::ACT_FOLLOW_PATH:
        {
            actFollowPath(agent, level, deltaTicks);
        }
        break;

        case constants::ACT_FOLLOW_PATH_ORIENT:
        {
            actFollowPathOrient(agent, level, deltaTicks);
        }
        break;

        case constants::ACT_RAND_PATHFIND:
        {
            actRandomPathfind(agent, pathFinder, graph, level);
        }
        break;

        case constants::ACT_PATHFIND:
        {
            actPathfind(action, agent, pathFinder, graph, level);
        }
        break;

        case constants::ACT_CHOOSE_TARGET:
        {
            actChooseTarget(agent);
        }
        break;

        case constants::ACT_ORIENT:
        {
            actOrient(agent, deltaTicks);
        }
        break;

        case constants::ACT_FIRE:
        {
            actFire(agent, bullets);
        }
        break;

        case constants::ACT_TAKE_ITEM: //TODO (imp#3#) Not used at all. Should be removed at some point.
        {
            actTakeItem(action, agent, locations);
        }
        break;


        case constants::ACT_PLACE_ITEM: //TODO (imp#3#) Not used at all. Should be removed at some point.
        {
            actPlaceItem(action, agent, locations);
        }
        break;

        case constants::ACT_SUPPORT_PATHFIND: //TODO (imp#3#) Not used at all. Should be removed at some point.
        {
            actSupportPathfind(action, agent, pathFinder, graph, level);
        }
        break;

        case constants::ACT_QUERY_SQUAD:
        {
            actQuerySquad(agent, squads);
        }
        break;

        case constants::ACT_RESET_ENGAGED:
        {
            actResetEngaged(agent);
        }
        break;

        case constants::ACT_SET_ENGAGED:
        {
            actSetEngaged(agent);
        }
        break;

        case constants::ACT_SCAN:
        {
            actScan(agent, deltaTicks);
        }
        break;

        case constants::ACT_SETUP_SEARCH:
        {
            actSetupSearch(agent);
        }
        break;

        case constants::ACT_SPOT_SEARCH:
        {
            actSpotSearch(agent, deltaTicks);
        }
        break;

        case constants::ACT_TARGET_FLAGGED:
        {
            actTargetFlagged(agent);
        }
        break;

        case constants::ACT_CHOOSE_TARGET_V2:
        {
            actChooseTargetV2(agent);
        }
        break;

        case constants::ACT_SET_SUPPORT_LOCATION:
        {
            actSetSupportLocation(agent, squads, pathFinder, graph, level);
        }
        break;

// Default explicitly excluded to make sure all actions are covered.
//        default:
//        {
//            actNone();
//        }
    }
}

void Action_Handler::actQuerySquad(AI_Agent &agent, vector<Squad> &squads)
{
    unsigned int s = 0;
    bool squad_found = false;

    while((squad_found == false) && (s < squads.size()))
    {
        if(agent.info.squad_ID == squads[s].squad_ID)
        {
            squad_found = true;
            if(squads[s].get_Action(agent.action_list, agent.info.agent_ID) == false)
            {
                //TODO (gen#3#) agent not in squad... find better way to utilise this.
            }
        }
        s++;
    }
}

void Action_Handler::actTakeItem(Action *action, AI_Agent &agent, vector<Location*> &locations)
{
    // am i at the right place
    // search current agent position vs locations
    // -- if found
    //    check loc id in action with the location the agent is in
    //    -- if confirmed
    //       search for item in location inventory
    //       confirm type
    //       confirm name
    //       confirm ID
    //       confirm quantity
    //       -- if matched
    //          edit location inv and add item to agent inventory

    unsigned int i = 0, j = 0;
    bool match = false;
    bool item_found = false;

    while((i < locations.size()) && (match == false))
    {
        if(utils::check_Point_Within_Box(locations[i]->get_box(), agent.info.current_position) == true)
        {
            Act_Take_Item *act = (Act_Take_Item *) action;
            if(locations[i]->get_ID() == act->location_ID)
            {
                while((j < locations[i]->items.size()) && (item_found == false))
                {
                    if((locations[i]->items[j].item_type == act->item.item_type)
                       && (locations[i]->items[j].item_name == act->item.item_name)
                       && (locations[i]->items[j].item_ID == act->item.item_ID)
                       && (locations[i]->items[j].item_quantity >= act->item.item_quantity))
                    {
                        locations[i]->items[j].item_quantity = locations[i]->items[j].item_quantity - act->item.item_quantity;
                        agent.info.inventory.push_back(act->item);//TODO (imp#3#) need a method for adding and removing items.
                        match = true;
                        item_found = true;
                    }
                    j++;
                }
            }
        }
        i++;
    }
}

void Action_Handler::actPlaceItem(Action *action, AI_Agent &agent, vector<Location*> &locations)
{
    unsigned int i = 0, j = 0;
    bool match = false;
    bool item_found = false;

    while((i < locations.size()) && (match == false))
    {
        if(utils::check_Point_Within_Box(locations[i]->get_box(), agent.info.current_position) == true)
        {
            Act_Place_Item *act = (Act_Place_Item *) action;
            if(locations[i]->get_ID() == act->location_ID)
            {
                while((j < agent.info.inventory.size()) && (item_found == false))
                {
                    if((agent.info.inventory[j].item_type == act->item.item_type)
                       && (agent.info.inventory[j].item_name == act->item.item_name)
                       && (agent.info.inventory[j].item_ID == act->item.item_ID)
                       && (agent.info.inventory[j].item_quantity >= act->item.item_quantity))
                    {
                        agent.info.inventory[j].item_quantity = agent.info.inventory[j].item_quantity - act->item.item_quantity;
                        locations[i]->items.push_back(act->item); //TODO (imp#3#) need a method for adding and removing items.
                        match = true;
                        item_found = true;
                    }
                    j++;
                }
            }
        }
        i++;
    }
}

void Action_Handler::actChooseTarget(AI_Agent &agent)
{
    Enemy_vars closest_target;
    bool target_still_seen = false;

    //IF: assigned target is not seen
    //THEN: choose closest enemy as target

    // checking for seen target
    target_still_seen = agent.info.update_Current_Attack_Target();

    // choosing closest target
    if((agent.info.visibleEnemiesCheck()) && (target_still_seen == false))
    {
        closest_target = agent.info.seen_enemies[0];
        for(unsigned int i = 1; i < agent.info.seen_enemies.size(); i++)
        {
            if((agent.info.current_position - agent.info.seen_enemies[i].current_position).length() < (agent.info.current_position - closest_target.current_position).length())
            {
                closest_target = agent.info.seen_enemies[i];
            }
        }

        agent.info.attack_target = closest_target;
    }
}

void Action_Handler::actOrient(AI_Agent &agent, unsigned int deltaTicks)
{
    agent.orientateTowardsTarget(agent.info.attack_target.current_position, deltaTicks);
}

void Action_Handler::actRandomPathfind(AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level)
{
    int goal_node = 0;
    Path path;

    goal_node = utils::getRandomInt(0, graph.getSize()-1); // FUCK YOU minus one!!!! To hell!!!! I want my week back! *sob*

    if(pathFinder.pathFind(level, graph, agent.info.current_position.getX(), agent.info.current_position.getY(), goal_node, path) == true)
    {
        path.cullPath(graph, level);
        agent.setAIPath(path);
    }
}

void Action_Handler::actPathfind(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level)
{
    Path path;
    Act_Pathfind *act = (Act_Pathfind *) action;

    if(pathFinder.pathFind(level, graph, agent.info.current_position.getX(), agent.info.current_position.getY(), act->target.getX(), act->target.getY(), path) == true)
    {
        path.cullPath(graph, level);
        agent.setAIPath(path);
    }
}

void Action_Handler::actNone()
{
}

void Action_Handler::actFollowPath(AI_Agent &agent, Level &level, unsigned int deltaTicks)
{
    agent.move(deltaTicks, level);
}

void Action_Handler::actFollowPathOrient(AI_Agent &agent, Level &level, unsigned int deltaTicks)
{
    agent.moveOrientate(deltaTicks, level);
}

void Action_Handler::actFire(AI_Agent &agent, vector<Bullet> &bullets)
{
    if(agent.info.weapon_timer.get_ticks() > agent.info.rate_of_fire)
    {
        bullets.push_back(Bullet(agent.info.current_position, agent.info.orientation, agent.info.team, agent.info.agent_ID, agent.info.bullet_count));
        agent.info.bullet_count++;
        agent.info.weapon_timer.start();
    }
}

void Action_Handler::actSupportPathfind(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level)
{
    Path path;
    VecXY_Float support_pos = VecXY_Float(100, 100);

    // TODO (gen#3#) Implement support pos choice.

    // IF direct line to support_pos
    // THEN create 1 point path
    // ELSE do normal pathfind
    if(level.walkable(agent.info.current_position, support_pos))
    {
        path._culled_path.push_back(Coord((int)support_pos.getX(), (int)support_pos.getY()));
        agent.setAIPath(path);
    }
    else
    {
        if(pathFinder.pathFind(level, graph, agent.info.current_position.getX(), agent.info.current_position.getY(), support_pos.getX(), support_pos.getY(), path) == true)
        {
            path.cullPath(graph, level);
            agent.setAIPath(path);
        }
    }
}

void Action_Handler::actResetEngaged(AI_Agent &agent)
{
    agent.info.engaged = false;
}

void Action_Handler::actSetEngaged(AI_Agent &agent)
{
    agent.info.engaged = true;
}

void Action_Handler::actScan(AI_Agent &agent, unsigned int deltaTicks)
{
    agent.orientateTowardsTarget(agent.info.bullet_pos, deltaTicks);
}

void Action_Handler::actSetupSearch(AI_Agent &agent)
{
    // Sets the search variables.
    // Chooses a random direction to rotate in during the search. left or right.
    int dir = utils::getRandomInt(0, 1);

    if(dir == 1)
    {
        agent.info.search_direction = true;
    }
    else
    {
        agent.info.search_direction = false;
    }

    // Resets the variable that tracks how much the agent has turned.
    agent.info.search_rotation = 0.0;

}

void Action_Handler::actSpotSearch(AI_Agent &agent, unsigned int deltaTicks)
{
    agent.info.search_rotation += agent.rotateAgent(agent.info.search_direction, deltaTicks);
}

void Action_Handler::actChooseTargetV2(AI_Agent &agent)
{
    Enemy_vars closest_target;

    // choosing closest target
    if(agent.info.visibleEnemiesCheck())
    {
        closest_target = agent.info.seen_enemies[0];
        for(unsigned int i = 1; i < agent.info.seen_enemies.size(); i++)
        {
            if((agent.info.current_position - agent.info.seen_enemies[i].current_position).length() < (agent.info.current_position - closest_target.current_position).length())
            {
                closest_target = agent.info.seen_enemies[i];
            }
        }

        agent.info.attack_target = closest_target;
    }
}

void Action_Handler::actTargetFlagged(AI_Agent &agent)
{
    if(agent.info.better_target_flag)
    {
        agent.info.better_target_flag = false;
        actChooseTargetV2(agent);
    }
}

void Action_Handler::actSetSupportLocation(AI_Agent &agent, vector<Squad> &squads, PathFinding &pathFinder, Graph &graph, Level &level)
{
    unsigned int s = 0;
    bool squad_found = false;
    Path path;
    VecXY_Float support_location;
    bool location_found = false;

    // Get location from squad.
    while((squad_found == false) && (s < squads.size()))
    {
        if(agent.info.squad_ID == squads[s].squad_ID)
        {
            squad_found = true;
            location_found = squads[s].get_Support_Location(agent.info.agent_ID, support_location);
        }
        s++;
    }


    // Pathfind to the location obtained from squad.
    if(location_found)
    {
        if(pathFinder.pathFind(level, graph, agent.info.current_position.getX(), agent.info.current_position.getY(), (int)support_location.getX(), (int)support_location.getY(), path) == true)
        {
            path.cullPath(graph, level);
            agent.setAIPath(path);
        }
    }
}
