#ifndef PT_WORLDSTATE_H
#define PT_WORLDSTATE_H

#include <vector>

class WorldState {
    public:
        WorldState();

        int aliveSquads();
        int idleCount();
        int healthyCount();
        int engagedCount();

        std::vector<int> vecAliveSquads;
        std::vector<int> vecIdleCount;
        std::vector<int> vecHealthyCount;
        std::vector<int> vecEngagedCount;

};

#endif
