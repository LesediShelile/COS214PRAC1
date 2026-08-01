#include <iostream>
#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "Pipeline.h"
#include "PostgresFactory.h"
#include "CheckpointManager.h"

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

   
    delete checkpoint;
    delete checkpointManager;
    delete pipeline;
    delete registry;

    return 0;
}