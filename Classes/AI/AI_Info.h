#ifndef AI_INFO_H
#define AI_INFO_H

#include <vector>

#include "../Utils/Constants.h"
#include "../Utils/VecXY_Float.h"
#include "../Utils/Timer.h"

#include "../Pathfinding/Path.h"

#include "../Item.h"

#include "Enemy_vars.h"

class AI_Info
{
    public:
        AI_Info(VecXY_Float startPos, float orient, float spd, float rot, int ID, int tm, bool dumb);

        float speed;        // Speed per second
        float rotation;     // Angular velocity in degrees per second

        float radius;   // The radius that defines a circle around the agent.
        float fov;      // The agent's field of view
        float vision_range; // How far the agent can see, in pixels
        int agent_ID;   //unique ID reference for agent

        int team;
        float health;
        float max_health;
        bool alive;
        bool dummy;     // If true the agent sees no enemies ie perception is not updated.
        int squad_ID;

        float orientation;  // Facing in degrees
        VecXY_Float current_position;
        VecXY_Float previous_position;

        Path path;
        VecXY_Float path_goal;
        VecXY_Float next_path_coord;

        bool goal_reached;
        bool goal_changed_flag;

        Enemy_vars attack_target;
        vector<Enemy_vars> seen_enemies; // Lists the enemies that this agent can currenttly see.

        // Vars and method used for the Chase and Search behaviours.
        bool search_direction; // Bool used to define whether the agent turns left or right when searching.
        float search_rotation; // Float used to record how many degrees the agent has rotated during a search.
        vector<int> known_dead_enemies; // Lists the enemies the this agent has seen dead.
        void register_Dead_Enemy(int id);   // Used to add seen dead enemies to the list.

        // Vars used for the improved target selection, ie Act_Choose_Target_V2()
        bool better_target_flag;

        bool engaged;
        VecXY_Float bullet_pos;
        float perception_distance;

        float attack_range; //TODO (stuff#1#) Would be weapon dependent if diff weapons could be used.
        Timer weapon_timer;
        int rate_of_fire;
        std::vector<Item> inventory;
        int bullet_count;
        int miss_threshold; // The number of time an Agent can miss a target before trying to ajust position.

        bool squad_support_flag;
        VecXY_Float observePoint;

        // -------------------------------------------------------------------------
        // Query methods -----------------------------------------------------------

        bool visibleEnemiesCheck();
        bool orientationCheck(VecXY_Float target, float margin);
        bool validateTarget(Enemy_vars &target);
        bool rangeCheck(Enemy_vars &target, float margin);
        bool atPosition(VecXY_Float target, float margin);
        bool deadEnemiesCheck(int id);
        bool searchRangeCheck(Enemy_vars &target, float margin);
        bool betterTargetCheck();

        Enemy_vars get_Targeting_Info();
        bool update_Current_Attack_Target();

    private:
        AI_Info(const AI_Info& that);
        AI_Info& operator=(const AI_Info& that);
};

#endif

