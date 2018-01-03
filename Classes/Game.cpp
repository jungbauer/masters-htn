#include "Game.h"

Game::Game(Game_Configuration config):
        level(Level(config.map_name)),
        graph(Graph()),
        game_timer(Timer()),
        score_team1(0),
        score_team2(0),
        act_handler(Action_Handler()),
        path_finder(PathFinding()),
        first_call(false),
        game_finished(false),
        game_time_limit(config.time_limit),
        game_score_limit(config.score_limit)
{
//    level = Level(config.map_name);
    graph.generateGraph(level);

//    first_call = false;
//    game_finished = false;
//    game_time_limit = config.time_limit;
//    game_score_limit = config.score_limit;
//TODO (imp#3#) Score limit is not yet tested for or used, neither is respawn time.
//    score_team1 = 0;
//    score_team2 = 0;

    /// setting up AI agents ------------------------
    ai_agents.reserve(config.T1_agent_total + config.T2_agent_total);
//    manual_Agent_Setup();
    add_Agents(1, config.T1_AI_type, config.T1_agent_total, config.T1_squad_size, level.team1_spawn, level.team1_orientation, false);
    add_Agents(2, config.T2_AI_type, config.T2_agent_total, config.T2_squad_size, level.team2_spawn, level.team2_orientation, false);

    /// setting up previous tick vector
    previous_tick.reserve(ai_agents.size());
    for(unsigned int i = 0; i < ai_agents.size(); i++)
    {
        Agent_Status ai_stat;
        ai_stat.agent_ID = ai_agents[i]->info.agent_ID;
        ai_stat.alive = ai_agents[i]->info.alive;

        previous_tick.push_back(ai_stat);
    }

    // Shrinking squad vector to size.
    if(squads.size() > 0)
    {
        std::vector<Squad>(squads.begin(),squads.end()).swap(squads);
    }

    if(config.T1_AI_type == constants::FSM_CMD_HTN) { commanders.push_back(Commander(1, 0)); }
    if(config.T2_AI_type == constants::FSM_CMD_HTN) { commanders.push_back(Commander(2, 1)); }

//    commanders.push_back(Commander(1, 0));
//    commanders.push_back(Commander(2, 1));
    for(unsigned int i = 0; i < squads.size(); i++)
    {
        if(squads[i].commandSquad) {
            for (int j = 0; j < commanders.size(); ++j) {
                if(squads[i].squad_team == commanders[j].commander_team) {
                    commanders[j].add_Squad(&squads[i]);
                }
            }
        }

//        if(squads[i].squad_team == 1)
//        {
//            commanders[0].add_Squad(&squads[i]);
//        }
//        else
//        {
//            commanders[1].add_Squad(&squads[i]);
//        }
    }

    /// Influence map setup
    for (int j = 0; j < commanders.size(); ++j) {
        commanders[j].influence.set_Height(level.get_height_in_tiles_());
        commanders[j].influence.set_Width(level.get_width_in_tiles_());
        commanders[j].influence.setupInfluenceMaps();
    }

//    commanders[0].influence.set_Height(level.get_height_in_tiles_());
//    commanders[1].influence.set_Height(level.get_height_in_tiles_());
//    commanders[0].influence.set_Width(level.get_width_in_tiles_());
//    commanders[1].influence.set_Width(level.get_width_in_tiles_());
//    commanders[0].influence.setupInfluenceMaps();
//    commanders[1].influence.setupInfluenceMaps();
}

Game::~Game()
{
    //std::cerr << "Game destrutor!!!!" << std::endl;

    // Clearing vector of AI_Agent pointers
    for(unsigned int i = 0; i < ai_agents.size(); i++)
    {
        delete ai_agents[i];
    }
    ai_agents.clear();

    // Clearing vector of Locations
//    for(unsigned int i = 0; i < locations.size(); i++)
//    {
//        delete locations[i];
//    }
//    locations.clear();
}

//Game::Game(const Game& that)
//{
//    std::cerr << "Game Copy constructor!!!!" << std::endl;
//}
//
//Game& Game::operator=(const Game& that)
//{
//    std::cerr << "Game assignment operator!!!!" << std::endl;
//}

bool Game::run_Game_Logic(unsigned int delta_ticks)
{
//    LOG(FILE_LOG(logDEBUG) << "Game::run_Game_Logic() -> begin";);

    if(game_finished == false)
    {
        if(first_call == false)
        {
            first_call = true;
            calc_Crude_Visibility();
            game_timer.start();
        }

//        vector<VecXY_Float> teamOnePositions;
//        vector<VecXY_Float> teamTwoPositions;
//
//        for(unsigned int i = 0; i < ai_agents.size(); i++) {
//            if(ai_agents[i]->info.team == 1 && ai_agents[i]->info.alive) {
//                teamOnePositions.push_back(ai_agents[i]->info.current_position);
//            }
//
//            if(ai_agents[i]->info.team == 2 && ai_agents[i]->info.alive) {
//                teamTwoPositions.push_back(ai_agents[i]->info.current_position);
//            }
//        }
//
//        commanders[0].calc_Influence(level, crude_visibility, teamTwoPositions);
//        commanders[1].calc_Influence(level, crude_visibility, teamOnePositions);

        commanderLogic();
        //Location_Logic(delta_ticks);
        Squad_Logic(delta_ticks);
        Agent_Logic(delta_ticks);
        Bullet_Logic(delta_ticks);

        finished_Check();
    }

    if(game_finished == true)
    {
        LOG(FILE_LOG(logDEBUG2) << "Squad Call Dump";);
        // dump squad call info to debug file
        for(unsigned int i =0; i < squads.size(); i++)
        {
            LOG(FILE_LOG(logDEBUG2) << "SCD_# " <<squads[i].squad_team << "," << squads[i].squad_ID << "," << squads[i].get_action_count << "," << squads[i].get_support_location_count;);
        }
    }

//    LOG(FILE_LOG(logDEBUG) << "Game::run_Game_Logic() -> end";);

    return game_finished;
}

void Game::finished_Check()
{
//    LOG(FILE_LOG(logDEBUG3) << "Game::finished_Check() -> begin";);

    // One or more teams are dead. -------------------------------------
    // Is team 1 all dead?
    bool team1_dead = true;
    unsigned int a = 0;
    while((team1_dead == true) && (a < ai_agents.size()))
    {
        if((ai_agents[a]->info.team == 1) && (ai_agents[a]->info.alive == true))
        {
            // There is at least 1 alive agent
            team1_dead = false;
        }
        a++;
    }

    // Is team 2 all dead?
    bool team2_dead = true;
    a = 0;
    while((team2_dead == true) && (a < ai_agents.size()))
    {
        if((ai_agents[a]->info.team == 2) && (ai_agents[a]->info.alive == true))
        {
            // There is at least 1 alive agent
            team2_dead = false;
        }
        a++;
    }

    // Checking the time limit -----------------------------------------
    if(game_timer.get_ticks() >= game_time_limit)
    {
        game_finished = true;
        game_timer.pause();
    }

    if((team1_dead == true) || (team2_dead == true))
    {
        game_finished = true;
        game_timer.pause();
    }

    // Tracking the score. -------------------------------------------
    bool found = false;
    unsigned int l = 0;
    for(unsigned int i = 0; i < previous_tick.size(); i++)
    {
        found = false;
        l = 0;
        while((found == false) && (l < ai_agents.size()))
        {
            if(previous_tick[i].agent_ID == ai_agents[l]->info.agent_ID)
            {
                found = true;
                // Check for change in status
                if((previous_tick[i].alive == true) && (ai_agents[l]->info.alive) == false)
                {
                    Death_Info deadAgent;
                    deadAgent.timeOfDeath = game_timer.get_ticks();
                    deadAgent.botTeam = ai_agents[l]->info.team;
                    deadAgent.xPos = ai_agents[l]->info.current_position.getX();
                    deadAgent.yPos = ai_agents[l]->info.current_position.getY();

                    death_information.push_back(deadAgent);

                    std::string botInfo = "time: ";
                    botInfo += std::to_string(deadAgent.timeOfDeath);
                    botInfo += ", team: ";
                    botInfo += std::to_string(deadAgent.botTeam);
                    botInfo += ", xpos: ";
                    botInfo += std::to_string(deadAgent.xPos);
                    botInfo += ", ypos: ";
                    botInfo += std::to_string(deadAgent.yPos);

                    LOG(FILE_LOG(logDEBUG3) << "Dead agent time: " + botInfo);

                    // agent died this tick. Score a point for the opposing team.
                    if(ai_agents[l]->info.team == 1)
                    {
                        score_team2 += 1;
                    }
                    else
                    {
                        score_team1 += 1;
                    }
                }
                // Store for next tick check.
                previous_tick[i].alive = ai_agents[l]->info.alive;
            }
            l++;
        }
    }
//    LOG(FILE_LOG(logDEBUG3) << "Game::finished_Check() -> end";);
}

void Game::Agent_Logic(unsigned int delta_ticks)
{
    for(unsigned int i = 0; i < ai_agents.size(); i++)
    {
        if(ai_agents[i]->info.alive == true)
        {
            // AI perception
            if(ai_agents[i]->info.dummy == false)
            {
                enemyPerceptionCheck(*ai_agents[i], ai_agents, level);
            }

            //AI Actions
            /// Get AI Actions
            ai_agents[i]->update(AI_action);

            /// Perform AI action
            if(!ai_agents[i]->info.dummy) { act_handler.doAction(AI_action, *ai_agents[i], path_finder, graph, level, delta_ticks, bullets, locations, squads);}

            /// Flag action as done - method then checks to see if should be repeated or not
            ai_agents[i]->pop_action();
        }
    }
}

void Game::Bullet_Logic(unsigned int delta_ticks)
{
//    LOG(FILE_LOG(logDEBUG3) << "Game::Bullet_Logic() -> begin";);

    /// move bullets
    vector<Bullet>::iterator itBullets;
    bool bullet_erased = false;
    for(itBullets = bullets.begin(); itBullets != bullets.end(); itBullets++)
    {
        bullet_erased = false;
        VecXY_Float pos = (*itBullets).getNextPosition(delta_ticks);
        (*itBullets).set_Position(pos);
        VecXY_Float collison_obj_pos(-1,-1);

        /// check bullet vs world collisions
        if(level.levelCollisionCheck_Circle((*itBullets).get_Position(), (*itBullets).get_Radius(), collison_obj_pos))
        {
            ai_agents[(*itBullets).get_Agent_ID()]->register_Bullet_Miss((*itBullets).get_Bullet_ID(), collison_obj_pos);
            /// remove bullet
            bullets.erase(itBullets);
            itBullets--;
            bullet_erased = true;
        }

        /// check bullet vs AI colisions
        if(bullet_erased == false)
        {
            /// loop agents
            unsigned int i = 0;
            while((i < ai_agents.size()) && (bullet_erased == false))
            {
                if(ai_agents[i]->info.alive == true)
                {
                    if(bulletAgentCollision((*itBullets), ai_agents[i]))
                    {
                        /// apply damage
                        ai_agents[i]->registerDamage((*itBullets).get_Damage(), (*itBullets).get_Position());

                        /// remove bullet
                        bullets.erase(itBullets);
                        itBullets--;
                        bullet_erased = true;
                    }
                }
                i++;
            }
        }
    }
//    LOG(FILE_LOG(logDEBUG3) << "Game::Bullet_Logic() -> end";);
}

void Game::Location_Logic(unsigned int delta_ticks)
{
//    bool night = night_Time_Check();
//
//    for(unsigned int l = 0; l < locations.size(); l++)
//    {
//        locations[l]->tick_Logic(night, delta_ticks);
//    }
}

void Game::Squad_Logic(unsigned int delta_ticks)
{
//    LOG(FILE_LOG(logDEBUG3) << "Game::Squad_Logic() -> begin";);

    for(unsigned int i = 0; i < squads.size(); i++)
    {
        if(squads[i].active_Check())
        {
            squads[i].update(graph, level);
        }
    }

//    LOG(FILE_LOG(logDEBUG3) << "Game::Squad_Logic() -> end";);
}

bool Game::bulletAgentCollision(Bullet &bullet, AI_Agent* agent)
{
    bool hit = false;

    if(bullet.get_Team() != agent->info.team)
    {
        hit = utils::sphere_Sphere_SweepTest(bullet.get_Radius(), bullet.get_Previous_position(), bullet.get_Position(), agent->info.radius, agent->info.previous_position, agent->info.current_position);
    }

    return hit;
}

void Game::commanderLogic() {
    vector<VecXY_Float> teamOnePositions;
    vector<VecXY_Float> teamTwoPositions;

    for(unsigned int i = 0; i < ai_agents.size(); i++) {
        if(ai_agents[i]->info.team == 1 && ai_agents[i]->info.alive) {
            teamOnePositions.push_back(ai_agents[i]->info.current_position);
        }

        if(ai_agents[i]->info.team == 2 && ai_agents[i]->info.alive) {
            teamTwoPositions.push_back(ai_agents[i]->info.current_position);
        }
    }

    for (int j = 0; j < commanders.size(); ++j) {
        if(commanders[j].commander_team == 1){
            commanders[j].calc_Influence(level, crude_visibility, teamTwoPositions);
        }
        else {
            commanders[j].calc_Influence(level, crude_visibility, teamOnePositions);
        }

        commanders[j].update();
    }
}

void Game::enemyPerceptionCheck(AI_Agent& agent, std::vector<AI_Agent*>& all_agents, Level& level)
{
    std::vector<Enemy_vars> seen_enemies;
    VecXY_Float difference;
    float angle = -1, bound_A = 0.0, bound_B = 0.0;

    for(unsigned int i = 0; i < all_agents.size(); i++)
    {
        //TODO (repetative#9#) This section does a lot of calculations that it doesnt have to.

        // Registering seen LIVE enemies.
        if((all_agents[i]->info.alive == true) && (all_agents[i]->info.team != agent.info.team) && (all_agents[i]->info.agent_ID != agent.info.agent_ID))
        {
            // check if within view distance
            difference = agent.info.current_position - all_agents[i]->info.current_position;
            if(difference.length() <= agent.info.vision_range)
            {
                // check if within FOV
                angle = utils::calculateAngle(agent.info.current_position, all_agents[i]->info.current_position);
                bound_A = agent.info.orientation - (agent.info.fov/2);
                bound_B = agent.info.orientation + (agent.info.fov/2);
                utils::trimAngle(bound_A);
                utils::trimAngle(bound_B);

                if(((angle >= bound_A) && (angle <= bound_A + agent.info.fov)) || ((angle <= bound_B)&&(angle >= bound_B-agent.info.fov)))
                {
                    // check if not behind obstacles....
                    if(checkLOS(agent.info.current_position.getX(), agent.info.current_position.getY(), all_agents[i]->info.current_position.getX(), all_agents[i]->info.current_position.getY(), level))
                    {
                        //seen_enemies.push_back(Enemy_vars(all_agents[i]->info.current_position, all_agents[i]->info.orientation, all_agents[i]->info.team, all_agents[i]->info.agent_ID, all_agents[i]->info.health));
                        seen_enemies.push_back(all_agents[i]->info.get_Targeting_Info());
                    }
                }
            }
        }

        // Registering seen dead enemies.
        if((all_agents[i]->info.alive == false) && (all_agents[i]->info.team != agent.info.team) && (all_agents[i]->info.agent_ID != agent.info.agent_ID))
        {
            // check if within view distance
            difference = agent.info.current_position - all_agents[i]->info.current_position;
            if(difference.length() <= agent.info.vision_range)
            {
                // check if within FOV
                angle = utils::calculateAngle(agent.info.current_position, all_agents[i]->info.current_position);
                bound_A = agent.info.orientation - (agent.info.fov/2);
                bound_B = agent.info.orientation + (agent.info.fov/2);
                utils::trimAngle(bound_A);
                utils::trimAngle(bound_B);

                if(((angle >= bound_A) && (angle <= bound_A + agent.info.fov)) || ((angle <= bound_B)&&(angle >= bound_B-agent.info.fov)))
                {
                    // check if not behind obstacles....
                    if(checkLOS(agent.info.current_position.getX(), agent.info.current_position.getY(), all_agents[i]->info.current_position.getX(), all_agents[i]->info.current_position.getY(), level))
                    {
                        agent.info.register_Dead_Enemy(all_agents[i]->info.agent_ID);
                    }
                }
            }
        }
    }

    agent.info.seen_enemies = seen_enemies;
    agent.info.update_Current_Attack_Target();
}

/// checks LOS
bool Game::checkLOS(int x1, int y1, int x2, int y2, Level& level)
{
    /// from http://playtechs.blogspot.com/2007/03/raytracing-on-grid.html
    //cerr << "Game.checkLOS()" << endl;
    bool LOS = true;
    int gx1 = -1, gy1 = -1, gx2 = -1, gy2 = -1;

    if ((level.getGridPositionFromPixels(x1,y1,gx1, gy1)) && (level.getGridPositionFromPixels(x2,y2,gx2, gy2)))
    {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int x = x1;
        int y = y1;
        int n = 1 + dx + dy;
        int x_inc = (x2 > x1) ? 1 : -1;
        int y_inc = (y2 > y1) ? 1 : -1;
        int error = dx - dy;
        dx *= 2;
        dy *= 2;

        Tile check_tile;
        Box tile_box;
        level.get_tile(gx1, gy1, check_tile);
        tile_box = check_tile.get_box();

        while((LOS != false) && (n > 0))
        {
            // check if tile is an obstacle
            if(check_tile.get_type() == constants::ENUM_HIGH_WALL)
            {
                // LOS is blocked
                LOS = false;
            }
            else
            {
                // check if x&y are within bounds of the current tile
                if((x >= tile_box.get_x()) && (x < tile_box.get_x() + tile_box.get_w()) && (y >= tile_box.get_y()) && (y < tile_box.get_y() + tile_box.get_h()))
                {
                    // within bounds thus continue
                    // step to next pixel
                    if (error > 0)
                    {
                        x += x_inc;
                        error -= dy;
                    }
                    else
                    {
                        y += y_inc;
                        error += dx;
                    }

                    //pixelRGBA(mapView, x, y, 255,255,255,255);

                    n--;
                }
                else
                {
                    // get new tile
                    if(level.getGridPositionFromPixels(x,y,gx1, gy1))
                    {
                        // if not get new tile
                        if(level.get_tile(gx1, gy1, check_tile) == false)
                        {
                            LOS = false;
                            break;
                        }
                        else
                        {
                            tile_box = check_tile.get_box();
                        }
                    }
                    else
                    {
                        LOS = false;
                        break;
                    }

                }
            }
        }
    }

    return LOS;
}

Score Game::get_Game_Score()
{
    Score current;
    current.team_1_score = score_team1;
    current.team_2_score = score_team2;
    current.game_time = game_timer.get_ticks();

    return current;
}

void Game::manual_Agent_Setup()
{
//    float orientation = 0.0;
//    float speed = 100.0;
    float rotation = 90.0;
    //bool dumb = true;

    // Vision range for the agents is 400 pixels.
    // Attack range for the agents is 200 pixels.

    // team 1
    ai_agents.push_back(new AI_Agent(constants::FSM_SQUAD_V5, VecXY_Float(380, 340), 0, 100, rotation, 1, 0, false));
    ai_agents.push_back(new AI_Agent(constants::FSM_SQUAD_V5, VecXY_Float(100, 330), 0, 100, rotation, 1, 1, false));
    ai_agents.push_back(new AI_Agent(constants::FSM_SQUAD_V5, VecXY_Float(60, 160), 0, 10, rotation, 1, 2, false));
//    ai_agents.push_back(new AI_Agent(constants::FSM_SQUAD_V1, VecXY_Float(100, 70), orientation, speed, rotation, 1, 4, false));
//    ai_agents.push_back(new AI_Agent(VecXY_Float(140, 70), orientation, speed, rotation, 1, 5, false));
//    ai_agents.push_back(new AI_Agent(VecXY_Float(180, 70), orientation, speed, rotation, 1, 6, false));

    // team 2
//    ai_agents.push_back(new AI_Agent(constants::FSM_DEFAULT, VecXY_Float(500, 330), 0, 100, rotation, 2, 6, false));
    ai_agents.push_back(new AI_Agent(constants::FSM_DEFAULT, VecXY_Float(20, 20), 180, 0, rotation, 2, 3, false));
//    ai_agents.push_back(new AI_Agent(constants::FSM_DEFAULT, VecXY_Float(500, 330), 180, 100, rotation, 2, 8, false));
//    ai_agents.push_back(new AI_Agent(VecXY_Float(500, 80), orientation, speed, rotation, 2, 10, false, false));
//    ai_agents.push_back(new AI_Agent(VecXY_Float(540, 80), orientation, speed, rotation, 2, 11, false, false));
//    ai_agents.push_back(new AI_Agent(VecXY_Float(580, 80), orientation, speed, rotation, 2, 12, false, false));

    // Squad setup
    squads.push_back(Squad(1, 1));
    squads[0].add_Agent(ai_agents[0]);
    squads[0].add_Agent(ai_agents[1]);
    squads[0].add_Agent(ai_agents[2]);
//
//    squads.push_back(Squad(2, 2));
//    squads[1].add_Agent(ai_agents[3]);
//    squads[1].add_Agent(ai_agents[4]);
//    squads[1].add_Agent(ai_agents[5]);

//    squads.push_back(Squad(2, 3));
//    squads[2].add_Agent(ai_agents[6]);
//    squads[2].add_Agent(ai_agents[7]);
//    squads[2].add_Agent(ai_agents[8]);
}

void Game::add_Agents(int team, constants::StateMachines agent_type, int total, int squad_size, VecXY_Float pos, float orientation, bool dumb)
{
//    LOG(FILE_LOG(logDEBUG) << "Game::add_Agents() -> begin";);
    float speed = 100.0;
    float rotation = 90.0;

    int offset = ai_agents.size();
    int agent_id = 0;

    for(int i = 0; i < total; i++)
    {
        agent_id = offset+i; // ID is also position in agent vector.
        try
        {
            ai_agents.push_back(new AI_Agent(agent_type, pos, orientation, speed, rotation, team, agent_id, dumb));
        }
        catch(std::bad_alloc& e)
        {
            std::cerr << "Game::add_Agents() bad_alloc memory error" << std::endl;
        }

        // SQUAD SETUP
        if((agent_type == constants::FSM_SQUAD_V1) || (agent_type == constants::FSM_SQUAD_V2)
           || (agent_type == constants::FSM_SQUAD_V3) || (agent_type == constants::FSM_SQUAD_V4)
           || (agent_type == constants::FSM_SQUAD_V5) || (agent_type == constants::FSM_CMD_HTN))
        {
            // addition of first squad and agent
//            if(squads.size() == 0)
//            {
//                squads.push_back(Squad(team, 0));
//                squads[0].add_Agent(ai_agents[agent_id]);
//            }
//            else
//            {
                // There are already squads. Find suitable one or add a new one.
                bool placed = false;
                unsigned int s = 0;
                while((placed == false) && (s < squads.size()))
                {
                    if((squads[s].squad_team == team) && (squads[s].get_Squad_Size() < squad_size))
                    {
                        // Space in squad, add agent.
                        squads[s].add_Agent(ai_agents[agent_id]);
                        placed = true;
                    }

                    s++;
                }

                // If no valid squad was found add a new one.
                if(placed == false)
                {
                    int id = squads.size();
                    squads.push_back(Squad(team, id));
                    if(agent_type == constants::FSM_CMD_HTN) { squads[id].commandSquad = true; }
                    squads[id].add_Agent(ai_agents[agent_id]);
                }
//            }
        }
    }

//    if(agent_type  == constants::FSM_CMD_HTN){
//        int index = commanders.size();
//        commanders.push_back(Commander(team, index));
//        for(unsigned int i = 0; i < squads.size(); i++)
//        {
//            if(squads[i].squad_team == team)
//            {
//                commanders[index].add_Squad(&squads[i]);
//            }
//        }
//        commanders[index].influence.set_Height(level.get_height_in_tiles_());
//        commanders[index].influence.set_Width(level.get_width_in_tiles_());
//        commanders[index].influence.setupInfluenceMaps();
//    }
//    LOG(FILE_LOG(logDEBUG) << "Game::add_Agents() -> end";);
}

void Game::calc_Crude_Visibility()
{
    for(unsigned int i = 0; i < level.tiles_.size(); i++)
    {
        // vars
        std::vector<int> visible_from_points;
        Tile test_tile;
        Tile inner_tile;
        int tx=0, ty=0, inx=0, iny=0;

        // get test tile
        level.get_tile(i, test_tile);
        test_tile.GetCentrePixels(tx, ty);

        // check test_tile against all other tiles
        for(unsigned int j = 0; j < level.tiles_.size(); j++)
        {
            // get inner tile
            level.get_tile(j, inner_tile);
            inner_tile.GetCentrePixels(inx, iny);

            if(checkLOS(tx, ty, inx, iny, level))
            {
                visible_from_points.push_back(inner_tile.map_ref);
            }
        }

        // Add vector to influence object
        crude_visibility.push_back(visible_from_points);
    }
}
