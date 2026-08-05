#include <iostream>
#include <string>
#include "Pipeline.h"

Pipeline::Pipeline(ConnectorFactory* factory) {
    this->factory = factory;
    this->stage = 0;
    // records starts empty - nothing to do
}

void Pipeline::run() {
    this->connect();
    this->extract();
    this->transform();
    this->load();
}

void Pipeline::addStep(Transformation* step) {
    steps.push_back(step);
}

//pipeline as the originator class for checkpoints 

RunCheckpoint* Pipeline::createCheckpoint() { // create new runcheckpoint object which is functioning as the memento 
    return new RunCheckpoint(stage, records); // returns a runcheckpoint p
}

void Pipeline::restore(RunCheckpoint* checkpoint) {
    if (checkpoint == nullptr) {
        return; // validate input
    }
    this->stage = checkpoint->getStage();
    this->records = checkpoint->getRecords();
}

Pipeline::~Pipeline() {
    for (Transformation* ptr : steps) {
        delete ptr;
    }
    steps.clear();

    delete factory;
    factory = nullptr;
}

void Pipeline::connect() {
    Connector* connector = factory->createConnector();
    std::cout << "Connecting to " << connector->getSource() << std::endl;
    this->stage = 1;
    delete connector;
}

void Pipeline::transform() {
    for (auto& item : steps) {
        records = item->apply(records);
    }
    this->stage = 3;
}

