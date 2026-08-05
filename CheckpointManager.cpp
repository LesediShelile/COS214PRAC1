#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint* checkpoint) {
    if (checkpoint == nullptr) {
        return; // validate input
    }
    history.push_back(checkpoint);
}

RunCheckpoint* CheckpointManager::undo() {
    if (history.empty()) {
        return nullptr;
    }
    RunCheckpoint* last = history.back();
    history.pop_back(); // ownership transfers to the caller
    return last;
}

CheckpointManager::~CheckpointManager() {
    for (RunCheckpoint* checkpoint : history) {
        delete checkpoint;
    }
    history.clear();
}