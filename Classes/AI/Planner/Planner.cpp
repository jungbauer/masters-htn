#include "Planner.h"

vector<constants::PlannerTasks> Planner::findPlan(WorldState currentWS) {
//    std::cout << std::endl << "-----------------------------" << std::endl;
    WorldState workingWS = currentWS;
//    std::cout << "WS(alive: " << workingWS.aliveSquads();
//    std::cout << ", idle: " << workingWS.idleCount();
//    std::cout << ", healthy: " << workingWS.healthyCount();
//    std::cout << ", engaged: " << workingWS.engagedCount() << ")" << std::endl;
    vector<Task*> tasksToProcess;
    tasksToProcess.push_back(new Task_BeCommander());

    vector<constants::PlannerTasks> finalPlan;
    vector<HistoryItem> decompHistory;
    HistoryItem initialHistory;
    initialHistory.decompMethod = -1;
    initialHistory.owningTask = nullptr;
    decompHistory.push_back(initialHistory);
    int methodRestriction = -1;

//    std::cout << "initial: " << initialHistory.tasksToProcess.empty() << std::endl;

    while (!tasksToProcess.empty()) {
//        std::cout << "==========================" << std::endl;
        Task *currentTask = tasksToProcess.back();
        tasksToProcess.pop_back();

        if (currentTask->taskType == constants::PT_TYPE_COMPOUND) {
//            std::cout << "compound Task: " << currentTask->taskName << std::endl;
            CompoundTask *pCompound = (CompoundTask *) currentTask;
            vector<Method *>::iterator iter = pCompound->methods.begin();

            // Shift iterator based on method restriction
            for (int i = 0; i < methodRestriction+1; ++i) {
                iter++;
            }

            // Find the condition satisfying method -------------------------------
            Method *pSatifiedMethod = nullptr;
            while (iter != pCompound->methods.end() && pSatifiedMethod == nullptr) {
//                std::cout << "method: " << (*iter)->methodId;
                if ((*iter)->checkConditions(workingWS)) {
//                    std::cout << " conditions passed" << std::endl;
                    pSatifiedMethod = (*iter);
                } else {
//                    std::cout << " conditions FAILED" << std::endl;
                }

                iter++;
            }

            // Do something with the method -----------------------------------------------
            if (pSatifiedMethod != nullptr) {
                // Record history
                HistoryItem historyItem;
                historyItem.owningTask = currentTask;
                historyItem.decompMethod = pSatifiedMethod->methodId;
                historyItem.finalPlan = finalPlan;
                historyItem.tasksToProcess = tasksToProcess;
                decompHistory.push_back(historyItem);

                // reset method restriction
                methodRestriction = -1;

//                std::cout << "satisfied method: " << pSatifiedMethod->methodId << std::endl;
//                std::cout << "subtasks: " << pSatifiedMethod->subTasks.size() << std::endl;
                vector<Task *>::iterator subTaskIter = pSatifiedMethod->subTasks.begin();

                while (subTaskIter != pSatifiedMethod->subTasks.end()) {
                    tasksToProcess.push_back((*subTaskIter));
                    subTaskIter++;
                }

            } else {
//                std::cout << "restore" << std::endl;
                HistoryItem item = decompHistory.back();
                decompHistory.pop_back();

//                std::cout << "++++++++++" << std::endl;
//                std::cout << item.decompMethod << std::endl;
//                if (item.owningTask == nullptr){std::cout << "null" << std::endl;}
//                else {std::cout << item.owningTask->taskName << std::endl;}
//
//                std::cout << item.finalPlan.size() << std::endl;
//                std::cout << item.tasksToProcess.size() << std::endl;

                methodRestriction = item.decompMethod;
                finalPlan = item.finalPlan;
                tasksToProcess = item.tasksToProcess;
                if (item.owningTask != nullptr) {tasksToProcess.push_back(item.owningTask);}
            }
        }
        else {
//            std::cout << "primitive task" << std::endl;
            finalPlan.push_back(currentTask->taskName);
        }

//        std::cout << "ttp: " << tasksToProcess.size() << std::endl;
    }

//    std::cout << std::endl << "history: " << decompHistory.size() << std::endl;
//    for (int i = 0; i < decompHistory.size(); ++i) {
//        std::cout << "-------" << std::endl;
//        std::cout << decompHistory[i].decompMethod << std::endl;
//        if (decompHistory[i].owningTask == nullptr){std::cout << "null" << std::endl;}
//        else {std::cout << decompHistory[i].owningTask->taskName << std::endl;}
//
//        std::cout << decompHistory[i].finalPlan.size() << std::endl;
//        std::cout << decompHistory[i].tasksToProcess.size() << std::endl;
//
//    }

    return finalPlan;
}
