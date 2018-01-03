#ifndef AI_AGENT_H
#define AI_AGENT_H

#include <vector>
#include <cmath>

#include "../Utils/Coord.h"
#include "../Utils/log.h"
#include "../Pathfinding/Path.h"
#include "../Pathfinding/Graph.h"
#include "AI_Info.h"
#include "../Level.h"
#include "../Tile.h"

#include "Enemy_vars.h"
#include "Actions/Action.h"
#include "Actions/Act_Pathfind.h"

#include "State_Machines/StateMachine.h"
#include "State_Machines/FSM_Default.h"
#include "State_Machines/FSM_Squad_V1.h"
#include "State_Machines/FSM_Rand_V2.h"
#include "State_Machines/FSM_Rand_V3.h"
#include "State_Machines/FSM_Rand_V4.h"
#include "State_Machines/FSM_Squad_V2.h"
#include "State_Machines/FSM_Squad_V3.h"
#include "State_Machines/FSM_Squad_V4.h"
#include "State_Machines/FSM_Squad_V5.h"
#include "State_Machines/FSM_Htn.h"

/// AI Class
class AI_Agent {
	public:
        AI_Agent(constants::StateMachines fsm, VecXY_Float startPos, float orient, float spd, float rot, int tm, int ID, bool dumb);
        ~AI_Agent();

        // Orientation & angle methods
        void orientateTowardsTarget(VecXY_Float target, unsigned int& deltaTicks);
        float rotateAgent(bool direction, unsigned int& deltaTicks);

        // Movement methods
        void move(unsigned int deltaTicks, Level& level);
        void moveOrientate(unsigned int deltaTicks, Level& level);
        VecXY_Float getNextPosition(unsigned int& deltaTicks);
        VecXY_Float side_Step(VecXY_Float object);

        // Collision checks

        // Pathing methods

        // Damage methods
        void registerDamage(float base, VecXY_Float bull_pos);

        // Get & Set methods
        constants::StateType getState();
        void setGoal(VecXY_Float goal);
        void setAIPath(Path path);
        void set_Moving_State();

        // Other methods
        void update(Action* &act);
        void pop_action();

        void clear_Action_List();
        void erase_First_Action();
        //void clear_Action_Queue();
        //void pop_Action_Queue();
        void register_Bullet_Miss(int bullet_ID, VecXY_Float obj_pos);

        // -------------------------------------------------------------------------
        // public variables --------------------------------------------------------
        vector<Action*> action_list;
        //Work* job;
        AI_Info info;
        int stuck_count; // Used to count movement collisions and force a new pathfind if threshold is reached.
        int miss_count; // Used to check if a visible target is being shot at and the bullets are continually hitting an obstacle.
        int last_missed_bullet; // Tracks the ID of the last bullet to miss its target.

    private:
        StateMachine* state_machine_;
        AI_Agent(const AI_Agent& that);
        AI_Agent& operator=(const AI_Agent& that);
};

#endif

