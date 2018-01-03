#ifndef SQUAD_H
#define SQUAD_H

#include <vector>

#include "AI_Agent.h"
#include "AI_Info.h"

#include "Actions/Action.h"
#include "Actions/Act_None.h"
#include "Actions/Act_Pathfind.h"

#include "../Level.h"
#include "../Pathfinding/Graph.h"

#include "../Utils/Constants.h"
#include "../Utils/VecXY_Float.h"
#include "../Utils/Utils.h"

struct Agent_Track
{
    int agent_ID;
    VecXY_Float assigned_pos;
    bool reached;
};

struct Valid_Pos
{
    VecXY_Float position;
    bool assigned;
};

class Squad {
	public:
        Squad(int team, int ID);
        Squad();

        int squad_team;
        int squad_ID;

        int get_action_count;
        int get_support_location_count;
        bool support_flag;

        bool commandSquad;
        VecXY_Float commandPos;
        VecXY_Float observePos;

        //methods---------------------------
        void update(Graph &graph, Level &level);
        bool get_Action(vector<Action*> &actions, int agent_ID);
        void add_Agent(AI_Agent* member);
        bool active_Check();
        int get_Squad_Size();
        bool get_Support_Location(int agent_ID, VecXY_Float &loc);
        void get_Agent_Positions(vector<VecXY_Float> &positions);
        void get_Seen_Enemies(vector<VecXY_Float> &positions);
        bool idleCheck();
        bool engagedCheck();
        void listEngagedMembers();
        bool getEngagedInfo(VecXY_Float &memberPos, VecXY_Float &lookPos);
        int healthyCount();
        bool healthCheck();
        VecXY_Float getReferencePos();

        void get_Draw_Info(float &orient, VecXY_Float &desire, vector<VecXY_Float> &valid_pos);

    private:
        vector<AI_Agent*> squad_members; // Squad is not responsible for the deletion of the objects these pointers point at, Game is.
        vector<Agent_Track> tracker;
        vector<Valid_Pos> valid_positions;
        VecXY_Float desired_pos;
        float orientation;

        void assign_Positions_To_Agents();
        void calc_Valid_Squad_Positions(Level &level);
        void get_Squad_Positions(float radius, vector<VecXY_Float> &positions);
        bool validate_Squad_Position(VecXY_Float pos, float agent_radius, Level &level);
        bool validate_Agent(int ID);
        void assignCommandPosition();
};

#endif




