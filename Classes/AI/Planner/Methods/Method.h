#ifndef PM_METHOD_H
#define PM_METHOD_H

#include <vector>
#include "../Tasks/Task.h"
#include "../WorldState.h"

using namespace std;

//class Task;

class Method {
    public:
        Method();
        virtual bool checkConditions(WorldState worldState){return false;};

        vector<Task*> subTasks;
        int methodId;

};


#endif
