#include <iostream>
#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "Pipeline.h"
#include "PostgresFactory.h"
#include "CheckpointManager.h"

int main() {

    // (1) Create a TransformationRegistry and register prototypes under their keys.
    //     The registry takes ownership of the prototypes it is given and will
    //     delete them in its own destructor.
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep());
    registry->registerStep("aggregate", new AggregateByRegionStep());

    // (2) Create a BatchPipeline with a PostgresFactory.
    //     Pipeline's destructor deletes the factory it was given, so ownership
    //     of the PostgresFactory transfers to the pipeline here.
    Pipeline* pipeline = new BatchPipeline(new PostgresFactory());

    // (3) Add cloned steps from the registry -- never construct steps directly.
    //     Pipeline::~Pipeline() deletes every step in its `steps` vector, so the
    //     clones become the pipeline's responsibility from this point on.
    pipeline->addStep(registry->create("dedup"));
    pipeline->addStep(registry->create("aggregate"));

    // (4) Create a CheckpointManager.
    CheckpointManager* checkpointManager = new CheckpointManager();

    // (5) Run the pipeline, then checkpoint and save the result.
    pipeline->run();
    RunCheckpoint* checkpoint = pipeline->createCheckpoint();
    checkpointManager->save(checkpoint);

    // (6) Clean up everything main still owns.
    //     - `checkpoint` was created by the pipeline but not stored/owned by
    //       anything else after save(), so main deletes it here. If your
    //       CheckpointManager::save() takes ownership of the pointer instead,
    //       remove this line to avoid a double free.
    //     - `checkpointManager` was created directly by main.
    //     - `pipeline` deletes its own factory and steps internally.
    //     - `registry` deletes any prototypes still left registered.
    delete checkpoint;
    delete checkpointManager;
    delete pipeline;
    delete registry;

    return 0;
}