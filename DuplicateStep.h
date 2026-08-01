#ifndef DEDUPLICATESTEP_H
#define DEDUPLICATESTEP_H

#include "Transformation.h"

// ConcretePrototype
class DeduplicateStep : public Transformation {
public:
    DeduplicateStep();
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

#endif