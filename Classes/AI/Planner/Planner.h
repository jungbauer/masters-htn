#ifndef PLANNER_H
#define PLANNER_H

#include <iostream>
#include <vector>
#include "WorldState.h"
#include "Tasks/Task.h"
#include "Tasks/Task_BeCommander.h"

using namespace std;

struct HistoryItem {
    vector<constants::PlannerTasks> finalPlan;
    vector<Task*> tasksToProcess;
    int decompMethod;
    Task *owningTask;
};

class Planner {

    public:
        vector<constants::PlannerTasks> findPlan(WorldState currentWS);

};


#endif
