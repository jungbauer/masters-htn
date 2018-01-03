#include "Squad.h"

Squad::Squad(int team, int ID):
        squad_team(team),
        squad_ID(ID),
        desired_pos(VecXY_Float()),
        orientation(0),
        commandPos(VecXY_Float())
{
//    squad_team = team;
//    squad_ID = ID;
//    orientation = 0;
    get_action_count = 0;
    get_support_location_count = 0;
    support_flag = false;
    commandSquad = false;
}

Squad::Squad():
        squad_team(-99),
        squad_ID(-99),
        desired_pos(VecXY_Float()),
        orientation(0),
        commandPos(VecXY_Float())
{
//    squad_team = -99;
//    squad_ID = -99;
//    orientation = 0;
    get_action_count = 0;
    get_support_location_count = 0;
    support_flag = false;
    commandSquad = false;
}

bool Squad::idleCheck() {
    bool squad_is_idle = true;
    unsigned int a = 0;

    while(squad_is_idle && (a < squad_members.size())) {
        if (squad_members[a]->info.alive && (squad_members[a]->getState() != constants::STATE_IDLE)) {
            squad_is_idle = false;
        }
        a++;
    }

    return squad_is_idle;
}

bool Squad::engagedCheck() {
    bool squadEngaged = false;
    unsigned int a = 0;

    while(!squadEngaged && (a < squad_members.size())) {
        if (squad_members[a]->info.alive && squad_members[a]->info.engaged) {
            squadEngaged = true;
        }
        a++;
    }

    return squadEngaged;
}

void Squad::listEngagedMembers() {
    for (int i = 0; i < squad_members.size(); ++i) {
        if (squad_members[i]->info.alive && squad_members[i]->info.engaged) {
            std::cout << "ai: " << i << " - " << squad_members[i]->info.squad_ID
                      << " - [" << squad_members[i]->info.current_position.getX() << "," << squad_members[i]->info.current_position.getY() << "]"
                      << " - en:" << squad_members[i]->info.seen_enemies.size()
                      << " - blt: [" << squad_members[i]->info.bullet_pos.getX() << "," << squad_members[i]->info.bullet_pos.getY() << "]" << std::endl;
        }
    }
}

bool Squad::getEngagedInfo(VecXY_Float &memberPos, VecXY_Float &lookPos) {
    bool set = false;
    int i = 0;

    //checking for seen enemies
    while (!set && i < squad_members.size()) {
        if (squad_members[i]->info.alive && squad_members[i]->info.engaged) {
            memberPos = squad_members[i]->info.current_position;
            if (!squad_members[i]->info.seen_enemies.empty()) {
                lookPos = squad_members[i]->info.seen_enemies[0].current_position;
                set = true;
            }
        }

        i++;
    }

    // if no seen enemies look to the bullet position
    if (!set) {
        int x = 0;
        while (!set && x < squad_members.size()) {
            if (squad_members[x]->info.alive && squad_members[x]->info.engaged) {
                memberPos = squad_members[x]->info.current_position;
                lookPos = squad_members[x]->info.bullet_pos;
                set = true;
            }

            x++;
        }
    }

    return set;
}

int Squad::healthyCount() {
    int count = 0;

    for (int i = 0; i < squad_members.size(); ++i) {
        if (squad_members[i]->info.alive) {
            count++;
        }
    }

    return count;
}

bool Squad::healthCheck() {
    int count = 0;

    for (int i = 0; i < squad_members.size(); ++i) {
        if (squad_members[i]->info.alive) {
            count++;
        }
    }

    return count > 1;
}

VecXY_Float Squad::getReferencePos() {
    bool set = false;
    VecXY_Float refPos = VecXY_Float(0, 0);
    int i = 0;

    //checking for seen enemies
    while (!set && i < squad_members.size()) {
        if (squad_members[i]->info.alive) {
            refPos.setX(squad_members[i]->info.current_position.getX());
            refPos.setY(squad_members[i]->info.current_position.getY());
            set = true;
        }

        i++;
    }

    return refPos;
}

void Squad::update(Graph &graph, Level &level)
{
    bool squad_is_idle = true;
    bool squadie_needs_support = false;
    unsigned int a = 0;

    //Check if squad is idle.
    a = 0;
    while((squad_is_idle == true) && (a < squad_members.size()))
    {
        if((squad_members[a]->info.alive == true) && (squad_members[a]->getState() != constants::STATE_IDLE))
        {
            squad_is_idle = false;
        }
        a++;
    }

    //Check if squadmembers need support
    a = 0;
    while((squadie_needs_support == false) && (a < squad_members.size()))
    {
        if((squad_members[a]->info.alive == true) && (squad_members[a]->info.engaged == true))
        {
            squadie_needs_support = true;
        }
        a++;
    }

    if(squad_is_idle)
    {
        if(commandSquad) {
//            assignCommandPosition();
            desired_pos.setX(commandPos.getX());
            desired_pos.setY(commandPos.getY());
            calc_Valid_Squad_Positions(level);
            assign_Positions_To_Agents();
            for(unsigned int i = 0; i < squad_members.size(); i++)
            {
                squad_members[i]->info.observePoint = observePos;
            }
        }
        else {
            // Find a new desired location.
            int goal_node = 0;
            goal_node = utils::getRandomInt(0, graph.getSize()-1);
            Node g_node = graph.getNode(goal_node);
            int x, y;
            level.getPixelPositionFromGrid(g_node.x_pos, g_node.y_pos, x, y);
            desired_pos.setX((float) x);
            desired_pos.setY((float) y);

            // Calculate valid squad positions.
            calc_Valid_Squad_Positions(level);

            // Assign positions to agents.
            assign_Positions_To_Agents();
        }
    }

    //Update squadmembers on support situation
    support_flag = squadie_needs_support;
    for(unsigned int i = 0; i < squad_members.size(); i++)
    {
        squad_members[i]->info.squad_support_flag = squadie_needs_support;
    }
}

bool Squad::active_Check()
{
    bool squad_is_active = false;
    unsigned int a = 0;

    //Check if there are live agents available.
    while((squad_is_active == false) && (a < squad_members.size()))
    {
        if(squad_members[a]->info.alive == true)
        {
            squad_is_active = true;
        }
        a++;
    }

    return squad_is_active;
}

bool Squad::get_Action(vector<Action*> &actions, int agent_ID)
{
    // Data collection
    get_action_count += 1;

    bool in_squad = false;
    bool do_nothing = true;
    bool found = false;
    unsigned int t = 0;
    unsigned int a = 0;

    // Check if agent is in the squad.
    while((in_squad == false) && (a < squad_members.size()))
    {
        if(agent_ID == squad_members[a]->info.agent_ID)
        {
            in_squad = true;
            if(squad_members[a]->info.alive == true)
            {
                // Look in tracker.
                t = 0;
                while((found == false) && (t < tracker.size()))
                {
                    if(tracker[t].agent_ID == squad_members[a]->info.agent_ID)
                    {
                        found = true;
                        // Have they reached their assigned position?
                        if(tracker[t].reached == false)
                        {
                            //check if position has been reached
                            if(squad_members[a]->info.atPosition(tracker[t].assigned_pos, 7))
                            {
                                // position reached: do nothing
                                tracker[t].reached = true;
                            }
                            else
                            {
                                //position not reached: PF to pos
                                do_nothing = false;
                                try
                                {
                                    actions.push_back(new Act_Pathfind(tracker[t].assigned_pos));
                                }
                                catch(std::bad_alloc& e)
                                {
                                    std::cerr << "Squad::get_action() bad_alloc memory error" << std::endl;
                                }
                                squad_members[a]->set_Moving_State();
                            }
                        }
                    }
                    t++;
                }
            }
        }
        a++;
    }

    if(do_nothing)
    {
        try
        {
            actions.push_back(new Act_None());
        }
        catch(std::bad_alloc& e)
        {
            std::cerr << "Squad::get_action() bad_alloc memory error" << std::endl;
        }
    }

    return in_squad;
}

void Squad::add_Agent(AI_Agent* member)
{
    squad_members.push_back(member);
    member->info.squad_ID = squad_ID;

    Agent_Track new_member;
    new_member.agent_ID = member->info.agent_ID;
    new_member.assigned_pos = VecXY_Float(-1,-1);
    new_member.reached = false;
    tracker.push_back(new_member);
}


void Squad::assign_Positions_To_Agents()
{
    // Loop through the squad members.
    for(unsigned int i = 0; i < squad_members.size(); i++)
    {
        if(squad_members[i]->info.alive == true)
        {
            // Find in tracker and assign position.
            bool found = false;
            unsigned int a = 0;
            while((found == false) && (a < tracker.size()))
            {
                if(squad_members[i]->info.agent_ID == tracker[a].agent_ID)
                {
                    found = true;

                    // Loop through valid positions and assign
                    bool assigned = false;
                    unsigned int s = 0;
                    while((assigned == false) && (s < valid_positions.size()))
                    {
                        if(valid_positions[s].assigned == false)
                        {
                            assigned = true;
                            valid_positions[s].assigned = true;
                            tracker[a].assigned_pos = valid_positions[s].position;
                            tracker[a].reached = false;
                        }
                        s++;
                    }

                    // If no pos is assigned (usually due to insufficient valid positions) assign the first valid position.
                    if(assigned == false)
                    {
                        tracker[a].assigned_pos = valid_positions[0].position;
                        tracker[a].reached = false;
                    }
                }
                a++;
            }
        }
    }
}

void Squad::assignCommandPosition()
{
    // Loop through the squad members.
    for(unsigned int i = 0; i < squad_members.size(); i++)
    {
        if(squad_members[i]->info.alive)
        {
            // Find in tracker and assign position.
            bool found = false;
            unsigned int a = 0;
            while((!found) && (a < tracker.size()))
            {
                if(squad_members[i]->info.agent_ID == tracker[a].agent_ID)
                {
                    found = true;
                    tracker[a].assigned_pos = commandPos;
                    tracker[a].reached = false;
                }
                a++;
            }
        }
    }
}

void Squad::calc_Valid_Squad_Positions(Level &level)
{
    vector<VecXY_Float> positions;
    valid_positions.clear();

    // Get all 7 positions.
    get_Squad_Positions(squad_members[0]->info.radius, positions);

    for(unsigned int i = 0; i < positions.size(); i++)
    {
        if(validate_Squad_Position(positions[i], squad_members[0]->info.radius, level))
        {
            Valid_Pos pos;
            pos.position = positions[i];
            pos.assigned = false;

            valid_positions.push_back(pos);
        }
    }
}

bool Squad::validate_Squad_Position(VecXY_Float pos, float agent_radius, Level &level)
{
    return (!level.levelCollisionCheck_Circle(pos, agent_radius));
}

bool Squad::validate_Agent(int ID)
{
    bool valid_agent = false;
    unsigned int i = 0;

    while((i < squad_members.size()) && (valid_agent == false))
    {
        if((squad_members[i]->info.agent_ID == ID) && (squad_members[i]->info.alive = true))
        {
            // Live agent found.
            valid_agent = true;
        }

        i++;
    }

    return valid_agent;
}

void Squad::get_Squad_Positions(float radius, vector<VecXY_Float> &positions)
{
    positions.clear();
    float spacing = 30.0;

    VecXY_Float support_front_1 = VecXY_Float((radius + spacing) * cos(orientation*constants::PIE/180), (radius + spacing) * sin(orientation*constants::PIE/180));
    VecXY_Float support_front_2 = VecXY_Float((radius + spacing*2) * cos(orientation*constants::PIE/180), (radius + spacing*2) * sin(orientation*constants::PIE/180));
    VecXY_Float support_rear_1 = VecXY_Float((radius + spacing) * cos((orientation - 180)*constants::PIE/180), (radius + spacing) * sin((orientation - 180)*constants::PIE/180));
    VecXY_Float support_rear_2 = VecXY_Float((radius + spacing*2) * cos((orientation - 180)*constants::PIE/180), (radius + spacing*2) * sin((orientation - 180)*constants::PIE/180));
    VecXY_Float support_rear_left = VecXY_Float((radius + spacing - 10) * cos((orientation - 135)*constants::PIE/180), (radius + spacing-10) * sin((orientation - 135)*constants::PIE/180));
    VecXY_Float support_rear_right = VecXY_Float((radius + spacing - 10) * cos((orientation - 225)*constants::PIE/180), (radius + spacing-10) * sin((orientation - 225)*constants::PIE/180));

    support_front_1 = support_front_1 + desired_pos;
    support_front_2 = support_front_2 + desired_pos;
    support_rear_1 = support_rear_1 + desired_pos;
    support_rear_2 = support_rear_2 + desired_pos;
    support_rear_left = support_rear_left + desired_pos;
    support_rear_right = support_rear_right + desired_pos;

    // Listing in order of general preference
    positions.push_back(desired_pos);
    positions.push_back(support_rear_left);
    positions.push_back(support_rear_right);
    positions.push_back(support_rear_1);
    positions.push_back(support_rear_2);
    positions.push_back(support_front_1);
    positions.push_back(support_front_2);
}

void Squad::get_Draw_Info(float &orient, VecXY_Float &desired, vector<VecXY_Float> &valid_pos)
{
    orient = orientation;
    desired = desired_pos;
    valid_pos.clear();

    for(unsigned int i = 0; i < valid_positions.size(); i++)
    {
        valid_pos.push_back(valid_positions[i].position);
    }

}

int Squad::get_Squad_Size()
{
    return squad_members.size();
}

bool Squad::get_Support_Location(int agent_ID, VecXY_Float &loc)
{
    // Data collection
    get_support_location_count += 1;

    bool location_found = false;
    unsigned int a = 0;

    while((location_found == false) && (a < squad_members.size()))
    {
        if((squad_members[a]->info.agent_ID != agent_ID) && (squad_members[a]->info.alive == true) && (squad_members[a]->info.engaged == true))
        {
            location_found = true;
            loc = squad_members[a]->info.current_position;
        }
        a++;
    }

    return location_found;
}

void Squad::get_Agent_Positions(vector<VecXY_Float> &positions)
{
    for(unsigned int i = 0; i < squad_members.size(); i++)
    {
        if(squad_members[i]->info.alive == true)
        {
            positions.push_back(squad_members[i]->info.current_position);
        }
    }
}

void Squad::get_Seen_Enemies(vector<VecXY_Float> &positions)
{
    bool found = false;
    unsigned int p = 0;
    for(unsigned int i = 0; i < squad_members.size(); i++)
    {
        if(squad_members[i]->info.alive == true)
        {
            // Run through seen enemies and add them if they are not already in list.
            for(unsigned int en = 0; en < squad_members[i]->info.seen_enemies.size(); en++)
            {
                found = false;
                p = 0;
                while((p < positions.size()) && (found == false))
                {
                    if(positions[p] == squad_members[i]->info.seen_enemies[en].current_position)
                    {
                        found = true;
                    }
                    p++;
                }

                if(found == false)
                {
                    positions.push_back(squad_members[i]->info.seen_enemies[en].current_position);
                }
            }
        }
    }
}

//void AI_Info::calc_Support_Positions(VecXY_Float position, float orient, float rad, vector<VecXY_Float> &positions)
//{
//    positions.clear();
//    float spacing = 30.0;
//
//    VecXY_Float support_front_1 = VecXY_Float((rad + spacing) * cos(orient*constants::PIE/180), (rad + spacing) * sin(orient*constants::PIE/180));
//    VecXY_Float support_front_2 = VecXY_Float((rad + spacing*2) * cos(orient*constants::PIE/180), (rad + spacing*2) * sin(orient*constants::PIE/180));
//    VecXY_Float support_rear_1 = VecXY_Float((rad + spacing) * cos((orient - 180)*constants::PIE/180), (rad + spacing) * sin((orient - 180)*constants::PIE/180));
//    VecXY_Float support_rear_2 = VecXY_Float((rad + spacing*2) * cos((orient - 180)*constants::PIE/180), (rad + spacing*2) * sin((orient - 180)*constants::PIE/180));
//    VecXY_Float support_rear_left = VecXY_Float((rad + spacing - 10) * cos((orient - 135)*constants::PIE/180), (rad + spacing-10) * sin((orient - 135)*constants::PIE/180));
//    VecXY_Float support_rear_right = VecXY_Float((rad + spacing - 10) * cos((orient - 225)*constants::PIE/180), (rad + spacing-10) * sin((orient - 225)*constants::PIE/180));
//
//    support_front_1 = support_front_1 + position;
//    support_front_2 = support_front_2 + position;
//    support_rear_1 = support_rear_1 + position;
//    support_rear_2 = support_rear_2 + position;
//    support_rear_left = support_rear_left + position;
//    support_rear_right = support_rear_right + position;
//
//    // Listing in order of general preference
//    positions.push_back(support_rear_left);
//    positions.push_back(support_rear_right);
//    positions.push_back(support_rear_1);
//    positions.push_back(support_rear_2);
//    positions.push_back(support_front_1);
//    positions.push_back(support_front_2);
//}
