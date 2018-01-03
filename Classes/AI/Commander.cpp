#include "Commander.h"

Commander::Commander(int team, int ID):
        commander_team(team),
        commander_ID(ID)
{}

Commander::Commander():
        commander_team(-99),
        commander_ID(-99)
{}

void Commander::add_Squad(Squad* member)
{
    member_squads.push_back(member);
    //member->commander_ID = commander_ID;
}

void Commander::calc_Influence(Level &level, vector<vector<int> > &crude_visibility, vector<VecXY_Float> &enemies)
{
    // Get list of friendly positions.
    vector<VecXY_Float> friendlies;
    for(unsigned int i = 0; i < member_squads.size(); i++)
    {
        member_squads[i]->get_Agent_Positions(friendlies);
    }

    influence.calcInfluence(friendlies, enemies, level, crude_visibility);
}

void Commander::update() {
    WorldState worldState = getWorldState();
    if (worldState.idleCount() > 0) {
        PlanLog planLog;
        planLog.team = commander_team;
        planLog.start = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();

        vector<constants::PlannerTasks> plan = planner.findPlan(worldState);

        planLog.end = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();

//        std::cout << "Plan[";
//        for (int i = 0; i < plan.size(); ++i) {
//            std::cout << plan[i] << ",";
//        }
//        std::cout << "]" << std::endl;

//        std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
//        std::cout << ms.count() << std::endl;

        if (!plan.empty()) {
//            std::cout << "GOT A PLAN!!!" << std::endl;
            planLog.plan = "[";
            for (int i = 0; i < plan.size(); ++i) {
                planLog.plan += std::to_string(plan[i]);
                if(i < plan.size()-1) planLog.plan += ",";
            }
            planLog.plan += "]";
//            std::cout << commander_team << " : " << planLog.plan << std::endl;
            planLogs.push_back(planLog);

            assignTasks(plan, worldState);
        }

//        std::cout << "back from planner" << std::endl;
    }
}

Coord Commander::findClosestViewpoint(Coord vulPt, std::vector<Coord> &vulVisPts) {
    float vulPtX = (float) vulPt.getX();
    float vulPtY = (float) vulPt.getY();
    Coord closest = Coord(vulVisPts[0].getX(), vulVisPts[0].getY());
    float visX = (float) vulVisPts[0].getX();
    float visY = (float) vulVisPts[0].getY();

    float currDist = sqrt(pow((vulPtX - visX), 2.0f) + pow((vulPtY - visY), 2.0f));

    for (int i = 1; i < vulVisPts.size(); ++i) {
        visX = (float) vulVisPts[i].getX();
        visY = (float) vulVisPts[i].getY();
        float newDist = sqrt(pow((vulPtX - visX), 2.0f) + pow((vulPtY - visY), 2.0f));
        if (newDist < currDist) {
            currDist = newDist;
            closest.setX(vulVisPts[i].getX());
            closest.setY(vulVisPts[i].getY());
        }
    }

    return closest;
}

WorldState Commander::getWorldState() {
    WorldState worldState;
    for(int i = 0; i < member_squads.size(); i++) {
        // only count active squads.
        if (member_squads[i]->active_Check()) {
            worldState.vecAliveSquads.push_back(i);
            if (member_squads[i]->idleCheck()) {worldState.vecIdleCount.push_back(i);}
            if (member_squads[i]->engagedCheck()) {worldState.vecEngagedCount.push_back(i);}
            if (member_squads[i]->healthCheck()) {worldState.vecHealthyCount.push_back(i);}
        }
    }

//    worldState.vecAliveSquads.push_back(0);
//    worldState.vecAliveSquads.push_back(1);
//    worldState.vecAliveSquads.push_back(2);
//
//    worldState.vecIdleCount.push_back(0);
//    worldState.vecIdleCount.push_back(1);
//
//    worldState.vecHealthyCount.push_back(0);
//    worldState.vecHealthyCount.push_back(1);
//    worldState.vecHealthyCount.push_back(2);

    return worldState;
}

void Commander::assignPositionToSquad(int squadId, VecXY_Float position, VecXY_Float lookPos) {
    member_squads[squadId]->commandPos = position;
    member_squads[squadId]->observePos = lookPos;
}

void Commander::assignTasks(vector<constants::PlannerTasks> plan, WorldState &worldState) {
//    std::cout << std::endl << "Assigning tasks" << std::endl;
    while (!plan.empty()) {
        constants::PlannerTasks task = plan.back();
        plan.pop_back();

//        std::cout << task << std::endl;

        switch (task) {
            case constants::PT_SQ1_VA: assignVulnerablePt(0,"A"); break;
            case constants::PT_SQ2_VA: assignVulnerablePt(1,"A"); break;
            case constants::PT_SQ3_VA: assignVulnerablePt(2,"A"); break;
            case constants::PT_SQ3_VB: assignVulnerablePt(2,"B"); break;
            case constants::PT_FIRST_IDLE_ENGAGED: assignIdleToEngaged(true, worldState); break;
            case constants::PT_SECOND_IDLE_ENGAGED: assignIdleToEngaged(false, worldState); break;
            case constants::PT_FIRST_IDLE_CLOSEST_ENGAGED: assignIdleToClosestEngaged(worldState); break;
            case constants::PT_FIRST_IDLE_VA: assignVulnerablePt(worldState.vecIdleCount[0],"A"); break;
            case constants::PT_SECOND_IDLE_VA: assignVulnerablePt(worldState.vecIdleCount[1],"A"); break;
            default: break;
        }
    }
}

void Commander::assignVulnerablePt(int squadId, std::string point) {
    Coord closestVis;
    float vulX = 0.0, vulY = 0.0;
    float posX = 0.0, posY = 0.0;

    if (point == "A") {
        closestVis = findClosestViewpoint(influence.vulnerableA, influence.vulAVisPts);
        vulX = (influence.vulnerableA.getX() * 40) +20;
        vulY = (influence.vulnerableA.getY() * 40) +20;
    } else {
        closestVis = findClosestViewpoint(influence.vulnerableB, influence.vulBVisPts);
        vulX = (influence.vulnerableB.getX() * 40) +20;
        vulY = (influence.vulnerableB.getY() * 40) +20;
    }

    posX = (closestVis.getX() * 40) +20;
    posY = (closestVis.getY() * 40) +20;

    assignPositionToSquad(squadId, VecXY_Float(posX, posY), VecXY_Float(vulX, vulY));
}

void Commander::assignIdleToEngaged(bool first, WorldState &worldState) {
    int squadId = 0;
    if (first) {squadId = worldState.vecIdleCount[0];}
    else {squadId = worldState.vecIdleCount[1];}

    int engagedSquadId = worldState.vecEngagedCount[0];
    VecXY_Float memberPos, lookPos;
    member_squads[engagedSquadId]->getEngagedInfo(memberPos, lookPos);

    assignPositionToSquad(squadId, VecXY_Float(memberPos.getX(), memberPos.getY()), VecXY_Float(lookPos.getX(), lookPos.getY()));
}

void Commander::assignIdleToClosestEngaged(WorldState &worldState) {
    int squadId = worldState.vecIdleCount[0];
    VecXY_Float refPos = member_squads[squadId]->getReferencePos();

    int engagedSquadOne = worldState.vecEngagedCount[0];
    int engagedSquadTwo = worldState.vecEngagedCount[1];
    VecXY_Float memberPos1, lookPos1, memberPos2, lookPos2;
    member_squads[engagedSquadOne]->getEngagedInfo(memberPos1, lookPos1);
    member_squads[engagedSquadTwo]->getEngagedInfo(memberPos2, lookPos2);

    float dist1 = sqrt(pow((refPos.getX() - memberPos1.getX()), 2.0f) + pow((refPos.getY() - memberPos1.getY()), 2.0f));
    float dist2 = sqrt(pow((refPos.getX() - memberPos2.getX()), 2.0f) + pow((refPos.getY() - memberPos2.getY()), 2.0f));

    if (dist1 <= dist2) {
        assignPositionToSquad(squadId, VecXY_Float(memberPos1.getX(), memberPos1.getY()), VecXY_Float(lookPos1.getX(), lookPos1.getY()));
    }
    else {
        assignPositionToSquad(squadId, VecXY_Float(memberPos2.getX(), memberPos2.getY()), VecXY_Float(lookPos2.getX(), lookPos2.getY()));
    }
}
