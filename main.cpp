#include <iostream>

#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "ConnectorFactory.h"
#include "PostgresFactory.h"
#include "Pipeline.h"
#include "BatchPipeline.h"
#include "CheckpointManager.h"
#include "RunCheckpoint.h"

int main() {
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep());
    registry->registerStep("aggregate", new AggregateByRegionStep());

    Pipeline* pipeline = new BatchPipeline(new PostgresFactory());

    pipeline->addStep(registry->create("dedup"));
    pipeline->addStep(registry->create("aggregate"));

    CheckpointManager* checkpointManager = new CheckpointManager();

    pipeline->run();
    RunCheckpoint* checkpoint = pipeline->createCheckpoint();
    checkpointManager->save(checkpoint);

    RunCheckpoint* resumed = checkpointManager->undo();
if (resumed) {
    pipeline->restore(resumed);
    delete resumed;
}

    
    delete checkpointManager;
    delete pipeline;
    delete registry;

    return 0;
}