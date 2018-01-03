#ifndef ACTION_HANDLER_H
#define ACTION_HANDLER_H

#include <iostream>
#include <vector>

#include "AI_Agent.h"
#include "Actions/Action.h"
#include "Actions/Act_Take_Item.h"
#include "Actions/Act_Place_Item.h"
#include "Squad.h"

#include "../Utils/Constants.h"
#include "../Utils/Utils.h"
#include "../Utils/log.h"
#include "../Pathfinding/Path.h"
#include "../Pathfinding/PathFinding.h"
#include "../Pathfinding/Graph.h"
#include "../Level.h"
#include "../Bullet.h"

#include "../Locations/Location.h"


using namespace std;

class Action_Handler
{
    public:
        Action_Handler();
        void doAction(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level, unsigned int deltaTicks, vector<Bullet> &bullets, vector<Location*> &locations, vector<Squad> &squads);

    private:
        void actNone();
        void actFollowPath(AI_Agent &agent, Level &level, unsigned int deltaTicks);
        void actFollowPathOrient(AI_Agent &agent, Level &level, unsigned int deltaTicks);
        void actRandomPathfind(AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level);
        void actPathfind(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level);
        void actSupportPathfind(Action *action, AI_Agent &agent, PathFinding &pathFinder, Graph &graph, Level &level);
        void actChooseTarget(AI_Agent &agent);
        void actOrient(AI_Agent &agent, unsigned int deltaTicks);
        void actFire(AI_Agent &agent, vector<Bullet> &bullets);
        void actTakeItem(Action *action, AI_Agent &agent, vector<Location*> &locations);
        void actPlaceItem(Action *action, AI_Agent &agent, vector<Location*> &locations);
        void actQuerySquad(AI_Agent &agent, vector<Squad> &squads);
        void actResetEngaged(AI_Agent &agent);
        void actSetEngaged(AI_Agent &agent);
        void actScan(AI_Agent &agent, unsigned int deltaTicks);
        void actSetupSearch(AI_Agent &agent);
        void actSpotSearch(AI_Agent &agent, unsigned int deltaTicks);
        void actChooseTargetV2(AI_Agent &agent);
        void actTargetFlagged(AI_Agent &agent);
        void actSetSupportLocation(AI_Agent &agent, vector<Squad> &squads, PathFinding &pathFinder, Graph &graph, Level &level);
};

#endif

