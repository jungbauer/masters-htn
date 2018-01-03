#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    //Screen attributes
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 800;
    const int SCREEN_BPP = 32;

    //Camera attributes
    const int CAMERA_WIDTH = 1000;
    const int CAMERA_HEIGHT = 640;
    const int CAMERA_VELOCITY = 4000;

    const int MAP_VIEW_X = 10;
    const int MAP_VIEW_Y = 150;

    //The frame rate
    const int FRAMES_PER_SECOND = 20;

    //The dimensions of the level
    //const int LEVEL_WIDTH = 2000;
    //const int LEVEL_HEIGHT = 1000;

    //Tile constants
    const int TILE_WIDTH = 40;
    const int TILE_HEIGHT = 40;
    //const int TOTAL_TILES = 1250;
    const int NUM_TILE_SPRITES = 5;

    const float PIE = 3.14159265;

    //The different tile sprites
    enum TileSprites
    {
        ENUM_BLANK = 0,
        ENUM_GRASS = 1,
        ENUM_PATH = 2,
        ENUM_HIGH_WALL = 3,
        ENUM_LOW_WALL = 4,
    };

    enum StateType
    {
        STATE_IDLE = 0,
        STATE_MOVING = 1,
        STATE_ATTACK = 2,
        STATE_SHOOT = 3,
        STATE_ORIENTATE = 4,
        STATE_CLOSE = 5,
        STATE_SCAN = 6,
        STATE_CHASE = 7,
        STATE_SEARCH = 8
    };

    enum Actions
    {
        ACT_NONE = 0,
        ACT_FOLLOW_PATH = 1,
        ACT_RAND_PATHFIND = 2,
        ACT_PATHFIND = 3,
        ACT_CHOOSE_TARGET = 4,
        ACT_ORIENT = 5,
        ACT_FIRE = 6,
        ACT_TAKE_ITEM = 7,
        ACT_PLACE_ITEM = 8,
        ACT_SUPPORT_PATHFIND = 9,
        ACT_QUERY_SQUAD = 10,
        ACT_RESET_ENGAGED = 11,
        ACT_SET_ENGAGED = 12,
        ACT_SCAN = 13,
        ACT_SETUP_SEARCH = 14,
        ACT_SPOT_SEARCH = 15,
        ACT_TARGET_FLAGGED = 16,
        ACT_CHOOSE_TARGET_V2 = 17,
        ACT_SET_SUPPORT_LOCATION = 18,
        ACT_FOLLOW_PATH_ORIENT = 19
    };

    enum Locations
    {
        LOC_DEFAULT = 0,
    };

    enum Items
    {
        ITEM_DEFAULT = 0,
    };

    enum Work
    {
        WORK_NONE = 0,
    };

    enum StateMachines
    {
        FSM_IDLE = 0,
        FSM_DEFAULT = 1,
        FSM_SQUAD_V1 = 2,
        FSM_RAND_V2 = 3,
        FSM_SQUAD_V2 = 4,
        FSM_RAND_V3 = 5,
        FSM_RAND_V4 = 6,
        FSM_SQUAD_V3 = 7,
        FSM_SQUAD_V4 = 8,
        FSM_SQUAD_V5 = 9,
        FSM_CMD_HTN = 10,
    };

    enum GameTypes
    {
        DEATH_MATCH = 0,
    };

    enum PlannerTaskType {
        PT_TYPE_PRIMITIVE,
        PT_TYPE_COMPOUND
    };

    enum PlannerTasks {
        PT_NONE = 0,
        PT_BE_COMMANDER = 1,
        PT_USE_THREE = 2,
        PT_USE_TWO = 3,
        PT_USE_ONE = 4,
        PT_SQ1_VA = 5,
        PT_SQ2_VA = 6,
        PT_SQ3_VA = 7,
        PT_SQ3_VB = 8,
        PT_FIRST_IDLE_ENGAGED = 9,
        PT_SECOND_IDLE_ENGAGED = 10,
        PT_FIRST_IDLE_CLOSEST_ENGAGED = 11,
        PT_FIRST_IDLE_VA = 12,
        PT_SECOND_IDLE_VA = 13,
    };
}

#endif
