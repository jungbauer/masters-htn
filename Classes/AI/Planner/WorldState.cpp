#include "WorldState.h"

WorldState::WorldState() {}

int WorldState::aliveSquads() {
    if (vecAliveSquads.empty()) {
        return 0;
    } else {
        return (int) vecAliveSquads.size();
    }
}

int WorldState::idleCount() {
    if (vecIdleCount.empty()) {
        return 0;
    } else {
        return (int) vecIdleCount.size();
    }
}

int WorldState::healthyCount() {
    if (vecHealthyCount.empty()) {
        return 0;
    } else {
        return (int) vecHealthyCount.size();
    }
}

int WorldState::engagedCount() {
    if (vecEngagedCount.empty()) {
        return 0;
    } else {
        return (int) vecEngagedCount.size();
    }
}