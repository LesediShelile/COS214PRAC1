#ifndef AGGREGATEBYREGIONSTEP_H
#define AGGREGATEBYREGIONSTEP_H

#include "Transformation.h"

// ConcretePrototype
class AggregateByRegionStep : public Transformation {
public:
    AggregateByRegionStep();
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

#endif