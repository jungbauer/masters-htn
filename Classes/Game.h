#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include "Bullet.h"
#include "Item.h"

#include "Locations/Location.h"

#include "Pathfinding/Graph.h"
#include "Pathfinding/PathFinding.h"

#include "AI/AI_Agent.h"
#include "AI/Squad.h"
#include "AI/Commander.h"
//#include "AI/InfluenceMaps.h"
#include "AI/Action_Handler.h"
#include "AI/Actions/Action.h"

#include "Utils/Box.h"
#include "Utils/Timer.h"
#include "Utils/log.h"

struct Agent_Status
{
    int agent_ID;
    bool alive;
};

struct Score
{
    int team_1_score;
    int team_2_score;
    int game_time;
};

struct Death_Info {
    int timeOfDeath;
    int botTeam;
    float xPos;
    float yPos;
};

struct Game_Configuration
{
    constants::GameTypes game_type;
    int time_limit;
    int score_limit;
    std::string map_name;

    constants::StateMachines T1_AI_type;
    int T1_agent_total;
    int T1_squad_size;
    int T1_respawn_time;

    constants::StateMachines T2_AI_type;
    int T2_agent_total;
    int T2_squad_size;
    int T2_respawn_time;
};

class Game {
    public:
        Game(Game_Configuration config);
        ~Game();

        bool run_Game_Logic(unsigned int delta_ticks);

        void Agent_Logic(unsigned int delta_ticks);
        void Bullet_Logic(unsigned int delta_ticks);
        void Location_Logic(unsigned int delta_ticks);
        void Squad_Logic(unsigned int delta_ticks);
        void commanderLogic();

        void enemyPerceptionCheck(AI_Agent& agent, std::vector<AI_Agent*>& all_agents, Level& level);
        bool checkLOS(int x1, int y1, int x2, int y2, Level& level);
        bool bulletAgentCollision(Bullet &bullet, AI_Agent* agent);
        void finished_Check();

        Score get_Game_Score();

        void pause();
        void unpause();


        Level level;
        Graph graph;
        vector<Bullet> bullets;
        vector<AI_Agent*> ai_agents;
        vector<Location*> locations;
        vector<Squad> squads;
        vector<Commander> commanders;
        Timer game_timer;
        int score_team1;
        int score_team2;
        vector<Agent_Status> previous_tick;
        //InfluenceMaps influence_maps;
        vector<vector<int> > crude_visibility;
        vector<Death_Info> death_information;

    private:
        Action_Handler act_handler;
        Action* AI_action;
        PathFinding path_finder;
        bool first_call;
        bool game_finished;
        int game_time_limit;
        int game_score_limit;

        Game(const Game& that);
        Game& operator=(const Game& that);
        void manual_Agent_Setup();
        void add_Agents(int team, constants::StateMachines agent_type, int total, int squad_size, VecXY_Float pos, float orientation, bool dumb);
        void calc_Crude_Visibility();
};

#endif
