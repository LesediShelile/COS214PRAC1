#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>
#include "RunCheckpoint.h"

// Caretaker (Memento)
// Stores checkpoints without inspecting their contents (the "wide"
// interface used to construct/inspect a RunCheckpoint stays private
// to Pipeline; the Caretaker only ever passes RunCheckpoint* around).
class CheckpointManager {
private:
    std::vector<RunCheckpoint*> history;

public:
    // Takes ownership of checkpoint.
    void save(RunCheckpoint* checkpoint);

    // Removes and returns the most recently saved checkpoint,
    // transferring ownership to the caller. Returns nullptr if
    // no checkpoints remain.
    RunCheckpoint* undo();

    // Deletes every checkpoint still held (i.e. never undo()'d).
    ~CheckpointManager();
};

#endif