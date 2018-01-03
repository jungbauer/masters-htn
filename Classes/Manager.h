#ifndef MANAGER_H
#define MANAGER_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

#include "Game.h"
#include "Camera.h"
#include "Draw.h"

#include "Utils/Constants.h"
#include "Utils/Surfaces.h"
#include "Utils/Timer.h"
#include "Utils/Utils.h"
#include "Utils/log.h"

using namespace constants;

class Manager {
	public:
        Manager(std::string config_file);

        int run();

        bool SDL_init();
        bool load_files();
        bool render(Game &game, int game_id);
        void clean_up();

        void user_Input_Check();

        //void infoShow(Camera &camera, int lvl_w, int lvl_h, AI_Agent &agent);
        void debug_Output(Game &game, int game_id);

    private:
        bool configuration_Setup(std::string config_file);
        bool read_Config_File(std::string config_file);
        bool validate_Configuration();
        void create_Output_Files();
        void write_Summary_File();
        void write_Config_File();
        void write_Game_Log(int game_ID, Score info, int winner);
        void write_Death_Log(int game_ID, Score info, int winner, vector<Death_Info>& deaths);
        void write_Plan_Log(int game_ID, vector<Commander>& commanders);
        int aiTypeStringToInt(std::string ai);

        int run_Game_Iteration(int game_ID);

        bool quit_manager;
        bool stop_current_game;

        bool grid_show;
        bool graph_show;
        bool debug1;
        bool game_finished;
        SDL_Event event;
        Uint32 grey;
        Uint32 red;

        Timer game_time;

//        int frame;
        int frame_rate_cap;
        int frame_check;
        //Timer fps;
        Timer fps_check;

        int logic_tick;
//        int ticks;
        int tick_check;
        int modifier;
        Timer logic_tick_check;
        //Timer logic_tick_time;

        Timer user_delta;

        Game_Configuration game_config;
        int game_iterations;
        Camera camera;
        Draw drawing;
        int team_1_wins;
        int team_2_wins;
        int drawn_games;
        std::string game_log;
        std::string test_summary;
        std::string debug_log;
        std::string config_log;
        std::string death_log;
        std::string plan_log;
        bool game_pause;
        //bool inf_show;
        bool inf_commander_1;
        bool inf_commander_2;
        bool inf_val;
        int inf_map;
        bool crude_vision;
        bool vis_values;
        std::string initialConfigJson;
        bool daemonRun;
};

#endif



