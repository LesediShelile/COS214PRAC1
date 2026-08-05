#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
#include <vector>
#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

// AbstractClass (Template Method) / Originator (Memento)
class Pipeline {
protected:
    ConnectorFactory* factory;
    std::vector<Transformation*> steps;
    int stage;
    std::vector<std::string> records;

public:
    Pipeline(ConnectorFactory* factory);

    // Template method: fixes the algorithm's skeleton. Deliberately
    // NOT virtual - subclasses may not change the order of stages.
    void run();

    void addStep(Transformation* step);

protected:
    // Concrete step: same for every pipeline.
    void connect();

    // Primitive operation: each concrete pipeline decides how to extract.
    virtual void extract() = 0;

    // Concrete step: same for every pipeline.
    void transform();

    // Primitive operation: each concrete pipeline decides how to load.
    virtual void load() = 0;

public:
    // Memento hooks (Originator role).
    RunCheckpoint* createCheckpoint();
    void restore(RunCheckpoint* checkpoint);

    virtual ~Pipeline();
};

#endif