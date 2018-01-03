#include "Manager.h"
#include "Utils/rapidjson/document.h"

/// Class Constructor
Manager::Manager(std::string config_file):
        quit_manager(false),
        stop_current_game(false),
        grid_show(false),
        graph_show(false),
        debug1(true),
        game_finished(false),
        grey(0),
        red(0),
        game_time(Timer()),
        frame_rate_cap(200),
        frame_check(1000),
        fps_check(Timer()),
        logic_tick(100),
        tick_check(1000),
        modifier(1),
        logic_tick_check(Timer()),
        user_delta(Timer()),
        game_iterations(0),
        camera(Camera()),
        drawing(Draw()),
        team_1_wins(0),
        team_2_wins(0),
        drawn_games(0),
        game_log("gl"),
        test_summary("ts"),
        debug_log("dl"),
        config_log("cl"),
        death_log("el"),
        plan_log("pl")
{
    frame_check = 1000 / frame_rate_cap;
    tick_check = 1000 / (logic_tick * modifier);

    game_pause = false;
    inf_commander_1 = false;
    inf_commander_2 = false;
    inf_val = false;
    inf_map = 1;
    crude_vision = false;
    vis_values = false;

    if(configuration_Setup(config_file) == false)
    {
        game_iterations = 0;
        LOG(FILE_LOG(logERROR) << "Configuration file error.";);
    }

    create_Output_Files();
}

void Manager::create_Output_Files()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int sec = ltm->tm_sec;

    std::string s_month = utils::intToString(month);
    if(s_month.size() == 1)
    {
        s_month = "0" + s_month;
    }

    std::string s_day = utils::intToString(day);
    if(s_day.size() == 1)
    {
        s_day = "0" + s_day;
    }

    std::string s_hour = utils::intToString(hour);
    if(s_hour.size() == 1)
    {
        s_hour = "0" + s_hour;
    }

    std::string s_min = utils::intToString(minute);
    if(s_min.size() == 1)
    {
        s_min = "0" + s_min;
    }

    std::string s_sec = utils::intToString(sec);
    if(s_sec.size() == 1)
    {
        s_sec = "0" + s_sec;
    }

    std::string date =  utils::intToString(year) + "-" + s_month + "-" + s_day + "-" + s_hour + s_min + s_sec;

    #ifdef _LINUX
    game_log = "Logs/Game_Log_" + date + ".csv"; //Linux
    test_summary = "Logs/Summary_" + date + ".txt";
    config_log = "Logs/Config_File_" + date + ".txt";
    death_log = "Logs/Death_File_" + date + ".json";
    plan_log = "Logs/Plan_File_" + date + ".json";
    #else
    game_log = "Logs\\Game_Log_" + date + ".csv"; // Windows
    test_summary = "Logs\\Summary_" + date + ".txt";
    config_log = "Logs\\Config_File_" + date + ".txt";
    death_log = "Logs\\Death_File_" + date + ".json";
    plan_log = "Logs\\Plan_File_" + date + ".json";
    #endif

//    std::cerr << game_log << std::endl;
//    std::cerr << test_summary << std::endl;

    std::ofstream log_f(game_log.c_str());
    if(log_f.is_open())
    {
        log_f.close();
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Failed to create log file.";);
        std::cerr << "Failed to create log file." << std::endl;
    }

    std::ofstream sum_f(test_summary.c_str());
    if(sum_f.is_open())
    {
        sum_f.close();
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Failed to create summary file.";);
        std::cerr << "Failed to create summary file." << std::endl;
    }

    std::ofstream con_f(config_log.c_str());
    if(con_f.is_open())
    {
        con_f.close();
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Failed to create config log file.";);
        std::cerr << "Failed to create config log file." << std::endl;
    }

    std::ofstream dead_f(death_log.c_str());
    if(dead_f.is_open())
    {
        dead_f.close();
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Failed to create death log file.";);
        std::cerr << "Failed to create death log file." << std::endl;
    }

    std::ofstream plan_f(plan_log.c_str());
    if(plan_f.is_open())
    {
        plan_f.close();
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Failed to create plan log file.";);
        std::cerr << "Failed to create plan log file." << std::endl;
    }

    /// Main Log file setup ----------------------------------------------------------
    #ifdef _LINUX
    debug_log = "Logs/Debug_Log_" + date + ".txt"; //Linux
    #else
    debug_log = "Logs\\Debug_Log_" + date + ".txt"; // Windows
    #endif

     /// setting up the debug log file, only used if _DEBUG is defined
    /// _DEBUG is #defined in build options
    #ifdef _DEBUG
    FILELog::ReportingLevel() = logDEBUG3;
    FILE* log_fd = fopen( debug_log.c_str(), "w" );
    Output2FILE::Stream() = log_fd;
    #endif

//    LOG(FILE_LOG(logERROR) << "Manager::create_Output_Files() -> test";);

}

bool Manager::configuration_Setup(std::string config_file)
{
    LOG(FILE_LOG(logDEBUG) << config_file;);
    // Read the config file.
    if(read_Config_File(config_file) == true)
    {
        // Validate the logic of configuration.
        if(validate_Configuration() == false)
        {
            LOG(FILE_LOG(logERROR) << "Error validating read configuration.";);
            std::cerr << "Error validating read configuration." << std::endl;
            return false;
        }
    }
    else
    {
        LOG(FILE_LOG(logERROR) << "Error reading config file inside Manager.";);
        std::cerr << "Error reading config file inside Manager." << std::endl;
        return false;
    }

    return true;
}

bool Manager::validate_Configuration()
{
    bool result = true;
    // Game type check
    if(game_config.game_type != constants::DEATH_MATCH)
    {
        LOG(FILE_LOG(logERROR) << "Game type validation failure.";);
        std::cerr << "Game type validation failure." << std::endl;
        result = false;
    }

    // Time limit check. ie less than a minute.
    if(game_config.time_limit < 60000)
    {
        LOG(FILE_LOG(logERROR) << "Time limit validation failure.";);
        std::cerr << "Time limit validation failure." << std::endl;
        result = false;
    }

    // Score check
    if(game_config.score_limit <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Score limit validation failure.";);
        std::cerr << "Score limit validation failure." << std::endl;
        result = false;
    }

    // Map file check
    std::ifstream map_file(game_config.map_name.c_str(), std::ifstream::in);
    if(map_file.fail())
    {
        LOG(FILE_LOG(logERROR) << "Map file validation failure.";);
        std::cerr << "Map file validation failure." << std::endl;
        result = false;
    }
    map_file.close();

    // Game iterations check
    if(game_iterations <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Game iterations validation failure.";);
        std::cerr << "Game iterations validation failure." << std::endl;
        result = false;
    }

    // Team 1 checks ---------------------------------------------------------
    // AI type check
    if((game_config.T1_AI_type < 0) || (game_config.T1_AI_type > 10))
    {
        LOG(FILE_LOG(logERROR) << "Team 1 AI type validation failure.";);
        std::cerr << "Team 1 AI type validation failure." << std::endl;
        result = false;
    }

    // Agent total check
    if(game_config.T1_agent_total <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Team 1 agent total validation failure.";);
        std::cerr << "Team 1 agent total validation failure." << std::endl;
        result = false;
    }

    // Squad check
    if((game_config.T1_AI_type == constants::FSM_SQUAD_V1) || (game_config.T1_AI_type == constants::FSM_SQUAD_V2)
       || (game_config.T1_AI_type == constants::FSM_SQUAD_V3) || (game_config.T1_AI_type == constants::FSM_SQUAD_V4)
       || (game_config.T1_AI_type == constants::FSM_SQUAD_V5)  || (game_config.T1_AI_type == constants::FSM_CMD_HTN))
    {
        if(game_config.T1_squad_size <= 0)
        {
            LOG(FILE_LOG(logERROR) << "Team 1 squad size validation failure.";);
            std::cerr << "Team 1 squad size validation failure." << std::endl;
            result = false;
        }
    }

    // Respawn time check
    if(game_config.T1_respawn_time <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Team 1 respawn time validation failure.";);
        std::cerr << "Team 1 respawn time validation failure." << std::endl;
        result = false;
    }

    // Team 2 checks ---------------------------------------------------------
    // AI type check
    if((game_config.T2_AI_type < 0) || (game_config.T2_AI_type > 10))
    {
        LOG(FILE_LOG(logERROR) << "Team 2 AI type validation failure.";);
        std::cerr << "Team 2 AI type validation failure." << std::endl;
        result = false;
    }

    // Agent total check
    if(game_config.T2_agent_total <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Team 2 agent total validation failure.";);
        std::cerr << "Team 2 agent total validation failure." << std::endl;
        result = false;
    }

    // Squad check
    if((game_config.T2_AI_type == constants::FSM_SQUAD_V1) || (game_config.T2_AI_type == constants::FSM_SQUAD_V2)
       || (game_config.T2_AI_type == constants::FSM_SQUAD_V3) || (game_config.T2_AI_type == constants::FSM_SQUAD_V4)
       || (game_config.T2_AI_type == constants::FSM_SQUAD_V5)|| (game_config.T1_AI_type == constants::FSM_CMD_HTN))
    {
        if(game_config.T2_squad_size <= 0)
        {
            LOG(FILE_LOG(logERROR) << "Team 2 squad size validation failure.";);
            std::cerr << "Team 2 squad size validation failure." << std::endl;
            result = false;
        }
    }

    // Respawn time check
    if(game_config.T2_respawn_time <= 0)
    {
        LOG(FILE_LOG(logERROR) << "Team 2 respawn time validation failure.";);
        std::cerr << "Team 2 respawn time validation failure." << std::endl;
        result = false;
    }

    return result;
}

bool Manager::read_Config_File(std::string config_file)
{

    std::ifstream ifs(config_file);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );

    LOG(FILE_LOG(logINFO) << config_file << " == " << content;);

    initialConfigJson = content;

    if(ifs.fail())
    {
        LOG(FILE_LOG(logERROR) << "Error ifstream == NULL.";);
        std::cerr << "Error ifstream == NULL." << std::endl;
        return false;
    }

    rapidjson::Document doc;
    doc.Parse(content.c_str());

    int game_type = doc["game_type"].GetInt();
    int time_limit = doc["time_limit"].GetInt();
    int score_limit = doc["score_limit"].GetInt();
    int iterations = doc["iterations"].GetInt();
    std::string map = doc["map"].GetString();
    bool daemon_run = doc["daemon_run"].GetBool();

    game_config.game_type = (constants::GameTypes) game_type;
    game_config.time_limit = time_limit;
    game_config.score_limit = score_limit;
    game_iterations = iterations;
    game_config.map_name = map;
    daemonRun = daemon_run;

    std::string teamOneAi = doc["team_one"]["ai_type"].GetString();
    int teamOneNumBots = doc["team_one"]["num_bots"].GetInt();
    int teamOneNumSquads = doc["team_one"]["num_squads"].GetInt();
    int teamOneNumRespawn = doc["team_one"]["respawn_time"].GetInt();

    std::string teamTwoAi = doc["team_two"]["ai_type"].GetString();
    int teamTwoNumBots = doc["team_two"]["num_bots"].GetInt();
    int teamTwoNumSquads = doc["team_two"]["num_squads"].GetInt();
    int teamTwoNumRespawn = doc["team_two"]["respawn_time"].GetInt();

    game_config.T1_AI_type = (constants::StateMachines) aiTypeStringToInt(teamOneAi);
    game_config.T1_agent_total = teamOneNumBots;
    game_config.T1_squad_size = teamOneNumSquads;
    game_config.T1_respawn_time = teamOneNumRespawn;

    game_config.T2_AI_type = (constants::StateMachines) aiTypeStringToInt(teamTwoAi);
    game_config.T2_agent_total = teamTwoNumBots;
    game_config.T2_squad_size = teamTwoNumSquads;
    game_config.T2_respawn_time = teamTwoNumRespawn;

    //Close the file
    ifs.close();

    return true;
}

int Manager::run()
{
//    LOG(FILE_LOG(logDEBUG) << "Manager::run() -> begin";);

    /// SETUP ----------------------------------------------------------
    //srand((unsigned)time(0));
    srand(time(NULL));

    if(!daemonRun) {
        //Initialize SDL
        if (SDL_init() == false) {
            std::cerr << "SDL init fail." << std::endl;
            return 11;
        }

        //Load the files
        if (load_files() == false) {
            std::cerr << "File load fail." << std::endl;
            return 22;
        }

        //Clip the tile sheet
        surfaces::clip_tiles();

        mapView = SDL_CreateRGBSurface(screen->flags, CAMERA_WIDTH, CAMERA_HEIGHT, SCREEN_BPP, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask,screen->format->Amask);
        influenceMini = SDL_CreateRGBSurface(screen->flags, 375, 240, SCREEN_BPP, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask,screen->format->Amask);
        red = SDL_MapRGB(screen->format, 255,0,0);
        grey = SDL_MapRGB(screen->format, 128,128,128);
        SDL_FillRect(mapView,NULL,grey);
        SDL_FillRect(influenceMini,NULL,red);
        SDL_FillRect(screen,NULL,grey);
    }

    //Log the config settings used
    write_Config_File();

    /// ITERATIONS LOOP ----------------------------------------------------------------
    //std::cerr << "iterations" << game_iterations << std::endl;
    int i = 0;
    while((quit_manager == false) && (i < game_iterations))
    {
        //std::cout << i << std::endl;
        run_Game_Iteration(i);

        i++;
    }

    write_Summary_File();

    /// CLEAN UP -----------------------------------------------------------------
    if(!daemonRun) {
        clean_up();
    }

//    LOG(FILE_LOG(logDEBUG) << "Manager::run() -> end";);

    return 0;
}

void Manager::write_Summary_File()
{
    float t1_wins = ((float)team_1_wins/(float)game_iterations)*100;
    float t2_wins = ((float)team_2_wins/(float)game_iterations)*100;
    float drawn = ((float)drawn_games/(float)game_iterations)*100;

    std::ofstream sum_f(test_summary.c_str(), std::ios::app);
    if(sum_f.is_open())
    {
        sum_f << "Team 1 Wins: " << team_1_wins << " -- " << t1_wins << "%\n";
        sum_f << "Team 2 Wins: " << team_2_wins << " -- " << t2_wins << "%\n";
        sum_f << "Drawn Games: " << drawn_games << " -- " << drawn << "%\n\n";
        sum_f << "Configuration Settings used.\n";
        sum_f << game_config.game_type << "\n";
        sum_f << game_config.time_limit << "\n";
        sum_f << game_config.score_limit << "\n";
        sum_f << game_config.map_name << "\n";
        sum_f << game_iterations << "\n\n";
        sum_f << game_config.T1_AI_type << "\n";
        sum_f << game_config.T1_agent_total << "\n";
        sum_f << game_config.T1_squad_size << "\n";
        sum_f << game_config.T1_respawn_time << "\n\n";
        sum_f << game_config.T2_AI_type << "\n";
        sum_f << game_config.T2_agent_total << "\n";
        sum_f << game_config.T2_squad_size << "\n";
        sum_f << game_config.T2_respawn_time << "\n\n";
        sum_f << initialConfigJson << "\n\n";
        sum_f.close();
    }
    else
    {
        std::cerr << "Failed to write summary file." << std::endl;
    }

//    std::cerr << std::endl << "Team 1 Wins: " << team_1_wins << " -- " << (team_1_wins/game_iterations)*100 << "%" << std::endl;
//    std::cerr << "Team 2 Wins: " << team_2_wins << " -- " << (team_2_wins/game_iterations)*100 << "%"  << std::endl;
//    std::cerr << "Drawn Games: " << drawn_games << " -- " << (drawn_games/game_iterations)*100 << "%"  << std::endl;
}

void Manager::write_Config_File()
{
    std::ofstream con_f(config_log.c_str(), std::ios::app);
    if(con_f.is_open())
    {
        con_f << "Configuration Settings used.\n";
        con_f << game_config.game_type << "\n";
        con_f << game_config.time_limit << "\n";
        con_f << game_config.score_limit << "\n";
        con_f << game_config.map_name << "\n";
        con_f << game_iterations << "\n\n";
        con_f << game_config.T1_AI_type << "\n";
        con_f << game_config.T1_agent_total << "\n";
        con_f << game_config.T1_squad_size << "\n";
        con_f << game_config.T1_respawn_time << "\n\n";
        con_f << game_config.T2_AI_type << "\n";
        con_f << game_config.T2_agent_total << "\n";
        con_f << game_config.T2_squad_size << "\n";
        con_f << game_config.T2_respawn_time << "\n\n";
        con_f << initialConfigJson << "\n\n";
        con_f.close();
    }
    else
    {
        std::cerr << "Failed to write Config file." << std::endl;
    }
}

int Manager::run_Game_Iteration(int game_ID)
{
    LOG(FILE_LOG(logDEBUG) << "Manager::run_Game_Iteration(" << game_ID << ") -> begin";);
    /// GAME SETUP -------------------------------------
    Game game(game_config);
    game_finished = false;
    stop_current_game = false;

    //TODO (gen#3#) Not sure how useful these timers actually are...??
    game_time.start();

    // Frame rate stuff
    //frame = 0;
    //fps.start();
    fps_check.start();

    // Logic tick stuff
//    ticks = 0;
    logic_tick_check.start();
    //logic_tick_time.start();

    user_delta.start();

    /// MAIN LOOP ----------------------------------------------------------------
    //While the user hasn't quit
    while((stop_current_game == false) && (quit_manager == false))
    {
        if(!daemonRun) { user_Input_Check(); }

        /// LOGIC STARTS HERE ------------------------
        if(!daemonRun) {
            camera.move(user_delta.get_ticks(),game.level.get_width_in_pixels_(), game.level.get_height_in_pixels_());
        }

        if(logic_tick_check.get_ticks() > tick_check)
        {
            if(game_pause == false)
            {
                game_finished = game.run_Game_Logic(15); // To simulate having limited time to calculate, as it would be in a real game.
//              ticks++;
                logic_tick_check.start();
            }
        }

        if(game_finished == true)
        {
            Score g_score = game.get_Game_Score();
            int winner = -99;
            if(g_score.team_1_score > g_score.team_2_score)
            {
                winner = 1;
                team_1_wins++;
            }
            else if(g_score.team_2_score > g_score.team_1_score)
                {
                    winner = 2;
                    team_2_wins++;
                }
                else if(g_score.team_1_score == g_score.team_2_score)
                    {
                        winner = 0;
                        drawn_games++;
                    }

            //std::cerr << game_ID << " - " << winner << " - " << g_score.team_1_score << " - " << g_score.team_2_score << " - " << g_score.game_time << std::endl;
            write_Game_Log(game_ID, g_score, winner);
            write_Death_Log(game_ID, g_score, winner, game.death_information);
            write_Plan_Log(game_ID, game.commanders);

            stop_current_game = true;
        }

        if(fps_check.get_ticks() > frame_check)
        {
//            int s1 = game_time.get_ticks();
            if(!daemonRun) {
                if(render(game, game_ID) == false)
                {
                    std::cerr << "Render Error." << std::endl;
                    return 33;
                }
            }
            else { std::this_thread::sleep_for(std::chrono::milliseconds(12)); }
//            int s2 = game_time.get_ticks() - s1;
//            LOG(FILE_LOG(logDEBUG) << "render time: " << s2;);

            // reset check
            fps_check.start();
        }

        //Restart delta timer
        user_delta.start();
    }

    LOG(FILE_LOG(logDEBUG) << "Manager::run_Game_Iteration(" << game_ID << ") -> end";);
    return 0;
}

void Manager::write_Game_Log(int game_ID, Score info, int winner)
{
    std::ofstream log_f(game_log.c_str(), std::ios::app);
    if(log_f.is_open())
    {
        log_f << game_ID << "," << winner << "," << info.team_1_score << "," << info.team_2_score << "," << info.game_time << "\n";
        log_f.close();
    }
    else
    {
        std::cerr << "Failed to write to log file." << std::endl;
    }
}

void Manager::write_Death_Log(int game_ID, Score info, int winner, vector<Death_Info>& deaths)
{
    std::string gameLog = "{\"game_id\":";
    gameLog += std::to_string(game_ID);
    gameLog += ",\"winner\": ";
    gameLog += std::to_string(winner);
    gameLog += ",\"team_one_score\": ";
    gameLog += std::to_string(info.team_1_score);
    gameLog += ",\"team_two_score\": ";
    gameLog += std::to_string(info.team_2_score);
    gameLog += ",\"game_time\": ";
    gameLog += std::to_string(info.game_time);
    gameLog += ",\"deaths\": [";

    for(unsigned int i = 0; i < deaths.size(); i++){
        std::string deathLog = "{\"time\": ";
        deathLog += std::to_string(deaths[i].timeOfDeath);
        deathLog += ", \"team\": ";
        deathLog += std::to_string(deaths[i].botTeam);
        deathLog += ", \"xpos\": ";
        deathLog += std::to_string(deaths[i].xPos);
        deathLog += ", \"ypos\": ";
        deathLog += std::to_string(deaths[i].yPos);
        deathLog += "}";

        if(i < deaths.size()-1) deathLog += ",";

        gameLog += deathLog;
    }

    gameLog += "]}";

    std::ofstream log_f(death_log.c_str(), std::ios::app);
    if(log_f.is_open())
    {
        log_f << gameLog << "\n";

        log_f.close();
    }
    else
    {
        std::cerr << "Failed to write to log file." << std::endl;
    }
}

void Manager::write_Plan_Log(int game_ID, vector<Commander>& commanders) {
    std::string planLog = "dud";

    std::ofstream log_f(plan_log.c_str(), std::ios::app);
    if(log_f.is_open()) {
        if (!commanders.empty()) {
            vector<Commander>::iterator iterC = commanders.begin();
            while (iterC != commanders.end()) {
                vector<PlanLog>::iterator iterP = (*iterC).planLogs.begin();
                while (iterP != (*iterC).planLogs.end()) {
                    planLog = "{\"game_id\": ";
                    planLog += std::to_string(game_ID);
                    planLog += ",\"team\": ";
                    planLog += std::to_string((*iterP).team);
                    planLog += ",\"start\": ";
                    planLog += std::to_string((*iterP).start);
                    planLog += ",\"end\": ";
                    planLog += std::to_string((*iterP).end);
                    planLog += ",\"plan\": ";
                    planLog += (*iterP).plan;

                    planLog += "}";

                    log_f << planLog << "\n";

                    iterP++;
                }
                iterC++;
            }
        }

        log_f.close();
    } else {
        std::cerr << "Failed to write to log file." << std::endl;
    }
}

bool Manager::SDL_init()
{
    //Initialize SDL subsystems
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
    {
        std::cerr << "SDL_Init() fail." << std::endl;
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_DOUBLEBUF);

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        std::cerr << "Screen setup fail." << std::endl;
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        std::cerr << "TTF setup fail." << std::endl;
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Test Manager", NULL );

    //If everything initialized fine
    return true;
}

bool Manager::load_files()
{
    //Load the tile sheet
    tileSheet = surfaces::load_image( "Images/tiles.png" );

    //If there was a problem in loading the tiles
    if( tileSheet == NULL )
    {
        std::cerr << "Tilesheet load fail." << std::endl;
        return false;
    }

    //Open the font
    font = TTF_OpenFont( "Fonts/arial.ttf", 10);

    //If there was an error in loading the font
    if( font == NULL )
    {
        std::cerr << "Font load fail." << std::endl;
        return false;
    }

    //If everything loaded fine
    return true;
}

void Manager::user_Input_Check()
{
    //While there's events to handle
    while( SDL_PollEvent( &event ) )
    {
        camera.handle_input(event);

        // clicking camera area
        if( event.type == SDL_MOUSEBUTTONUP )
        {
            //If the left mouse button was released
            if( event.button.button == SDL_BUTTON_LEFT )
            {
            }
        }

        // keyboard controls
        if( event.type == SDL_KEYDOWN )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_g:
                    grid_show = !grid_show; //toggle
                    break;

                case SDLK_a:
                    graph_show = !graph_show;
                    break;

                case SDLK_d:
                    debug1 = !debug1;
                    break;


                case SDLK_1:
                    {
                        modifier = 1;
                        tick_check = 1000 / (logic_tick * modifier);
                    }
                    break;

                case SDLK_2:
                    {
                        modifier = 2;
                        tick_check = 1000 / (logic_tick * modifier);
                    }
                    break;

                case SDLK_3:
                    {
                        modifier = 3;
                        tick_check = 1000 / (logic_tick * modifier);
                    }
                    break;

                case SDLK_SPACE:
                    stop_current_game = true;
                    break;

                case SDLK_ESCAPE:
                    quit_manager = true;
                    break;

                case SDLK_PAUSE:
                    game_pause = !game_pause;
                    break;

                case SDLK_F1:
                    {
                        inf_commander_1 = !inf_commander_1;
                        inf_map = 1;
                        if(inf_commander_2 == true)
                        {
                            inf_commander_2 = false;
                        }
                    }
                    break;

                case SDLK_F2:
                    {
                        inf_commander_2 = !inf_commander_2;
                        inf_map = 1;
                        if(inf_commander_1 == true)
                        {
                            inf_commander_1 = false;
                        }
                    }
                    break;

                case SDLK_F3:
                    inf_val = !inf_val;
                    break;

                case SDLK_F4:
                    inf_map = 1;
                    break;

                case SDLK_F5:
                    inf_map = 2;
                    break;

                case SDLK_F6:
                    inf_map = 3;
                    break;

                case SDLK_F7:
                    inf_map = 4;
                    break;

                case SDLK_F8:
                    inf_map = 5;
                    break;

                case SDLK_v:
                    crude_vision = !crude_vision;
                    break;

                case SDLK_b:
                    vis_values = !vis_values;
                    break;

                default: break;
            }
        }

        //If the user has Xed out the window
        if(event.type == SDL_QUIT)
        {
            //Quit the program
            quit_manager = true;
        }
    }
}

void Manager::clean_up()
{
    //Free the surfaces
    SDL_FreeSurface(tileSheet);
    SDL_FreeSurface(mapView);
    SDL_FreeSurface(message);
    //TODO (imp#3#) Maybe free screen as well???

    //Close the font that was used
    TTF_CloseFont(font);

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

bool Manager::render(Game &game, int game_id)
{
    SDL_FillRect(mapView,NULL,red);
    SDL_FillRect(screen,NULL,grey);
    SDL_FillRect(influenceMini,NULL,red);

    drawing.show_Level(game.level, camera.box, grid_show);
    //drawing.show_Influence_Mini_Level(game.level);
    //drawing.show_Influence_Mini_Power(game.influence_maps);

    if(graph_show == true)
    {
        drawing.show_Graph(game.graph, game.level, camera.box);
    }

    // AI AGENTS
    for(unsigned int i = 0; i < game.ai_agents.size(); i++)
    {
        if(game.ai_agents[i]->info.alive == true)
        {
            drawing.show_AI_Agent((*game.ai_agents[i]), game.level, camera.box, debug1);
            //drawing.show_Influence_Mini_Agent(game.ai_agents[i]->info.current_position, game.ai_agents[i]->info.radius, game.ai_agents[i]->info.team);
        }
    }

    // BULLETS
    for(unsigned int b = 0; b < game.bullets.size(); b++)
    {
        drawing.show_Bullet(game.bullets[b], camera.box);
    }

    // SQUADS
    if(debug1)
    {
        for(unsigned int s = 0; s < game.squads.size(); s++)
        {
            if(game.squads[s].active_Check() == true)
            {
                drawing.show_Squad(game.squads[s], camera.box);
            }
        }
    }

    debug_Output(game, game_id);


    // Influence maps
    if(inf_commander_1)
    {
        drawing.show_Influence_Main(game.commanders[0].influence, inf_map);

        if(inf_val)
        {
            drawing.show_Influence_Main_Values(game.commanders[0].influence, inf_map);
        }

        drawing.show_EnemyMaxInf(game.commanders[0].influence.enemyMax);
        drawing.show_VulnerablePoint(game.commanders[0].influence.vulnerableA);
        drawing.show_VulnerablePoint(game.commanders[0].influence.vulnerableB);

        for (int i = 0; i < game.commanders[0].influence.vulAVisPts.size(); ++i) {
            drawing.show_VulnerableAssPoint(game.commanders[0].influence.vulAVisPts[i]);
        }

        for (int i = 0; i < game.commanders[0].influence.vulBVisPts.size(); ++i) {
            drawing.show_VulnerableAssPoint(game.commanders[0].influence.vulBVisPts[i]);
        }
    }

    if(inf_commander_2)
    {
        drawing.show_Influence_Main(game.commanders[1].influence, inf_map);

        if(inf_val)
        {
            drawing.show_Influence_Main_Values(game.commanders[1].influence, inf_map);
        }
    }

    // Crude vision
    if(crude_vision)
    {
        drawing.show_Crude_Vision(game.level, game.crude_visibility, camera.box, vis_values);
    }

    surfaces::apply_surface( constants::MAP_VIEW_X, constants::MAP_VIEW_Y, mapView, screen );
    //surfaces::apply_surface( 1020, 150, influenceMini, screen );

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        std::cerr << "Screen update fail." << std::endl;
        return false;
    }

    //frame++;

    return true;
}

void Manager::debug_Output(Game &game, int game_id)
{
    SDL_Color textColor;
    textColor.b = 255;
    textColor.g = 255;
    textColor.r = 255;

    // controls
    std::string text = "controls: ";
    surfaces::textToSurface(text, textColor, screen,200,10);
    text = "<g> - shows grid";
    surfaces::textToSurface(text, textColor, screen,200,20);
    text = "<a> - shows path graph";
    surfaces::textToSurface(text, textColor, screen,200,30);
    text = "<d> - toggles AI debug mode";
    surfaces::textToSurface(text, textColor, screen,200,40);
    text = "<1,2,3> - changes speed modifier";
    surfaces::textToSurface(text, textColor, screen,200,50);
    text = "<ESC> - Quits the whole manager app.";
    surfaces::textToSurface(text, textColor, screen,200,60);
    text = "<SPACE> - Ends the current game.";
    surfaces::textToSurface(text, textColor, screen,200,70);
    text = "<PAUSE> - Pauses the game.";
    surfaces::textToSurface(text, textColor, screen,200,80);
    text = "<v> - Toggle crude vision mode.";
    surfaces::textToSurface(text, textColor, screen,200,90);
    text = "<b> - Show visibility values.";
    surfaces::textToSurface(text, textColor, screen,200,100);

    text = "<F1> - Toggle Commander 1 influence map.";
    surfaces::textToSurface(text, textColor, screen,600,10);
    text = "<F2> - Toggle Commander 2 influence map.";
    surfaces::textToSurface(text, textColor, screen,600,20);
    text = "<F3> - Show influence map values.";
    surfaces::textToSurface(text, textColor, screen,600,30);

    text = "<F4> - Friendly influence.";
    surfaces::textToSurface(text, textColor, screen,600,40);
    text = "<F5> - Enemy influence.";
    surfaces::textToSurface(text, textColor, screen,600,50);
    text = "<F6> - General influence map. T1 - T2";
    surfaces::textToSurface(text, textColor, screen,600,60);
    text = "<F7> - Tension map. T1 + T2Vulnerability influence map. Tension - abs_Gen";
    surfaces::textToSurface(text, textColor, screen,600,70);
    text = "<F8> - Vulnerability influence map. Tension - abs_Gen";
    surfaces::textToSurface(text, textColor, screen,600,80);

    // Frame Rate output
//    std::string fps_val;
//    fps_val = "Frame rate: " + utils::intToString(frame/(game_time.get_ticks()/1000.f));
//    surfaces::textToSurface(fps_val, textColor, screen,1050,20);

    // ticks output
//    std::string ticks_val;
//    ticks_val = "tick rate: " + utils::intToString(ticks/(game_time.get_ticks()/1000.f));
//    surfaces::textToSurface(ticks_val, textColor, screen,1050,35);

    // Speed modifier
//    std::string speed_mod;
    text = "speed modifier: " + utils::intToString(modifier);
    surfaces::textToSurface(text, textColor, screen,10,100);

    text = "Paused: " + utils::boolToString(game_pause);
    surfaces::textToSurface(text, textColor, screen,10,110);

    // AI
    // Team 1
    surfaces::textToSurface("-- Team 1 --", textColor, screen,400,5);
    int srt = 15, shift = 12;
    for(unsigned int i = 0; i < game.ai_agents.size(); i++)
    {
        if(game.ai_agents[i]->info.team == 1)
        {
            if(game.ai_agents[i]->info.alive)
            {
                text = utils::intToString(game.ai_agents[i]->info.agent_ID) + " " + utils::intToString(game.ai_agents[i]->info.team) + " " + utils::intToString(game.ai_agents[i]->getState());
                surfaces::textToSurface(text, textColor, screen,400,srt);
                srt += shift;
            }
        }
    }

    // Team 2
    surfaces::textToSurface("-- Team 2 --", textColor, screen,500,5);
    srt = 15;
    for(unsigned int i = 0; i < game.ai_agents.size(); i++)
    {
        if(game.ai_agents[i]->info.team == 2)
        {
            if(game.ai_agents[i]->info.alive)
            {
                text = utils::intToString(game.ai_agents[i]->info.agent_ID) + " " + utils::intToString(game.ai_agents[i]->info.team) + " " + utils::intToString(game.ai_agents[i]->getState()) + " "+ utils::boolToString(game.ai_agents[i]->info.engaged);
                surfaces::textToSurface(text, textColor, screen,500,srt);
                srt += shift;
            }
        }
    }

    // Squad Info
    surfaces::textToSurface("-- Team 1 Squads --", textColor, screen,600,90);
    srt = 100;//, shift = 12;
    for(unsigned int i = 0; i < game.squads.size(); i++)
    {
        if(game.squads[i].squad_team == 1)
        {
            text = utils::intToString(game.squads[i].squad_team) + " " + utils::intToString(game.squads[i].squad_ID) + " " + utils::boolToString(game.squads[i].support_flag);
            surfaces::textToSurface(text, textColor, screen,600,srt);
            srt += shift;
        }
    }

    surfaces::textToSurface("-- Team 2 Squads --", textColor, screen,730,90);
    srt = 100;
    for(unsigned int i = 0; i < game.squads.size(); i++)
    {
        if(game.squads[i].squad_team == 2)
        {
            text = utils::intToString(game.squads[i].squad_team) + " " + utils::intToString(game.squads[i].squad_ID) + " " + utils::boolToString(game.squads[i].support_flag);
            surfaces::textToSurface(text, textColor, screen,730,srt);
            srt += shift;
        }
    }

    // Game Timer
    text = "Game Timer: " + utils::intToString(game.game_timer.get_ticks()/1000);
    surfaces::textToSurface(text, textColor, screen,10,20);

    // Score
    surfaces::textToSurface("---SCORE----", textColor, screen,10,40);
    text = "Team 1: " + utils::intToString(game.score_team1);
    surfaces::textToSurface(text, textColor, screen,10,50);
    text = "Team 2: " + utils::intToString(game.score_team2);
    surfaces::textToSurface(text, textColor, screen,10,60);

    // Games
    text = "Current Game: " + utils::intToString(game_id+1) + " of " + utils::intToString(game_iterations);
    surfaces::textToSurface(text, textColor, screen,10,10);

    // Wins
    text = "Set Wins: " + utils::intToString(team_1_wins) + " vs " + utils::intToString(team_2_wins);
    surfaces::textToSurface(text, textColor, screen,10,80);

    // AI Types
    text = utils::intToString((int)game_config.T1_AI_type) + " vs. " + utils::intToString((int)game_config.T2_AI_type);
    surfaces::textToSurface(text, textColor, screen,150,100);
}

int Manager::aiTypeStringToInt(std::string ai) {
    int type = -2;

    if(ai.compare("R1") == 0) type = 1;

    if(ai.compare("S1") == 0) type = 2;

    if(ai.compare("R2") == 0) type = 3;

    if(ai.compare("S2") == 0) type = 4;

    if(ai.compare("R3") == 0) type = 5;

    if(ai.compare("R4") == 0) type = 6;

    if(ai.compare("S3") == 0) type = 7;

    if(ai.compare("S4") == 0) type = 8;

    if(ai.compare("S5") == 0) type = 9;

    if(ai.compare("H1") == 0) type = 10;

    return type;
}
