#ifndef COMMANDER_H
#define COMMANDER_H

#include <vector>
#include <chrono>
#include <string>

#include "../Utils/VecXY_Float.h"
#include "../Level.h"

#include "Squad.h"
#include "Command_Influence.h"
#include "Planner/Planner.h"

struct PlanLog {
	long start;
	long end;
	int team;
	std::string plan;
};

class Commander {
	public:
        Commander(int team, int ID);
        Commander();

        int commander_team;
        int commander_ID;
        Command_Influence influence;
		Planner planner;
        vector<PlanLog> planLogs;

        void add_Squad(Squad* member);
        void calc_Influence(Level &level, vector<vector<int> > &crude_visibility, vector<VecXY_Float> &enemies);
		void update();
		Coord findClosestViewpoint(Coord vulPt, std::vector<Coord> &vulVisPts);
		WorldState getWorldState();

    private:
        vector<Squad*> member_squads; // Commander is not responsible for the deletion of the objects these pointers point at, Squad + Game are.
		void assignPositionToSquad(int squadId, VecXY_Float position, VecXY_Float lookPos);
		void assignTasks(vector<constants::PlannerTasks> plan, WorldState &worldState);
		void assignVulnerablePt(int squadId, std::string point);
		void assignIdleToEngaged(bool first, WorldState &worldState);
		void assignIdleToClosestEngaged(WorldState &worldState);
};

#endif




