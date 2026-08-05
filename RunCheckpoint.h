#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H

#include <string>
#include <vector>

// Memento
class RunCheckpoint {
    
    friend class Pipeline;

private:
    int stage;
    std::vector<std::string> records;

    RunCheckpoint(int stage, std::vector<std::string> records);
    int getStage() const;
    std::vector<std::string> getRecords() const;
};

#endif